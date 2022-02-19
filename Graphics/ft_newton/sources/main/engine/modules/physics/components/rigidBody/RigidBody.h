#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"

class engine::physics::RigidBody final : public Component
{
	friend class Module;
	friend class CollisionResolver;

public :

	inline static const string typeName = "rigid body";
	static void deserialize(RigidBody &instance, const YAML::Node &node);

	RigidBody(Object &object);
	~RigidBody() override = default;

	inline float getMass() const
	{
		return _mass;
	}

	void setMass(float value);

	inline float getCoefficientOfRestitution() const
	{
		return _coefficientOfRestitution;
	}

	inline void setCoefficientOfRestitution(float value)
	{
		_coefficientOfRestitution = value;
	}

	inline float getFriction() const
	{
		return _friction;
	}

	inline void setFriction(float value)
	{
		_friction = value;
	}

	inline vec3 getVelocity() const
	{
		return _linearVelocity;
	}

	void applyForce(const vec3 &force);
	void applyForce(const vec3 &force, const vec3 &point);
	void applyTorque(const vec3 &point, const vec3 &force);

	void resetVelocity();

protected :

	void prepareInternally() override;

private :

	float _mass;
	float _inverseMass;

	float _coefficientOfRestitution;
	float _friction;

	vec3 _weight;
	mat4 _inverseInertiaTensor;

	ComponentFinder<Transformation, Mandatory> _transformationFinder;
	ComponentFinder<Collider, Optional> _colliderFinder;

	void integrate(float deltaTime);
	void updateInverseInertiaTensor();

	// Linear motion

	vec3 _forceAccumulator;
	vec3 _linearVelocity;

	void integrateLinearVelocity(float deltaTime);
	void integratePosition(float deltaTime);

	// Angular motion

	vec3 _torgueAccumulator;
	vec3 _angularVelocity;

	void integrateAngularVelocity(float deltaTime);
	void integrateOrientation(float deltaTime);
};