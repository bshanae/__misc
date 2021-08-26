#include "PointLight.h"

using namespace Engine;

PointLight::PointLight()
{
	_position = Vector3();
	_color = Color::white;
	_intensity = 1.f;
}

Vector3 PointLight::getPosition() const
{
	return _position;
}

void PointLight::setPosition(Vector3 position)
{
	_position = position;
}

Color PointLight::getColor() const
{
	return _color;
}

void PointLight::setColor(Color color)
{
	_color = color;
}

float PointLight::getIntensity() const
{
	return _intensity;
}

void PointLight::setIntensity(float intensity)
{
	_intensity = intensity;
}