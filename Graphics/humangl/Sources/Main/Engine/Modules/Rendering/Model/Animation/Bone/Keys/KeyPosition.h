#include "Vector3.h"

namespace Engine
{
	struct KeyPosition;
}

struct Engine::KeyPosition
{
	Vector3 position;
	float timeStamp;
};