#include "CollisionResolver.h"

#include "engine/tools/external/std/mathematics.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/physics/algorithm/collision/Contact.h"
#include "engine/modules/physics/components/rigidBody/RigidBody.h"

using namespace engine::physics;

void CollisionResolver::resolveInterpenetration(vector<ContactWorkspace> &contacts, array<RigidBody *, 2> &bodies)
{
	// Iteratively resolve interpenetration in order of severity.
	for (auto iteration = 0; iteration < 10; iteration++) // TODO MOVE TO SETTINGS
	{
		// Find the biggest penetration.
		auto maxPenetrationDepth = numeric_limits<float>::min();
		auto *contactWithBiggestPenetration = static_cast<ContactWorkspace *>(nullptr);

		for (auto &contact: contacts)
		{
			if (contact.penetrationDepth > maxPenetrationDepth)
			{
				maxPenetrationDepth = contact.penetrationDepth;
				contactWithBiggestPenetration = &contact;
			}
		}

		if (contactWithBiggestPenetration == nullptr)
			break;

		// Resolve the penetration.
		array<vec3, 2> linearChange;
		array<vec3, 2> angularChange;
		processInterpenetration(*contactWithBiggestPenetration, bodies, linearChange, angularChange);

		// Again this action may have changed the penetration of other
		// bodies, so we update contacts.
		for (auto &contact: contacts)
		{
			auto deltaPosition = linearChange[0] + cross(angularChange[0], contact.relativePositions[0]);
			contact.penetrationDepth -= dot(deltaPosition, contact.normal);

			deltaPosition = linearChange[1] + cross(angularChange[1], contact.relativePositions[1]);
			contact.penetrationDepth += dot(deltaPosition, contact.normal);
		}
	}
}

void CollisionResolver::processInterpenetration(
	ContactWorkspace &contact,
	array<RigidBody *, 2> &bodies,
	array<vec3, 2> &linearChange,
	array<vec3, 2> &angularChange)
{
	const auto angularLimit = 0.2f; // TODO SETTINGS

	float angularMove[2];
	float linearMove[2];

	float totalInertia = 0;
	float linearInertia[2];
	float angularInertia[2];

	// We need to work out the inertia of each object in the direction
	// of the contact normal, due to angular inertia only.
	for (auto i = 0; i < 2; i++)
	{
		// Use the same procedure as for calculating frictionless
		// velocity change to work out the angular inertia.
		auto angularInertiaWorld = cross(contact.relativePositions[i], contact.normal);
		angularInertiaWorld = transformDirection(angularInertiaWorld, bodies[i]->_inverseInertiaTensor);
		angularInertiaWorld = cross(angularInertiaWorld, contact.relativePositions[i]);
		angularInertia[i] = dot(angularInertiaWorld, contact.normal);

		// The linear component is simply the inverse mass
		linearInertia[i] = bodies[i]->_inverseMass;

		// Keep track of the total inertia from all components
		totalInertia += linearInertia[i] + angularInertia[i];

		// We break the loop here so that the totalInertia value is
		// completely calculated (by both iterations) before
		// continuing.
	}

	// Loop through again calculating and applying the changes
	for (auto i = 0; i < 2; i++)
	{
		// The linear and angular movements required are in proportion to
		// the two inverse inertias.
		const auto sign = i == 0 ? 1.f : -1.f;

		angularMove[i] = sign * contact.penetrationDepth * (angularInertia[i] / totalInertia);
		linearMove[i] = sign * contact.penetrationDepth * (linearInertia[i] / totalInertia);

		// To avoid angular projections that are too great (when mass is large
		// but inertia tensor is small) limit the angular move.
		const auto projection = contact.relativePositions[i] + contact.normal * -dot(contact.relativePositions[i], contact.normal);

		// Use the small angle approximation for the sine of the angle (i.e.
		// the magnitude would be sine(angularLimit) * projection.magnitude,
		// but we approximate sine(angularLimit) to angularLimit).
		const auto maxMagnitude = angularLimit * length(projection);

		if (angularMove[i] < -maxMagnitude)
		{
			auto totalMove = angularMove[i] + linearMove[i];
			angularMove[i] = -maxMagnitude;
			linearMove[i] = totalMove - angularMove[i];
		}
		else if (angularMove[i] > maxMagnitude)
		{
			auto totalMove = angularMove[i] + linearMove[i];
			angularMove[i] = maxMagnitude;
			linearMove[i] = totalMove - angularMove[i];
		}

		// We have the linear amount of movement required by turning
		// the rigid bodies (in angularMove[i]). We now need to
		// calculate the desired rotation to achieve that.
		if (angularMove[i] == 0)
		{
			// Easy case - no angular movement means no rotation.
			angularChange[i] = vec3(0);
		}
		else
		{
			// Work out the direction we'd like to rotate in.
			auto targetAngularDirection = cross(contact.relativePositions[i], contact.normal);

			// Work out the direction we'd need to rotate to achieve that
			angularChange[i] = transformDirection(targetAngularDirection, bodies[i]->_inverseInertiaTensor) *
							   (angularMove[i] / angularInertia[i]);
		}

		// Velocity change is easier - it is just the linear movement
		// along the contact normal.
		linearChange[i] = contact.normal * linearMove[i];

		// Now we can start to apply the values we've calculated.
		// Apply the linear movement
		bodies[i]->_transformationFinder().moveBy(contact.normal * linearMove[i]);

		// And the change in orientation
		bodies[i]->_transformationFinder().rotateAround(normalize(angularChange[i]), length(angularChange[i]));

		// We need to calculate the derived data for any bodies that is
		// asleep, so that the changes are reflected in the object's
		// data. Otherwise the resolution will not change the position
		// of the object, and the next collision detection round will
		// have the same penetration.
//		if (!bodies[i]->getAwake()) bodies[i]->calculateDerivedData();
	}
}