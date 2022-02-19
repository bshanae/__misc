#include "LabelShader.h"

using namespace engine::ui;

LabelShader::LabelShader() : Shader("text")
{
	_projection = makeUniform<mat4>("projection");
	_transformation = makeUniform<mat4>("transformation");
	_textColor = makeUniform<Color>("text_color");
}