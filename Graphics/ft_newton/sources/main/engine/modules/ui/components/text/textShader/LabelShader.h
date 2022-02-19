#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/environment/shader/Shader.h"
#include "engine/environment/shader/uniform/Uniform.h"
#include "engine/tools/color/Color.h"

class engine::ui::LabelShader : public Shader
{
public :

	LabelShader();
	~LabelShader() override = default;

	inline void setProjection(const mat4 &matrix)
	{
		_projection << matrix;
	}

	inline void setTransformation(const mat4 &matrix)
	{
		_transformation << matrix;
	}

	inline void setTextColor(const Color &vector)
	{
		_textColor << vector;
	}

private :

	Uniform<mat4> _projection;
	Uniform<mat4> _transformation;
	Uniform<Color> _textColor;
};