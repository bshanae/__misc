#include "Matrix4x4.h"

namespace Engine
{
	struct BoneInfo;
}

struct Engine::BoneInfo
{
	int id;
	Matrix4x4 offset;
};