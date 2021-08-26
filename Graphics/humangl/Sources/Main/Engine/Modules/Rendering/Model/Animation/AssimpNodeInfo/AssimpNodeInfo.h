#include "Matrix4x4.h"

namespace Engine
{
	struct AssimpNodeInfo;
}

struct Engine::AssimpNodeInfo
{
	Matrix4x4 transformation;
	std::string name;
	std::vector<AssimpNodeInfo> children;
};