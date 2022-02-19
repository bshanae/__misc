#include "CollisionDetector.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/physics/algorithm/primitives/sphere/Sphere.h"
#include "engine/modules/physics/algorithm/primitives/box/Box.h"
#include "engine/modules/physics/algorithm/primitives/interval/Interval.h"

using namespace engine::physics;

namespace engine::physics
{
	static inline vec3 getClosestPointOnBox(const vec3 &halfSize, const vec3 &point)
	{
		return {
			clamp(point.x, -halfSize.x, halfSize.x),
			clamp(point.y, -halfSize.y, halfSize.y),
			clamp(point.z, -halfSize.z, halfSize.z)
		};
	}
}

engine::optional<Collision> CollisionDetector::detect(const Sphere &sphere, const Box &box)
{
	// All calculations are performed in perspective of the box

	const auto halfSize = box.getHalfSize();

	const auto sphereCenterInWCS = sphere.getPosition();
	const auto sphereCenterInLCS = transformPoint(sphereCenterInWCS, box.getInverseModelMatrix());

	if (abs(sphereCenterInLCS.x) - sphere.getRadius() > halfSize.x)
		return {};
	if (abs(sphereCenterInLCS.y) - sphere.getRadius() > halfSize.y)
		return {};
	if (abs(sphereCenterInLCS.z) - sphere.getRadius() > halfSize.z)
		return {};

	const auto closestPointInLCS = getClosestPointOnBox(halfSize, sphereCenterInLCS);

	const auto distanceToSphere = length(closestPointInLCS - sphereCenterInLCS);
 	if (distanceToSphere > sphere.getRadius())
		 return {};

	const auto closestPointInWCS = transformPoint(closestPointInLCS, box.getModelMatrix());
	const auto contactNormal = normalize(sphereCenterInWCS - closestPointInWCS);
	const auto penetrationDepth = sphere.getRadius() - distanceToSphere;

	return Collision(Contact { closestPointInWCS, contactNormal, penetrationDepth });
}