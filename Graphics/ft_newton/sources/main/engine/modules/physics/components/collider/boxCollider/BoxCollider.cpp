#include "BoxCollider.h"

#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector.h"
#include "engine/modules/physics/components/collider/sphereCollider/SphereCollider.h"
#include "engine/modules/physics/components/collider/planeCollider/PlaneCollider.h"

using namespace engine::physics;

void BoxCollider::deserialize(BoxCollider &instance, const YAML::Node &node)
{
	instance.setSize(node["size"].as<vec3>(vec3(1.f)));
}

BoxCollider::BoxCollider(Object &object) : Collider(object, Collider::Type::Box)
{}

engine::optional<Collision> BoxCollider::testCollision(const Collider &that) const
{
	switch (that.getType())
	{
		case Collider::Type::Sphere:
			return CollisionDetector::detect(_primitive, static_cast<const SphereCollider &>(that).getPrimitive());

		case Collider::Type::Plane:
			return CollisionDetector::detect(_primitive, static_cast<const PlaneCollider &>(that).getPrimitive());

		case Collider::Type::Box:
			return CollisionDetector::detect(_primitive, static_cast<const BoxCollider &>(that).getPrimitive());

		default:
			return {};
	}
}

engine::mat4 BoxCollider::computeInertiaTensor(float mass) const
{
	constexpr auto factor = 1.0f / 12.0f;
	const auto size2 = _size * _size;

	return {
		mass * factor * (size2.y + size2.z), 0, 0, 0,
		0, mass * factor * (size2.x + size2.z), 0, 0,
		0, 0, mass * factor * (size2.x + size2.y), 0,
		0, 0, 0, 1.0f
	};
}

void BoxCollider::updatePrimitive()
{
	const auto &transformation = getTransformation();

	const auto modelMatrix = transformation.getParentHeritageMatrix() * transformation.getTranslationMatrix() * transformation.getRotationMatrix();
	const auto inverseModelMatrix = inverse(modelMatrix);

	_primitive.setPosition(transformation.getGlobalPosition());
	_primitive.setSize(_size);
	_primitive.setParentMatrix(transformation.getParentHeritageMatrix());
	_primitive.setModelMatrix(modelMatrix);
	_primitive.setInverseModelMatrix(inverseModelMatrix);
	_primitive.setTranslationMatrix(transformation.getTranslationMatrix());
	_primitive.setRotationMatrix(transformation.getRotationMatrix());
	_primitive.updateMeta();

	primitiveChanged.invoke();
}