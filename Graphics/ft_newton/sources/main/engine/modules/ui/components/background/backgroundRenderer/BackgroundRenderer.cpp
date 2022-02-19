#include "BackgroundRenderer.h"

#include "engine/core/settings/Settings.h"
#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/std/array.h"
#include "engine/environment/environment/Environment.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/rendering/components/model/material/Material.h"
#include "engine/modules/rendering/components/model/mesh/Mesh.h"
#include "engine/modules/rendering/components/model/mesh/vertex/Vertex.h"
#include "engine/modules/rendering/tools/shaders/unlitShader/UnlitShader.h"
#include "engine/modules/rendering/tools/layer/Layer.h"
#include "engine/modules/ui/components/background/Background.h"

using namespace engine::ui;

BackgroundRenderer::BackgroundRenderer(Object &object) : Renderer(object, RenderingLayer::UI), _backgroundFinder(*this), _transformationFinder(*this)
{}

void BackgroundRenderer::initializeInternally()
{
	initializeShader();
	initializeMesh();
}

void BackgroundRenderer::render()
{
	_shader->use(true);
	_mesh->bind(true);

	_shader->setColor(_backgroundFinder().getColor());
	_mesh->updateTransformations({ _transformationFinder().getGlobalModelMatrix() });

	Environment::renderIndexedBuffer(_mesh->getIndices().size());

	_mesh->bind(false);
	_shader->use(false);
}

void BackgroundRenderer::initializeShader()
{
	_shader = std::make_unique<UnlitShader>();
	if (not _shader->isValid())
	{
		Debug::logError("BackgroundRenderer", "Shader is not valid.");
		markBad();
		return;
	}

	const auto width = (float)engine::Settings::getWindowSize().x;
	const auto height = (float)engine::Settings::getWindowSize().y;

	_shader->use(true);

	_shader->setProjection(ortho(0.0f, width, 0.0f, height));
	_shader->setView(mat4(1));

	_shader->use(false);
}

void BackgroundRenderer::initializeMesh()
{
	auto vertices = vector<Vertex>{
		Vertex { .position = vec3(+0.5f, +0.5f, 0.0f) },
		Vertex { .position = vec3(+0.5f, -0.5f, 0.0f) },
		Vertex { .position = vec3(-0.5f, -0.5f, 0.0f) },
		Vertex { .position = vec3(-0.5f, +0.5f, 0.0f) }
	};

	auto indices = vector<unsigned>{
		0, 3, 1,
		1, 3, 2
	};

	_material = make_shared<Material>(Color::white);
	_mesh = make_unique<Mesh>(move(vertices), move(indices), 1, _material);
}