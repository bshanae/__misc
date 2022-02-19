#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/modules/physics/components/collider/Collider.h"
#include "engine/modules/physics/algorithm/primitives/box/Box.h"

class engine::physics::BoxCollider final : public engine::physics::Collider
{
public :

	inline static const string typeName = "box collider";
	static void deserialize(BoxCollider &instance, const YAML::Node &node);

	BoxCollider(Object &object);
	~BoxCollider() override = default;

	inline const Box &getPrimitive() const
	{
		return _primitive;
	}

	inline void setSize(const vec3 &size)
	{
		_size = size;

		if (isPrepared())
			updatePrimitive();
	}

	optional<Collision> testCollision(const Collider &) const override;

protected :

	mat4 computeInertiaTensor(float mass) const override;
	void updatePrimitive() override;

private :

	Box _primitive;
	vec3 _size;
};
