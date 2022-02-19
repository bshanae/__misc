#include "CollisionDetector.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/physics/algorithm/primitives/sphere/Sphere.h"
#include "engine/modules/physics/algorithm/primitives/box/Box.h"
#include "engine/modules/physics/algorithm/primitives/interval/Interval.h"

using namespace engine::physics;

engine::optional<Collision> CollisionDetector::detect(const Box &box, const Sphere &sphere)
{
	auto collision = detect(sphere, box);
	if (collision != nullopt)
		collision->inverseNormals();

	return collision;
}

