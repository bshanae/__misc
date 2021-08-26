#pragma once

#include "Vector3.h"

namespace Engine
{
	class Vector4;
}

class Engine::Vector4 final
{
public :

	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};

		float array[4];
	};

	Vector4();
	Vector4(float value);
	Vector4(const Vector3 &other, float w);
	Vector4(float x, float y, float z, float w);

	operator Vector3 () const;

	const float &operator [] (int index) const;
	float &operator [] (int index);

	friend Vector4 operator + (const Vector4 &left, const Vector4 &right);
	friend Vector4 operator - (const Vector4 &left, const Vector4 &right);

	friend Vector4 operator * (const Vector4 &vector, float value);
	friend Vector4 operator * (const Vector4 &left, const Vector4 &right);
};