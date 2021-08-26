#pragma once

#include "Component.h"
#include "Color.h"
#include "Vector3.h"

namespace Engine
{
	class AmbientLight;
}

class Engine::AmbientLight : public Engine::Component
{
public :

	AmbientLight();

	Color getColor() const;
	void setColor(Color color);

	float getIntensity() const;
	void setIntensity(float intensity);

private :

	Color _color;
	float _intensity;
};