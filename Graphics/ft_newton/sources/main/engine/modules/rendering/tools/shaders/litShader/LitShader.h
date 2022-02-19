#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/environment/shader/Shader.h"
#include "engine/environment/shader/uniform/Uniform.h"

class engine::rendering::LitShader final : public Shader
{
public :

	LitShader();
	~LitShader() override = default;

	inline void setProjection(const mat4 &matrix)
	{
		_projection << matrix;
	}

	inline void setView(const mat4 &matrix)
	{
		_view << matrix;
	}

	inline void setMaterialColor(const Color &color)
	{
		_materialColor << color;
	}

	void setNumberOfAmbientLights(int value);
	void setAmbientLight(int index, const Color &color, float intensity);

	void setNumberOfPointLights(int value);
	void setPointLight(int index, const vec3 &position, const Color &color, float intensity);

private :

	// MAIN

	Uniform<mat4> _projection;
	Uniform<mat4> _view;
	Uniform<Color> _materialColor;

	void prepareMainUniforms();

	// LIGHT

	struct AmbientLight
	{
		Uniform<Color> color;
		Uniform<float> intensity;
	};

	struct PointLight
	{
		Uniform<vec3> position;
		Uniform<Color> color;
		Uniform<float> intensity;
	};

	static constexpr int maxNumberOfAmbientLights = 10;

	Uniform<int> _numberOfAmbientLights;
	AmbientLight _ambientLights[maxNumberOfAmbientLights];

	static constexpr int maxNumberOfPointLights = 10;

	Uniform<int> _numberOfPointLights;
	PointLight _pointLights[maxNumberOfPointLights];

	void prepareAmbientLightUniforms();
	void preparePointLightUniforms();
};