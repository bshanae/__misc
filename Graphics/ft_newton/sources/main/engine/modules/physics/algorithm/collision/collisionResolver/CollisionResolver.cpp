#include "CollisionResolver.h"

#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/physics/algorithm/collision/Collision.h"
#include "engine/modules/physics/components/collider/Collider.h"
#include "engine/modules/physics/components/rigidBody/RigidBody.h"

using namespace engine::physics;

constexpr bool logPosition = true;
constexpr bool logDeltaVelocity = true;
constexpr bool logClosingVelocity = true;
constexpr bool logDesiredVelocity = true;
constexpr bool logImpulse = true;

void CollisionResolver::resolveCollision(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Collision &collision, float deltaTime)
{
	if (collision.getContacts().size() == 0)
	{
		// TODO
		Debug::logError("CollisionResolver", "Collision has no contacts!");
		return;
	}

	auto bodies = array<RigidBody *, 2>{ &rigidBodyA, &rigidBodyB };
	auto contacts = vector<ContactWorkspace>();

	for (const auto &contact : collision.getContacts())
		contacts.push_back(generateContactWorkspace(bodies, contact, deltaTime));

//	resolveInterpenetration(contacts, bodies);

//	resolveVelocity(rigidBodyA, rigidBodyB, collision, deltaTime);
	resolveInterpenetration(rigidBodyA, rigidBodyB, collision);
}

void CollisionResolver::resolveVelocity(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Collision &collision, float deltaTime)
{
	for (const auto &contact : collision.getContacts())
		resolveCollisionAtContact(rigidBodyA, rigidBodyB, contact);

	cout << endl;
}

void CollisionResolver::resolveInterpenetration(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Collision &collision)
{
	for (const auto &contact : collision.getContacts())
		resolveInterpenetrationAtContact(rigidBodyA, rigidBodyB, contact);
}

void CollisionResolver::resolveCollisionAtContact(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Contact &contact)
{
	if (logPosition)
		cout << "Position: " << to_string(contact.position) << endl;

	// COORDINATE SYSTEM PREPARATION
	// ////////////////////////////////////////

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

	const auto contactToWorld = makeMatrixFromBasis(contact.normal, contactTangent[0], contactTangent[1]);
	const auto worldToContact = transpose(contactToWorld);

	// DELTA VELOCITY COMPUTATION
	// ////////////////////////////////////////

	const auto contactPositionInLCSOfA = contact.position - rigidBodyA._transformationFinder().getGlobalPosition();
	const auto contactPositionInLCSOfB = contact.position - rigidBodyB._transformationFinder().getGlobalPosition();

	// Work out the change in velocity in contact coordinates.
	auto deltaVelocity = 0.f;

	if (isNotInfinity(rigidBodyA._mass))
	{
		// Build a vector that shows the change in velocity in world space for a unit impulse in the direction of the contact normal.
		auto deltaVelocityInWCS = cross(contactPositionInLCSOfA, contact.normal);
		deltaVelocityInWCS = transformDirection(deltaVelocityInWCS, rigidBodyA._inverseInertiaTensor);
		deltaVelocityInWCS = cross(deltaVelocityInWCS, contactPositionInLCSOfA);

		// Add the change in velocity due to rotation.
		deltaVelocity += dot(deltaVelocityInWCS, contact.normal);
		// Add the linear component of velocity change.
		deltaVelocity += rigidBodyA._inverseMass;
	}

	if (isNotInfinity(rigidBodyB._mass))
	{
		// Go through the same transformation sequence again.
		auto deltaVelocityInWCS = cross(contactPositionInLCSOfB, contact.normal);
		deltaVelocityInWCS = transformDirection(deltaVelocityInWCS, rigidBodyB._inverseInertiaTensor);
		deltaVelocityInWCS = cross(deltaVelocityInWCS, contactPositionInLCSOfB);

		// Add the change in velocity due to rotation.
		deltaVelocity += dot(deltaVelocityInWCS, contact.normal);
		// Add the linear component of velocity change.
		deltaVelocity += rigidBodyB._inverseMass;
	}

	if (logDeltaVelocity)
		cout << "Delta velocity: " << deltaVelocity << endl;

	// CLOSING VELOCITY COMPUTATION
	// ////////////////////////////////////////

	auto closingVelocityInWCS = cross(rigidBodyA._angularVelocity, contactPositionInLCSOfA) + rigidBodyA._linearVelocity;
	closingVelocityInWCS += cross(rigidBodyB._angularVelocity, contactPositionInLCSOfB) + rigidBodyB._linearVelocity;

	auto closingVelocityInLCS = transformDirection(closingVelocityInWCS, worldToContact);

	if (logClosingVelocity)
		cout << "Closing velocity: " << to_string(closingVelocityInWCS) << endl;

	// DESIRED VELOCITY COMPUTATION
	// ////////////////////////////////////////

	const auto desiredVelocity = -closingVelocityInLCS.x * (1 + min(rigidBodyA._coefficientOfRestitution, rigidBodyB._coefficientOfRestitution));

	if (logDeltaVelocity)
		cout << "Desired velocity: " << to_string(closingVelocityInWCS) << endl;

	// IMPULSE COMPUTATION
	// ////////////////////////////////////////

	const auto impulseInLCS = vec3(desiredVelocity / deltaVelocity, 0, 0);
	const auto impulseInWCS = transformDirection(impulseInLCS, contactToWorld);

	if (logImpulse)
		cout << "Impulse: " << to_string(impulseInWCS) << endl;

	// IMPULSE APPLICATION
	// ////////////////////////////////////////

	rigidBodyA._linearVelocity += impulseInWCS * rigidBodyA._inverseMass;
	rigidBodyA._angularVelocity += transformPoint(cross(contactPositionInLCSOfA, impulseInWCS), rigidBodyA._inverseInertiaTensor);

	rigidBodyB._linearVelocity += -impulseInWCS * rigidBodyB._inverseMass;
	rigidBodyB._angularVelocity += transformPoint(cross(contactPositionInLCSOfB, -impulseInWCS), rigidBodyB._inverseInertiaTensor);
}

void CollisionResolver::resolveInterpenetrationAtContact(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Contact &contact)
{
	const auto contactPositionInLCSOfA = contact.position - rigidBodyA._transformationFinder().getGlobalPosition();
	const auto contactPositionInLCSOfB = contact.position - rigidBodyB._transformationFinder().getGlobalPosition();

	// INERTIA COMPUTATION
	// ////////////////////////////////////////

	auto angularInertiaAInWCS = cross(contactPositionInLCSOfA, contact.normal);
	angularInertiaAInWCS = transformDirection(angularInertiaAInWCS, rigidBodyA._inverseInertiaTensor);
	angularInertiaAInWCS = cross(angularInertiaAInWCS, contactPositionInLCSOfA);

	auto angularInertiaA = dot(angularInertiaAInWCS, contact.normal);
	auto linearInertiaA = rigidBodyA._inverseMass;

	auto totalInertia = linearInertiaA + angularInertiaA;

	auto angularInertiaBInWCS = cross(contactPositionInLCSOfB, contact.normal);
	angularInertiaBInWCS = transformDirection(angularInertiaBInWCS, rigidBodyB._inverseInertiaTensor);
	angularInertiaBInWCS = cross(angularInertiaBInWCS, contactPositionInLCSOfB);

	auto angularInertiaB = dot(angularInertiaBInWCS, contact.normal);
	auto linearInertiaB = rigidBodyB._inverseMass;

	totalInertia += linearInertiaB + angularInertiaB;

	// MOVEMENT PROPORTIONS COMPUTATION
	// ////////////////////////////////////////

	auto inverseInertia = 1.f / totalInertia;

	auto linearMoveA = contact.penetrationDepth * linearInertiaA * inverseInertia;
	auto angularMoveA = contact.penetrationDepth * angularInertiaA * inverseInertia;

	auto linearMoveB = -contact.penetrationDepth * linearInertiaB * inverseInertia;
	auto angularMoveB = -contact.penetrationDepth * angularInertiaB * inverseInertia;

	// PROPORTIONS BALANCING
	// ////////////////////////////////////////

	auto limit = 0.2f * length(contactPositionInLCSOfA);
	if (abs(angularMoveA) > limit)
	{
		const auto totalMove = linearMoveA + angularMoveA;

		angularMoveA = clamp(angularMoveA, -limit, limit);
		linearMoveA = totalMove - angularMoveA;
	}

	limit = 0.2f * length(contactPositionInLCSOfB);
	if (abs(angularMoveB) > limit)
	{
		const auto totalMove = linearMoveB + angularMoveA;

		angularMoveA = clamp(angularMoveB, -limit, limit);
		linearMoveB = totalMove - angularMoveB;
	}

	// MOVEMENT PERFORMANCE
	// ////////////////////////////////////////

	if (linearInertiaA != 0.f)
		rigidBodyA._transformationFinder().moveBy(contact.normal * linearMoveA);

	if (linearInertiaB != 0.f)
		rigidBodyB._transformationFinder().moveBy(contact.normal * linearMoveB);

	if (angularInertiaA != 0.f)
	{
		const auto impulsePerMoveA = transformDirection(cross(contactPositionInLCSOfA, contact.normal), rigidBodyA._inverseInertiaTensor);
		const auto rotationPerMoveA = impulsePerMoveA / angularInertiaA;
		const auto rotationA = rotationPerMoveA * angularMoveA;
		rigidBodyA._transformationFinder().rotateAround(normalize(rotationA), length(rotationA));
	}

	if (angularInertiaB != 0.f)
	{
		const auto impulsePerMoveB = transformDirection(cross(contactPositionInLCSOfB, contact.normal), rigidBodyB._inverseInertiaTensor);
		const auto rotationPerMoveB = impulsePerMoveB / angularInertiaB;
		const auto rotationB = rotationPerMoveB * angularMoveB;
		rigidBodyB._transformationFinder().rotateAround(normalize(rotationB), length(rotationB));
	}
}