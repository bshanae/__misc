#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/std/optional.h"
#include "engine/modules/physics/algorithm/collision/Collision.h"

class engine::physics::CollisionDetector
{
public :

	static optional<Collision> detect(const Sphere &sphereA, const Sphere &sphereB);
	static optional<Collision> detect(const Sphere &sphere, const Plane &plane);
	static optional<Collision> detect(const Sphere &sphere, const Box &box);

	static optional<Collision> detect(const Plane &plane, const Sphere &sphere);
	static optional<Collision> detect(const Plane &plane, const Box &box);

	static optional<Collision> detect(const Box &box, const Sphere &sphere);
	static optional<Collision> detect(const Box &box, const Plane &plane);
	static optional<Collision> detect(const Box &boxA, const Box &boxB);

	CollisionDetector() = delete;
	~CollisionDetector() = delete;
};