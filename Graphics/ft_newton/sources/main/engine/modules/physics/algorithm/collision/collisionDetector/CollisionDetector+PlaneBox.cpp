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
	static inline optional<Contact> processVertex(const Plane &plane, const vec3 &vertex)
	{
		const auto distanceToPlane = dot(vertex, plane.getNormal());
		if (distanceToPlane <= plane.getDistanceFromOrigin())
		{
			const auto contact = vertex + plane.getNormal() * (distanceToPlane - plane.getDistanceFromOrigin()) * 0.5f;
			const auto penetrationDepth = plane.getDistanceFromOrigin() - distanceToPlane;

			return Contact { contact, -plane.getNormal(), penetrationDepth };
		}

		return {};
	}
}

engine::optional<Collision> CollisionDetector::detect(const Plane &plane, const Box &box)
{
	vector<Contact> contacts;
	for (const auto &vertex : box.getVertices())
	{
		auto possibleContact = processVertex(plane, vertex);
		if (possibleContact != nullopt)
			contacts.push_back(*possibleContact);
	}

	if (contacts.size() == 0)
		return {};

	return Collision(move(contacts));
}