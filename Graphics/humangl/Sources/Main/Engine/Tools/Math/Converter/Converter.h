#pragma once

#include <Assimp.h>

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

namespace Engine
{
	class Converter;
}

class Engine::Converter final
{
public :

	static Matrix4x4 convert(const aiMatrix4x4 &from)
	{
		Matrix4x4 to;

		to[0][0] = from.a1;
		to[1][0] = from.a2;
		to[2][0] = from.a3;
		to[3][0] = from.a4;

		to[0][1] = from.b1;
		to[1][1] = from.b2;
		to[2][1] = from.b3;
		to[3][1] = from.b4;

		to[0][2] = from.c1;
		to[1][2] = from.c2;
		to[2][2] = from.c3;
		to[3][2] = from.c4;

		to[0][3] = from.d1;
		to[1][3] = from.d2;
		to[2][3] = from.d3;
		to[3][3] = from.d4;

		return to;
	}

	static Vector3 convert(const aiVector3D &source)
	{
		return {source.x, source.y, source.z};
	}

	static Quaternion convert(const aiQuaternion &source)
	{
		return {source.x, source.y, source.z, source.w};
	}
};