#include "PlaneCollider.h"

#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector.h"
#include "engine/modules/physics/components/collider/sphereCollider/SphereCollider.h"
#include "engine/modules/physics/components/collider/boxCollider/BoxCollider.h"

using namespace engine::physics;

void PlaneCollider::deserialize(PlaneCollider &instance, const YAML::Node &node)
{
	instance._normal = node["normal"].as<vec3>(vec3(0, 1, 0));
	instance._distanceFromOrigin = node["distance from origin"].as<float>(0.f);
}

PlaneCollider::PlaneCollider(Object &object) : Collider(object, Collider::Type::Plane)
{}

engine::optional<Collision> PlaneCollider::testCollision(const Collider &that) const
{
	switch (that.getType())
	{
//		case Collider::Type::Sphere:
//			return CollisionDetector::detect(getPrimitive(), static_cast<const SphereCollider &>(that).getPrimitive());

		case Collider::Type::Box:
			return CollisionDetector::detect(getPrimitive(), static_cast<const BoxCollider &>(that).getPrimitive());

		default:
			return {};
	}
}

engine::mat4 PlaneCollider::computeInertiaTensor(float mass) const
{
	return {};
}

void PlaneCollider::updatePrimitive()
{
	_primitive.setNormal(_normal);
	_primitive.setDistanceFromOrigin(_distanceFromOrigin);
}