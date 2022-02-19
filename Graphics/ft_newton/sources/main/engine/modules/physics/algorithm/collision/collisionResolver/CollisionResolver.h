#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/glm/glm.h"
#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/std/array.h"

class engine::physics::CollisionResolver
{
public :

	CollisionResolver() = delete;
	~CollisionResolver() = delete;

	static void resolveCollision(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Collision &collision, float deltaTime);

private :

	struct ContactWorkspace
	{
		vec3 position;
		vec3 normal;
		float penetrationDepth;

		mat4 contactToWorld;
		mat4 worldToContact;
		vec3 contactVelocity;
		float desiredDeltaVelocity;
		vec3 relativePositions[2];
	};

	static ContactWorkspace generateContactWorkspace(array<RigidBody *, 2> &bodies, const Contact &contact, float deltaTime);
	static mat4 calculateContactBasis(const Contact &contact);
	static vec3 calculateRelativeVelocity(const ContactWorkspace &workspace, unsigned rigidBodyIndex, RigidBody *bodies);
	static float calculateDesiredDeltaVelocity(const ContactWorkspace &meta);

	static void resolveInterpenetration(vector<ContactWorkspace> &workspaces, array<RigidBody *, 2> &bodies);
	static void processInterpenetration(ContactWorkspace &workspace, array<RigidBody *, 2> &bodies, array<vec3, 2> &linearChange, array<vec3, 2> &angularChange);

	static void resolveVelocity(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Collision &collision, float deltaTime);
	static void resolveInterpenetration(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Collision &collision);

	static void resolveCollisionAtContact(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Contact &contact);
	static void resolveInterpenetrationAtContact(RigidBody &rigidBodyA, RigidBody &rigidBodyB, const Contact &contact);
};