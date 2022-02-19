#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/color/Color.h"

class engine::rendering::PointLight final : public Component
{
public :

	inline static const string typeName = "point light";
	static void deserialize(PointLight &instance, const YAML::Node &node);

	PointLight(Object &object);
	~PointLight() override = default;

	inline vec3 getPosition() const
	{
		return _position;
	}

	inline void setPosition(vec3 position)
	{
		_position = position;
	}

	inline Color getColor() const
	{
		return _color;
	}

	inline void setColor(Color color)
	{
		_color = color;
	}

	inline float getIntensity() const
	{
		return _intensity;
	}

	inline void setIntensity(float intensity)
	{
		_intensity = intensity;
	}

private :

	vec3 _position;
	Color _color;
	float _intensity;
};