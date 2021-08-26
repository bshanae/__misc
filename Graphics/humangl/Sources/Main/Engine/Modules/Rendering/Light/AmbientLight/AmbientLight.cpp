#include "AmbientLight.h"

using namespace Engine;

AmbientLight::AmbientLight()
{
	_color = Color::white;
	_intensity = 0.1f;
}

Color AmbientLight::getColor() const
{
	return _color;
}

void AmbientLight::setColor(Color color)
{
	_color = color;
}

float AmbientLight::getIntensity() const
{
	return _intensity;
}

void AmbientLight::setIntensity(float intensity)
{
	_intensity = intensity;
}