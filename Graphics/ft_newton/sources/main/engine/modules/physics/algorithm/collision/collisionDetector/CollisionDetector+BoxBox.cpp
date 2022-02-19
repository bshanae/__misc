#include "CollisionDetector.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/glm/glm.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/physics/algorithm/primitives/sphere/Sphere.h"
#include "engine/modules/physics/algorithm/primitives/box/Box.h"
#include "engine/modules/physics/algorithm/primitives/interval/Interval.h"

namespace engine::physics
{
	void findContacts(const Box &boxA, const Box &boxB, vector<Contact> &contacts, const vec3 &normal, float penetrationDepth)
	{
		const auto &aEdges = boxA.getEdges();
		const auto &bPlanes = boxB.getPlanes();

		for (const auto &aEdge: aEdges)
		for (const auto &bPlane: bPlanes)
		{
			if (auto intersection = bPlane.clip(aEdge); intersection and boxB.isInside(*intersection))
				contacts.push_back({ .position = *intersection, .normal = normal, .penetrationDepth = penetrationDepth });
		}
	}

	float computePenetrationDepth(const Box &boxA, const Box &boxB, const vec3 &axis, bool &shouldFlip)
	{
		const auto intervalA = boxA.getInterval(axis);
		const auto intervalB = boxB.getInterval(axis);

		if (not(intervalB.min <= intervalA.max and intervalA.min <= intervalB.max))
			return 0;

		const auto lengthA = intervalA.computeLength();
		const auto lengthB = intervalB.computeLength();

		const auto min = engine::min(intervalA.min, intervalB.min);
		const auto max = engine::max(intervalA.max, intervalB.max);

		const auto length = max - min;

		shouldFlip = intervalB.min < intervalA.min;

		return lengthA + lengthB - length;
	}
}

using namespace engine::physics;

#include <iostream>

engine::optional<Collision> CollisionDetector::detect(const Box &boxA, const Box &boxB)
{
	const auto &aAxes = boxA.getAxes();
	const auto &bAxes = boxB.getAxes();

	array<vec3, 15> testAxes =
	{
		aAxes[0],
		aAxes[1],
		aAxes[2],
		bAxes[0],
		bAxes[1],
		bAxes[2],
		cross(aAxes[0], bAxes[0]),
		cross(aAxes[0], bAxes[1]),
		cross(aAxes[0], bAxes[2]),
		cross(aAxes[1], bAxes[0]),
		cross(aAxes[1], bAxes[1]),
		cross(aAxes[1], bAxes[2]),
		cross(aAxes[2], bAxes[0]),
		cross(aAxes[2], bAxes[1]),
		cross(aAxes[2], bAxes[2])
	};

	auto intermediatePenetrationDepth = numeric_limits<float>::max();
	vec3 *hitNormalRef = nullptr;

	for (auto &testAxis: testAxes)
	{
		if (length2(testAxis) < 0.001f)
			continue;

		bool shouldFlip;
		const auto penetrationDepth = computePenetrationDepth(boxA, boxB, testAxis, shouldFlip);

		if (penetrationDepth <= 0.f)
			return {};

		if (penetrationDepth < intermediatePenetrationDepth)
		{
			if (shouldFlip)
				testAxis *= -1.f;

			intermediatePenetrationDepth = penetrationDepth;
			hitNormalRef = &testAxis;
		}
	}

	if (hitNormalRef == nullptr)
		return {};

	const auto penetrationDepth = intermediatePenetrationDepth;
	const auto intersectionAxis = normalize(*hitNormalRef);

	auto contacts = vector<Contact>();

	findContacts(boxA, boxB, contacts, -intersectionAxis, penetrationDepth);
	findContacts(boxB, boxA, contacts, -intersectionAxis, penetrationDepth);

	const auto interval = boxA.getInterval(intersectionAxis);
	const auto distance = interval.computeLength() * 0.5f - penetrationDepth * 0.5f;
	const auto pointOnPlane = boxA.getPosition() + intersectionAxis * distance;

	for (int i = contacts.size() - 1; i >= 0; --i)
	{
		contacts[i].position += (intersectionAxis * dot(intersectionAxis, pointOnPlane - contacts[i].position));

		for (int j = contacts.size() - 1; j > i; --j)
		{
			if (engine::distance(contacts[j].position, contacts[i].position) < 0.0001f)
			{
				contacts.erase(contacts.begin() + j);
				break;
			}
		}
	}

	return Collision(move(contacts));
}