#include "Color.h"

using namespace engine;

Color Color::black = Color(0, 0, 0);
Color Color::white = Color(1, 1, 1);
Color Color::red = Color(1, 0, 0);
Color Color::blue = Color(0, 0, 1);
Color Color::green = Color(0, 1, 0);

Color::Color() : Color(0, 0, 0)
{}

Color::Color(float r, float g, float b) : r(r), g(g), b(b), a(1)
{}

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a)
{}

unsigned hash(const Color &color)
{
	unsigned r = color.r * 256.f;
	unsigned g = color.g * 256.f;
	unsigned b = color.b * 256.f;
	unsigned a = color.a * 256.f;

	unsigned hash = 0;
	hash |= r << 8 * 3;
	hash |= g << 8 * 2;
	hash |= b << 8 * 1;
	hash |= a << 8 * 0;

	return hash;
}