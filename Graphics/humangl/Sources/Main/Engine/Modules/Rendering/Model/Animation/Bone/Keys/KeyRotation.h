#include "Quaternion.h"

namespace Engine
{
	struct KeyRotation;
}

struct Engine::KeyRotation
{
	Quaternion orientation;
	float timeStamp;
};