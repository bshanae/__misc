#pragma once

#include "engine/modules/physics/Physics.h"

class engine::physics::Interval final
{
public :

	Interval(float value) : min(value), max(value)
	{}

	Interval(float min, float max) : min(min), max(max)
	{}

	float min;
	float max;

	float computeLength() const
	{
		return max - min;
	}
};