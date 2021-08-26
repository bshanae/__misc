#pragma once

namespace Engine
{
	class Vector2;
}

class Engine::Vector2 final
{
public :

	float x;
	float y;

	Vector2();
	explicit Vector2(float value);
	Vector2(float x, float y);

	friend Vector2 operator + (const Vector2 &left, const Vector2 &right);
	friend Vector2 operator - (const Vector2 &left, const Vector2 &right);
	friend Vector2 operator * (const Vector2 &vector, float value);
};