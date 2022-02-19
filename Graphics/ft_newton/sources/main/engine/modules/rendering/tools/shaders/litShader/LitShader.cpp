#include "LitShader.h"

using namespace engine::rendering;

LitShader::LitShader() : Shader("lit")
{
	if (not isValid())
		return;

	prepareMainUniforms();
	prepareAmbientLightUniforms();
	preparePointLightUniforms();
}

void LitShader::setNumberOfAmbientLights(int value)
{
	_numberOfAmbientLights << value;
}

void LitShader::setAmbientLight(int index, const Color &color, float intensity)
{
	_ambientLights[index].color << color;
	_ambientLights[index].intensity << intensity;
}

void LitShader::setNumberOfPointLights(int value)
{
	_numberOfPointLights << value;
}

void LitShader::setPointLight(int index, const vec3 &position, const Color &color, float intensity)
{
	_pointLights[index].position << position;
	_pointLights[index].color << color;
	_pointLights[index].intensity << intensity;
}

void LitShader::prepareMainUniforms()
{
	_projection = makeUniform<mat4>("projection");
	_view = makeUniform<mat4>("view");
	_materialColor = makeUniform<Color>("material_color");
}

void LitShader::prepareAmbientLightUniforms()
{
	_numberOfAmbientLights = makeUniform<int>("number_of_ambient_lights");

	use(true);
	_numberOfAmbientLights << 0;
	use(false);

	for (int i = 0; i < maxNumberOfAmbientLights; i++)
	{
		const auto prefix = "ambient_lights[" + to_string(i) + "]";

		_ambientLights[i].color = makeUniform<Color>(prefix + ".color");
		_ambientLights[i].intensity = makeUniform<float>(prefix + ".intensity");
	}
}

void LitShader::preparePointLightUniforms()
{
	_numberOfPointLights = makeUniform<int>("number_of_point_lights");

	use(true);
	_numberOfPointLights << 0;
	use(false);

	for (int i = 0; i < maxNumberOfPointLights; i++)
	{
		const auto prefix = "point_lights[" + to_string(i) + "]";

		_pointLights[i].position = makeUniform<vec3>(prefix + ".position");
		_pointLights[i].color = makeUniform<Color>(prefix + ".color");
		_pointLights[i].intensity = makeUniform<float>(prefix + ".intensity");
	}
}