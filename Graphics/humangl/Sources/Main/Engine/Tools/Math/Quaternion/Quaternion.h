#pragma once

namespace Engine
{
	struct Quaternion;
}

struct Engine::Quaternion final
{
public :

	static Quaternion normalize(const Quaternion &source);
	static Quaternion slerp(const Quaternion &a, const Quaternion &b, float factor);

	float x;
	float y;
	float z;
	float w;

	Quaternion();
	Quaternion(float x, float y, float z, float w);
};