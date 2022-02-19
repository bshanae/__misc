#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/glm/glm.h"

struct engine::physics::Contact
{
	vec3 position;
	vec3 normal;
	float penetrationDepth;
};