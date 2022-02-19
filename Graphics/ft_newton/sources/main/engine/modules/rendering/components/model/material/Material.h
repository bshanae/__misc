#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/color/Color.h"

class engine::rendering::Material final
{
public :

	Material() = default;

	Material(const Color &color) : _color(color)
	{}

	~Material() = default;

	inline Color getColor() const
	{
		return _color;
	}

	inline void setColor(const Color &color)
	{
		_color = color;
	}

private :

	Color _color;
};