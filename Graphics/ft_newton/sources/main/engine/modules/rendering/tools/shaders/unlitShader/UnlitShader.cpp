#include "UnlitShader.h"

using namespace engine::rendering;

UnlitShader::UnlitShader() : Shader("unlit")
{
	if (not isValid())
		return;

	_projection = makeUniform<mat4>("projection");
	_view = makeUniform<mat4>("view");
	_color = makeUniform<Color>("color");
}