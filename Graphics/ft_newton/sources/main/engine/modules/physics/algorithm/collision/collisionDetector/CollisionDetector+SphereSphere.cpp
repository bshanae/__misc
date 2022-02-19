#include "CollisionDetector.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/physics/algorithm/primitives/sphere/Sphere.h"
#include "engine/modules/physics/algorithm/primitives/box/Box.h"
#include "engine/modules/physics/algorithm/primitives/interval/Interval.h"

using namespace engine::physics;

engine::optional<Collision> CollisionDetector::detect(const Sphere &sphereA, const Sphere &sphereB)
{
	const auto radiiSum = sphereA.getRadius() + sphereB.getRadius();

	const auto positionDelta = sphereA.getPosition() - sphereB.getPosition();
	const auto positionDeltaLength = length(positionDelta);

	if (positionDeltaLength > radiiSum or positionDeltaLength == 0)
		return {};

	const auto intersectionNormal = positionDelta * (1.f / positionDeltaLength); // faster way to get normalize delta
	const auto intersectionDepth = radiiSum - positionDeltaLength;
	const auto contactPoint = sphereA.getPosition() - positionDelta * 0.5f;

	return Collision(Contact { contactPoint, intersectionNormal, intersectionDepth });
}