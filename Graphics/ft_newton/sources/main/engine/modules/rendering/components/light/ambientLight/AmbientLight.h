#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/color/Color.h"

class engine::rendering::AmbientLight final : public Component
{
public :

	inline static const string typeName = "ambient light";
	static void deserialize(AmbientLight &instance, const YAML::Node &node);

	AmbientLight(Object &object);
	~AmbientLight() override = default;

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

	Color _color;
	float _intensity;
};