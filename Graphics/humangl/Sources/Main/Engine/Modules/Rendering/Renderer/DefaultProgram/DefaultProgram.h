#pragma once

#include "Program.h"
#include "Animation.h"

namespace Engine
{
	class DefaultProgram;
}

class Engine::DefaultProgram final
{
public :

	DefaultProgram();
	~DefaultProgram() = default;

	void use(bool state);

	void setProjection(const Matrix4x4 &matrix);
	void setView(const Matrix4x4 &matrix);
	void setTransformation(const Matrix4x4 &matrix);
	void setMaterialColor(const Color &color);

	void setNumberOfAmbientLights(int value);
	void setAmbientLight(int index, const Color &color, float intensity);

	void setNumberOfPointLights(int value);
	void setPointLight(int index, const Vector3 &position, const Color &color, float intensity);

	void setBone(int index, const Matrix4x4 &matrix);

private :

	std::unique_ptr<Program> _program;

	#pragma region uniforms : main

	std::unique_ptr<Uniform<Matrix4x4>> _projection;
	std::unique_ptr<Uniform<Matrix4x4>> _view;
	std::unique_ptr<Uniform<Matrix4x4>> _transformation;
	std::unique_ptr<Uniform<Color>> _materialColor;

	void prepareMainUniforms();

	#pragma endregion

	#pragma region uniforms : light

	struct AmbientLight
	{
		std::unique_ptr<Uniform<Color>> color;
		std::unique_ptr<Uniform<float>> intensity;
	};

	struct PointLight
	{
		std::unique_ptr<Uniform<Vector3>> position;
		std::unique_ptr<Uniform<Color>> color;
		std::unique_ptr<Uniform<float>> intensity;
	};

	static constexpr int maxNumberOfAmbientLights = 10;

	std::unique_ptr<Uniform<int>> _numberOfAmbientLights;
	AmbientLight _ambientLights[maxNumberOfAmbientLights];

	static constexpr int maxNumberOfPointLights = 10;

	std::unique_ptr<Uniform<int>> _numberOfPointLights;
	PointLight _pointLights[maxNumberOfPointLights];

	void prepareAmbientLightUniforms();
	void preparePointLightUniforms();

	#pragma endregion

	#pragma region uniforms : animation

	static constexpr int maxBones = Animation::NumberOfBones;

	std::unique_ptr<Uniform<Matrix4x4>> _bonesMesh[maxBones];

	void prepareAnimationUniforms();

	#pragma endregion
};