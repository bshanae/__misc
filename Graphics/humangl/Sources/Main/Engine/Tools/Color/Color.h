#pragma once

namespace Engine
{
	class Color;
}

class Engine::Color
{
public :

	static Color black;
	static Color white;

	Color();
	Color(float red, float green, float blue);

	float r;
	float g;
	float b;
};