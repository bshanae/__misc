#pragma once

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "engine/tools/external/glm/glm.h"

namespace engine
{
	inline static mat4 to_glm(const aiMatrix4x4 &source)
	{
		return {
			source.a1, source.b1, source.c1, source.d1,
			source.a2, source.b2, source.c2, source.d2,
			source.a3, source.b3, source.c3, source.d3,
			source.a4, source.b4, source.c4, source.d4
		};
	}

	inline static vec3 to_glm(const aiVector3D &source)
	{
		return { source.x, source.y, source.z };
	}

	inline static quat to_glm(const aiQuaternion &source)
	{
		return { source.w, source.x, source.y, source.z };
	}
}