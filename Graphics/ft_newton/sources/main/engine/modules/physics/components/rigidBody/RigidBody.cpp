#include "RigidBody.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/physics/settings/Settings.h"
#include "engine/modules/physics/components/collider/Collider.h"

using namespace engine::physics;

void RigidBody::deserialize(RigidBody &instance, const YAML::Node &node)
{
	instance.setMass(node["mass"].as<float>(1.0));
	instance.setCoefficientOfRestitution(node["coefficient of restitution"].as<float>(0.4));
	instance.setFriction(node["friction"].as<float>(0));
}

RigidBody::RigidBody(Object &object) :
	Component(object),
	_transformationFinder(*this),
	_colliderFinder(*this),
	_forceAccumulator(0),
	_torgueAccumulator(0),
	_linearVelocity(0),
	_angularVelocity(0)
{
}

void RigidBody::setMass(float value)
{
	_mass = value;
	_inverseMass = 1.f / value;

	_weight = takeIfNotInfinity(value, 0.f) * Settings::getGravityAcceleration();
}

void RigidBody::applyForce(const vec3 &force)
{
	_forceAccumulator += force;
}

void RigidBody::applyForce(const vec3 &force, const vec3 &point)
{

}

void RigidBody::applyTorque(const vec3 &point, const vec3 &force)
{
	const auto centerOfMass = _transformationFinder().getGlobalPosition();
	const auto torgue = cross(point - centerOfMass, force);

	_torgueAccumulator += torgue;
}

void RigidBody::resetVelocity()
{
	_linearVelocity = vec3(0);
	_angularVelocity = vec3(0);
}

void RigidBody::prepareInternally()
{
	updateInverseInertiaTensor();
	subscribe(_transformationFinder().changed, [this](){ updateInverseInertiaTensor(); });
}

void RigidBody::integrate(float deltaTime)
{
	_forceAccumulator += _weight;

	integratePosition(deltaTime);
	integrateLinearVelocity(deltaTime);

	integrateOrientation(deltaTime);
	integrateAngularVelocity(deltaTime);
}

void RigidBody::updateInverseInertiaTensor()
{
	if (_colliderFinder.isFound())
		_inverseInertiaTensor = _colliderFinder()->computeInverseInertiaTensor(_mass);
	else
		_inverseInertiaTensor = mat4(1);
}

void RigidBody::integrateLinearVelocity(float deltaTime)
{
	const auto acceleration = _forceAccumulator * _inverseMass;
	_forceAccumulator = vec3(0);

	_linearVelocity += acceleration * deltaTime;
	_linearVelocity *= Settings::getLinearVelocityDamping();
}

void RigidBody::integratePosition(float deltaTime)
{
	_transformationFinder().moveBy(_linearVelocity * deltaTime);
}

void RigidBody::integrateAngularVelocity(float deltaTime)
{
	const auto acceleration = transformDirection(_torgueAccumulator, _inverseInertiaTensor);
	_torgueAccumulator = vec3(0);

	_angularVelocity += acceleration * deltaTime;
	_angularVelocity *= Settings::getAngularVelocityDamping();
}

void RigidBody::integrateOrientation(float deltaTime)
{
	const auto axis = normalize(_angularVelocity);
	const auto angle = length(_angularVelocity) * deltaTime;

	if (approximatelyZero(angle))
		return;

	_transformationFinder().rotateAround(axis, angle);
}