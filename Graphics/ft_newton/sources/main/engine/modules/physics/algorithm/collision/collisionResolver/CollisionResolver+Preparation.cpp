#include "CollisionResolver.h"

#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/physics/algorithm/collision/Collision.h"
#include "engine/modules/physics/components/collider/Collider.h"
#include "engine/modules/physics/components/rigidBody/RigidBody.h"

using namespace engine::physics;

CollisionResolver::ContactWorkspace CollisionResolver::generateContactWorkspace(array<RigidBody *, 2> &bodies, const Contact &contact, float deltaTime)
{
	ContactWorkspace workspace;

	workspace.position = contact.position;
	workspace.normal = contact.normal;
	workspace.penetrationDepth = contact.penetrationDepth;

	workspace.contactToWorld = calculateContactBasis(contact);
	workspace.worldToContact = transpose(workspace.contactToWorld);

	workspace.relativePositions[0] = contact.position - bodies[0]->_transformationFinder().getGlobalPosition();
	workspace.relativePositions[1] = contact.position - bodies[1]->_transformationFinder().getGlobalPosition();

	workspace.contactVelocity = calculateRelativeVelocity(workspace, 0, bodies[0]) -
								calculateRelativeVelocity(workspace, 1, bodies[1]);

	workspace.desiredDeltaVelocity = calculateDesiredDeltaVelocity(workspace);

	return workspace;
}

engine::mat4 CollisionResolver::calculateContactBasis(const Contact &contact)
{
	vec3 contactTangent[2];

	// Check whether the Z axis is nearer to the X or Y axis.
	if (abs(contact.normal.x) > abs(contact.normal.y))
	{
		// Scaling factor to ensure the results are normalized.
		const float s = 1.0f / sqrt(contact.normal.z * contact.normal.z + contact.normal.x * contact.normal.x);

		// The new X axis is at right angles to the world Y axis.
		contactTangent[0].x = contact.normal.z * s;
		contactTangent[0].y = 0;
		contactTangent[0].z = -contact.normal.x * s;

		// The new Y axis is at right angles to the new X and Z axes.
		contactTangent[1].x = contact.normal.y * contactTangent[0].x;
		contactTangent[1].y = contact.normal.z * contactTangent[0].x - contact.normal.x * contactTangent[0].z;
		contactTangent[1].z = -contact.normal.y * contactTangent[0].x;
	}
	else
	{
		// Scaling factor to ensure the results are normalized.
		const float s = 1.0f / sqrt(contact.normal.z * contact.normal.z + contact.normal.y * contact.normal.y);

		// The new X axis is at right angles to the world X axis.
		contactTangent[0].x = 0;
		contactTangent[0].y = -contact.normal.z * s;
		contactTangent[0].z = contact.normal.y * s;

		// The new Y axis is at right angles to the new X and Z axes.
		contactTangent[1].x = contact.normal.y * contactTangent[0].z - contact.normal.z * contactTangent[0].y;
		contactTangent[1].y = -contact.normal.x * contactTangent[0].z;
		contactTangent[1].z = contact.normal.x * contactTangent[0].y;
	}

	return makeMatrixFromBasis(contact.normal, contactTangent[0], contactTangent[1]);
}

engine::vec3 CollisionResolver::calculateRelativeVelocity(const ContactWorkspace &workspace, unsigned rigidBodyIndex, RigidBody *rigidBody)
{
	// Work out the velocity of the contact point.
	const auto velocity = cross(rigidBody->_angularVelocity, workspace.relativePositions[rigidBodyIndex]) + rigidBody->_linearVelocity;

	// Turn the velocity into contact coordinates
	const auto contactVelocity = transformDirection(velocity, workspace.worldToContact);

	return contactVelocity;
}

float CollisionResolver::calculateDesiredDeltaVelocity(const ContactWorkspace &meta)
{

}