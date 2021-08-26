#include "DefaultProgram.h"

using namespace Engine;

DefaultProgram::DefaultProgram()
{
	_program = std::make_unique<Engine::Program>("Default");

	prepareMainUniforms();
	prepareAmbientLightUniforms();
	preparePointLightUniforms();
	prepareAnimationUniforms();
}

void DefaultProgram::use(bool state)
{
	_program->use(state);
}

void DefaultProgram::setProjection(const Matrix4x4 &matrix)
{
	*_projection = matrix;
}

void DefaultProgram::setView(const Matrix4x4 &matrix)
{
	*_view = matrix;
}

void DefaultProgram::setTransformation(const Matrix4x4 &matrix)
{
	*_transformation = matrix;
}

void DefaultProgram::setMaterialColor(const Color &color)
{
	*_materialColor = color;
}

void DefaultProgram::setNumberOfAmbientLights(int value)
{
	*_numberOfAmbientLights = value;
}

void DefaultProgram::setAmbientLight(int index, const Color &color, float intensity)
{
	*_ambientLights[index].color = color;
	*_ambientLights[index].intensity = intensity;
}

void DefaultProgram::setNumberOfPointLights(int value)
{
	*_numberOfPointLights = value;
}

void DefaultProgram::setPointLight(int index, const Vector3 &position, const Color &color, float intensity)
{
	*_pointLights[index].position = position;
	*_pointLights[index].color = color;
	*_pointLights[index].intensity = intensity;
}

void DefaultProgram::setBone(int index, const Matrix4x4 &matrix)
{
	*_bonesMesh[index] = matrix;
}

void DefaultProgram::prepareMainUniforms()
{
	_projection = _program->makeUniform<Matrix4x4>("projection");
	_view = _program->makeUniform<Matrix4x4>("view");
	_transformation = _program->makeUniform<Matrix4x4>("transformation");
	_materialColor = _program->makeUniform<Color>("material_color");
}

void DefaultProgram::prepareAmbientLightUniforms()
{
	_numberOfAmbientLights = _program->makeUniform<int>("number_of_ambient_lights");

	_program->use(true);
	*_numberOfAmbientLights = 0;
	_program->use(false);

	for (int i = 0; i < maxNumberOfAmbientLights; i++)
	{
		const auto prefix = "ambient_lights[" + std::to_string(i) + "]";

		_ambientLights[i].color = _program->makeUniform<Color>(prefix + ".color");
		_ambientLights[i].intensity = _program->makeUniform<float>(prefix + ".intensity");
	}
}

void DefaultProgram::preparePointLightUniforms()
{
	_numberOfPointLights = _program->makeUniform<int>("number_of_point_lights");

	_program->use(true);
	*_numberOfPointLights = 0;
	_program->use(false);

	for (int i = 0; i < maxNumberOfPointLights; i++)
	{
		const auto prefix = "point_lights[" + std::to_string(i) + "]";

		_pointLights[i].position = _program->makeUniform<Vector3>(prefix + ".position");
		_pointLights[i].color = _program->makeUniform<Color>(prefix + ".color");
		_pointLights[i].intensity = _program->makeUniform<float>(prefix + ".intensity");
	}
}

void DefaultProgram::prepareAnimationUniforms()
{
	for (int i = 0; i < maxBones; i++)
		_bonesMesh[i] = _program->makeUniform<Matrix4x4>("bones_mesh[" + std::to_string(i) + "]");;
}