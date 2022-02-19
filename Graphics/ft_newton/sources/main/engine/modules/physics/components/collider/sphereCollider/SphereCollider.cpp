#include "SphereCollider.h"

#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector.h"
#include "engine/modules/physics/components/collider/planeCollider/PlaneCollider.h"
#include "engine/modules/physics/components/collider/boxCollider/BoxCollider.h"

using namespace engine::physics;

void SphereCollider::deserialize(SphereCollider &instance, const YAML::Node &node)
{
	instance.setRadius(node["radius"].as<float>(1.f));
}

SphereCollider::SphereCollider(Object &object) : Collider(object, Collider::Type::Sphere)
{}

engine::optional<Collision> SphereCollider::testCollision(const Collider &that) const
{
	switch (that.getType())
	{
		case Collider::Type::Sphere:
			return CollisionDetector::detect(getPrimitive(), static_cast<const SphereCollider &>(that).getPrimitive());

		case Collider::Type::Plane:
			return CollisionDetector::detect(getPrimitive(), static_cast<const PlaneCollider &>(that).getPrimitive());

		case Collider::Type::Box:
			return CollisionDetector::detect(getPrimitive(), static_cast<const BoxCollider &>(that).getPrimitive());

		default:
			return {};
	}
}

engine::mat4 SphereCollider::computeInertiaTensor(float mass) const
{
	const auto diagonal = 2.0f / 5.0f * mass * _radius * _radius;

	return {
		diagonal, 0, 0, 0,
		0, diagonal, 0, 0,
		0, 0, diagonal, 0,
		0, 0, 0, 1.0f
	};
}

void SphereCollider::updatePrimitive()
{
	const auto &transformation = getTransformation();

	_primitive.setRadius(_radius);
	_primitive.setPosition(transformation.getGlobalPosition());

	primitiveChanged.invoke();
}