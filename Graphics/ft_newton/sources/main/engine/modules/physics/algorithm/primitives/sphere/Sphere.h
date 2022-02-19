#pragma once

#include "engine/tools/Tools.h"
#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/glm/glm.h"

class engine::physics::Sphere final
{
public :

	Sphere() = default;

	inline const vec3 &getPosition() const
	{
		return _position;
	}

	inline void setPosition(const vec3 &value)
	{
		_position = value;
	}

	inline float getRadius() const
	{
		return _radius;
	}

	inline void setRadius(float value)
	{
		_radius = value;
	}

private :

	vec3 _position;
	float _radius;
};