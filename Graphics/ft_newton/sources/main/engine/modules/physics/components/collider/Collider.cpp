#include "Collider.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/mathematics/Mathematics.h"

using namespace engine::physics;

Collider::Collider(Object &object, Type type) : Component(object), _type(type), _transformationFinder(*this)
{}

engine::mat4 Collider::computeInverseInertiaTensor(float mass) const
{
	if (isInfinity(mass))
		return mat4(0);

	auto globalRotationMatrix = _transformationFinder().getParentHeritageMatrix() * _transformationFinder().getRotationMatrix();
	globalRotationMatrix[3] = vec4(0, 0, 0, 1); // Delete translation

	return globalRotationMatrix * inverse(computeInertiaTensor(mass)); // TODO This may be incorrect
}

void Collider::prepareInternally()
{
	updatePrimitive();
	subscribe(_transformationFinder().changed,[this](){ updatePrimitive(); });
}