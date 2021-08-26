#pragma once

#include <vector>

#include "Component.h"
#include "DefaultProgram.h"

namespace Engine
{
	class DefaultCamera;
	class AmbientLight;
	class PointLight;
	class Model;
	class Animator;
	class DefaultProgram;
	class DefaultRenderer;
}

class Engine::DefaultRenderer : public Engine::Component
{
public :

	DefaultRenderer() = default;
	~DefaultRenderer() override = default;

	void prepared() override;
	void rendered() override;

private :

	std::unique_ptr<DefaultProgram> _program;

	std::shared_ptr<DefaultCamera> _camera;
	std::vector<std::shared_ptr<AmbientLight>> _ambientLights;
	std::vector<std::shared_ptr<PointLight>> _pointLights;

	std::shared_ptr<Model> _model;
	std::shared_ptr<Animator> _animator;
};