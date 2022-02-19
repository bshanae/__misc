#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/environment/shader/Shader.h"
#include "engine/environment/shader/uniform/Uniform.h"

class engine::rendering::UnlitShader : public Shader
{
public :

	UnlitShader();
	~UnlitShader() override = default;

	inline void setProjection(const mat4 &value)
	{
		_projection << value;
	}

	inline void setView(const mat4 &value)
	{
		_view << value;
	}

	inline void setColor(const Color &value)
	{
		_color << value;
	}

private :

	Uniform<mat4> _projection;
	Uniform<mat4> _view;
	Uniform<Color> _color;
};