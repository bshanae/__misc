#include "CollisionDetector.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/physics/algorithm/primitives/sphere/Sphere.h"
#include "engine/modules/physics/algorithm/primitives/box/Box.h"
#include "engine/modules/physics/algorithm/primitives/interval/Interval.h"

using namespace engine::physics;

engine::optional<Collision> CollisionDetector::detect(const Sphere &sphere, const Plane &plane)
{
	const auto distanceToPlane = dot(plane.getNormal(), sphere.getPosition()) - sphere.getRadius() - plane.getDistanceFromOrigin();
	if (distanceToPlane >= 0)
		return {};

	const auto intersectionNormal = plane.getNormal();
	const auto intersectionDepth = -distanceToPlane;
	const auto contactPoint = sphere.getPosition() - plane.getNormal() * (distanceToPlane + sphere.getRadius());

	return Collision(Contact { contactPoint, intersectionNormal, intersectionDepth });
}