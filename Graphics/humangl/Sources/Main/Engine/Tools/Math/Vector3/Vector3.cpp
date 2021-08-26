#include "Vector3.h"

#include <complex>

using namespace Engine;

float Vector3::dot(const Vector3 &left, const Vector3 &right)
{
	return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vector3 Vector3::cross(const Vector3 &left, const Vector3 &right)
{
	return {
		left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x};
}

Vector3 Vector3::normalize(const Vector3 &original)
{
	const float magnitude = original.getLength();

	if (magnitude == 0.f)
		throw VectorIsZero();

	return {original.x / magnitude, original.y / magnitude, original.z / magnitude};
}

Vector3 Vector3::mix(const Vector3 &a, const Vector3 &b, float factor)
{
	return a * (1 - factor) + a * factor;
}

Vector3::Vector3() : x(0), y(0), z(0)
{}

Vector3::Vector3(float value) : x(value), y(value), z(value)
{}

bool Vector3::operator == (const Vector3 &other) const
{
	return this->x == other.x and this->y == other.y and this->z == other.z;
}

bool Vector3::operator != (const Vector3 &other) const
{
	return not (*this == other);
}

Vector3 Engine::operator + (const Vector3 &left, const Vector3 &right)
{
	return {left.x + right.x, left.y + right.y, left.z + right.z};
}

Vector3 Engine::operator - (const Vector3 &left, const Vector3 &right)
{
	return {left.x - right.x, left.y - right.y, left.z - right.z};
}

void Vector3::operator += (const Vector3 &other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

void Vector3::operator -= (const Vector3 &other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

std::ostream &Engine::operator << (std::ostream &stream, const Vector3& vector)
{
	stream << "{" << vector.x << ", " << vector.y << ", " << vector.z << "}";
	return stream;
}

float Vector3::getLength() const
{
	return sqrt(x * x + y * y + z * z);
}