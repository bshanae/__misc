#pragma once

#include "Component.h"
#include "Color.h"
#include "Vector3.h"

namespace Engine
{
	class PointLight;
}

class Engine::PointLight : public Engine::Component
{
public :

	PointLight();

	Vector3 getPosition() const;
	void setPosition(Vector3 position);

	Color getColor() const;
	void setColor(Color color);

	float getIntensity() const;
	void setIntensity(float intensity);

private :

	Vector3 _position;
	Color _color;
	float _intensity;
};