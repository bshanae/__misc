#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/external/std/optional.h"
#include "engine/tools/external/std/pointers.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"
#include "engine/modules/physics/algorithm/collision/Collision.h"

class engine::physics::Collider : public Component
{
public :

	enum class Type
	{
		Plane,
		Sphere,
		Box
	};

	Event<> primitiveChanged;

	virtual ~Collider() override = default;

	inline Type getType() const
	{
		return _type;
	}

	inline const Collision *getCollision() const
	{
		return _collision;
	}

	inline void setCollision(const Collision *collision)
	{
		_collision = collision;
	}

	mat4 computeInverseInertiaTensor(float mass) const;

	virtual optional<Collision> testCollision(const Collider &) const = 0;

protected :

	Collider(Object &object, Type type);

	inline Transformation &getTransformation() const
	{
		return _transformationFinder();
	}

	virtual mat4 computeInertiaTensor(float mass) const = 0;

	virtual void updatePrimitive() = 0;

	void prepareInternally() override;

private :

	const Type _type;
	const Collision *_collision;

	ComponentFinder<Transformation, Mandatory> _transformationFinder;
};