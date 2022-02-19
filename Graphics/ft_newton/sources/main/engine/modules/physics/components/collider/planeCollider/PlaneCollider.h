#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/modules/physics/components/collider/Collider.h"
#include "engine/modules/physics/algorithm/primitives/plane/Plane.h"

class engine::physics::PlaneCollider final : public engine::physics::Collider
{
public :

	inline static const string typeName = "plane collider";
	static void deserialize(PlaneCollider &instance, const YAML::Node &node);

	PlaneCollider(Object &object);
	~PlaneCollider() override = default;

	inline const Plane &getPrimitive() const
	{
		return _primitive;
	}

	optional<Collision> testCollision(const Collider &) const override;

protected :

	mat4 computeInertiaTensor(float mass) const override;
	void updatePrimitive() override;

private :

	Plane _primitive;
	vec3 _normal;
	float _distanceFromOrigin;
};
