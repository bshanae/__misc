#pragma once

#include "engine/tools/Tools.h"
#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/glm/glm.h"

class engine::physics::Line final
{
public :

	Line() = default;

	Line(const vec3 &start, const vec3 &end) : _start(start), _end(end)
	{}

	inline const vec3 &getStart() const
	{
		return _start;
	}

	inline void setStart(const vec3 &value)
	{
		_start = value;
	}

	inline const vec3 &getEnd() const
	{
		return _end;
	}

	inline void setEnd(const vec3 &value)
	{
		_end = value;
	}

private :

	vec3 _start;
	vec3 _end;
};