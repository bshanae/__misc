#include "Color.h"

using namespace Engine;

Color Color::black = Color(0, 0, 0);
Color Color::white = Color(1, 1, 1);

Color::Color() : Color(0, 0, 0)
{}

Color::Color(float red, float green, float blue)
{
	this->r = red;
	this->g = green;
	this->b = blue;
}