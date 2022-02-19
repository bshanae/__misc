#include "Plane.h"

#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/physics/algorithm/primitives/line/Line.h"

using namespace engine::physics;

Plane::Plane(const vec3 &normal, float distanceFromOrigin) : _normal(normal), _distanceFromOrigin(distanceFromOrigin)
{}

engine::optional<engine::vec3> Plane::clip(const Line &line) const
{
	const auto startEnd = line.getEnd() - line.getStart();
	const auto nStartEnd = dot(_normal, startEnd);

	if (approximatelyZero(nStartEnd))
		return {};

	const auto nStart = dot(_normal, line.getStart());
	const auto t = (_distanceFromOrigin - nStart) / nStartEnd;

	if (t >= 0.f and t <= 1.f)
		return line.getStart() + startEnd * t;

	return {};
}