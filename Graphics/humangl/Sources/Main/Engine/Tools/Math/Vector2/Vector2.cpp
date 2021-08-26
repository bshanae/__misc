#include "Vector2.h"

using namespace Engine;

Vector2::Vector2() : x(0), y(0)
{}

Vector2::Vector2(float value) : x(value), y(value)
{}

Vector2::Vector2(float x, float y) : x(x), y(y)
{}

Vector2 Engine::operator + (const Vector2 &left, const Vector2 &right)
{
	return {left.x + right.x, left.y + right.y};
}

Vector2 Engine::operator - (const Vector2 &left, const Vector2 &right)
{
	return {left.x - right.x, left.y - right.y};
}

Vector2 Engine::operator * (const Vector2 &vector, float value)
{
	return {vector.x * value, vector.y * value};
}