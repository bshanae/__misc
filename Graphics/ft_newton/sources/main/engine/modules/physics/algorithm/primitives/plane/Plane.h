#pragma once

#include "engine/tools/Tools.h"
#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/std/optional.h"
#include "engine/tools/external/glm/glm.h"

class engine::physics::Plane final
{
public :

	Plane() = default;
	Plane(const vec3 &normal, float distanceFromOrigin);

	inline const vec3 &getNormal() const
	{
		return _normal;
	}

	inline void setNormal(const vec3 &value)
	{
		_normal = value;
	}

	inline float getDistanceFromOrigin() const
	{
		return _distanceFromOrigin;
	}

	inline void setDistanceFromOrigin(float value)
	{
		_distanceFromOrigin = value;
	}


	optional<vec3> clip(const Line &line) const;

private :

	vec3 _normal;
	float _distanceFromOrigin;
};