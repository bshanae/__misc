#pragma once

#include "engine/tools/Tools.h"

#include "engine/tools/external/std/mathematics.h"
#include "engine/tools/external/glm/glm.h"

namespace engine
{
	constexpr float epsilon = 0.0001f;

	inline bool approximately(float a, float b, float threshold = epsilon)
	{
		return abs(a - b) < threshold;
	}

	inline bool approximatelyZero(float v, float threshold = epsilon)
	{
		return abs(v) < threshold;
	}

	inline bool approximately(const vec2 &a, const vec2 &b, float threshold = epsilon)
	{
		return approximately(a.x, b.x, threshold) and approximately(a.y, b.y, threshold);
	}

	inline bool approximatelyZero(const vec2 &a, float threshold = epsilon)
	{
		return approximatelyZero(a.x, epsilon) and approximatelyZero(a.y, epsilon);
	}

	inline bool approximately(const vec3 &a, const vec3 &b, float threshold = epsilon)
	{
		return approximately(a.x, b.x, threshold) and
			   approximately(a.y, b.y, threshold) and
			   approximately(a.z, b.z, threshold);
	}

	inline bool approximatelyZero(const vec3 &v, float threshold = epsilon)
	{
		return approximatelyZero(v.x, threshold) and
			   approximatelyZero(v.y, threshold) and
			   approximatelyZero(v.z, threshold);
	}

	template <typename T>
	inline T isInfinity(T value)
	{
		return value == numeric_limits<T>::infinity();
	}

	template <typename T>
	inline T isNotInfinity(T value)
	{
		return value != numeric_limits<T>::infinity();
	}

	/// If value is not infinity, return it. Otherwise, return fallback value.
	template <typename T>
	inline T takeIfNotInfinity(T value, T fallback)
	{
		return isNotInfinity(value) ? value : fallback;
	}

	inline vec3 transformPoint(const vec3 &point, const mat4 &matrix)
	{
		return vec3(matrix * vec4(point, 1.f));
	}

	inline vec3 transformDirection(const vec3 &direction, const mat4 &matrix)
	{
		return vec3(matrix * vec4(direction, 0.f));
	}

	inline mat4 makeMatrixFromBasis(const vec3 &xAxis, const vec3 &yAxis, const vec3 &zAxis)
	{
		return mat4(
			xAxis.x, xAxis.y, xAxis.z, 0,
			yAxis.x, yAxis.y, yAxis.z, 0,
			zAxis.x, zAxis.y, zAxis.z, 0,
			0, 0, 0, 1
		);
	}

	inline mat4 deduceRotationMatrixFromZAxis(const vec3 &zAxis)
	{
		vec3 xAxis;
		vec3 yAxis;

		if (zAxis != vec3(1.f, 0.f, 0.f))
		{
			yAxis = normalize(cross(zAxis, vec3(1.f, 0.f, 0.f)));
			xAxis = normalize(cross(zAxis, yAxis));
		}
		else
		{
			xAxis = normalize(cross(zAxis, vec3(0.f, 1.f, 0.f)));
			yAxis = normalize(cross(zAxis, xAxis));
		}


		return makeMatrixFromBasis(xAxis, yAxis, zAxis);
	}
}