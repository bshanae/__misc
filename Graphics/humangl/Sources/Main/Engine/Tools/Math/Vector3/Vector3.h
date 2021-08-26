#pragma once

#include <iostream>

#include "Exception.h"

namespace Engine
{
	class Vector3;
}

class Engine::Vector3 final
{
public :

	class VectorIsZero : public Exception {};

	float x;
	float y;
	float z;

	static float dot(const Vector3 &left, const Vector3 &right);
	static Vector3 cross(const Vector3 &left, const Vector3 &right);
	static Vector3 normalize(const Vector3 &original);

	static Vector3 mix(const Vector3 &a, const Vector3 &b, float factor);

	Vector3();
	Vector3(float value);

	template <typename T>
	Vector3(T x, T y, T z) : x(x), y(y), z(z)
	{}

	bool operator == (const Vector3 &other) const;
	bool operator != (const Vector3 &other) const;

	friend Vector3 operator + (const Vector3 &left, const Vector3 &right);
	friend Vector3 operator - (const Vector3 &left, const Vector3 &right);

	void operator += (const Vector3 &other);
	void operator -= (const Vector3 &other);

	template <typename T>
	friend Vector3 operator * (const Vector3 &vector, T value)
	{
		return {vector.x * value, vector.y * value, vector.z * value};
	}

	template <typename T>
	friend Vector3 operator * (T value, const Vector3 &vector)
	{
		return {vector.x * value, vector.y * value, vector.z * value};
	}

	template <typename T>
	friend Vector3 operator / (const Vector3 &vector, T value)
	{
		return {vector.x / value, vector.y / value, vector.z / value};
	}

	template <typename T>
	friend Vector3 operator / (T value, const Vector3 &vector)
	{
		return {value / vector.x, value / vector.y, value / vector.z};
	}

	friend std::ostream &operator << (std::ostream &stream, const Vector3& vector);

	float getLength() const;
};