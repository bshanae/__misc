#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/modules/physics/components/collider/Collider.h"
#include "engine/modules/physics/algorithm/primitives/sphere/Sphere.h"

class engine::physics::SphereCollider final : public engine::physics::Collider
{
public :

	inline static const string typeName = "sphere collider";
	static void deserialize(SphereCollider &instance, const YAML::Node &node);

	SphereCollider(Object &object);
	~SphereCollider() override = default;

	inline const Sphere &getPrimitive() const
	{
		return _primitive;
	}

	inline void setRadius(float value)
	{
		_radius = value;

		if (isPrepared())
			updatePrimitive();
	}

	optional<Collision> testCollision(const Collider &) const override;

protected :

	mat4 computeInertiaTensor(float mass) const override;
	void updatePrimitive() override;

private :

	Sphere _primitive;
	float _radius;
};
