#pragma once

namespace Engine
{
	class MathUtilities;
}

class Engine::MathUtilities
{
public :

	template <typename T>
	static T sign(T value)
	{
		return value > 0 ? static_cast<T>(+1) : static_cast<T>(-1);
	}

	static float degreesToRadians(float input);
	static float radiansToDegrees(float input);
};