#include "Vector4.h"

using namespace Engine;

Vector4::Vector4() : x(0), y(0), z(0), w(0)
{}

Vector4::Vector4(float value) : x(value), y(value), z(value), w(value)
{}

Vector4::Vector4(const Vector3 &other, float w) : x(other.x), y(other.y), z(other.z), w(w)
{}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{}

Vector4::operator Vector3 () const
{
	return {x, y, z};
}

const float &Vector4::operator [] (int index) const
{
	return array[index];
}
float &Vector4::operator [] ( int index )
{
	return array[index];
}
Vector4 Engine::operator + (const Vector4 &left, const Vector4 &right)
{
	return {left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w};
}

Vector4 Engine::operator - (const Vector4 &left, const Vector4 &right)
{
	return {left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w};
}

Vector4 Engine::operator * (const Vector4 &vector, float value)
{
	return {vector.x * value, vector.y * value, vector.z * value, vector.w * value};
}

Vector4 Engine::operator * (const Vector4 &left, const Vector4 &right)
{
	return {left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w};
}