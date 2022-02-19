#include "DebugModelRenderer.h"

#include "engine/environment/environment/Environment.h"
#include "engine/core/scene/Scene.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/rendering/tools/layer/Layer.h"
#include "engine/modules/rendering/module/Module.h"
#include "engine/modules/rendering/components/model/Model.h"
#include "engine/modules/rendering/components/model/material/Material.h"
#include "engine/modules/rendering/components/model/mesh/Mesh.h"
#include "engine/modules/rendering/tools/shaders/unlitShader/UnlitShader.h"

using namespace test;

DebugModelRenderer::DebugModelRenderer(Object &object) : DebugModelRenderer(object, Color::white)
{
}

DebugModelRenderer::DebugModelRenderer(Object &object, const Color &color) :
	Renderer(object, RenderingLayer::Scene), _modelFinder(*this), _cameraFinder(object.getScene()), _color(color)
{
}

void DebugModelRenderer::initializeInternally()
{
	_shader = std::make_unique<UnlitShader>();
	if (not _shader->isValid())
	{
		Debug::logError("DebugModelRenderer", "Shader is not valid.");
		markBad();
		return;
	}
}

void DebugModelRenderer::prepareInternally()
{
	_clusterId = "debug-model-renderer:" + _modelFinder().getFileName() + ":" + std::to_string(hash(_color));
}

void DebugModelRenderer::render()
{
	const auto &clusterRenderers = RenderingModule::getRenderersForCluster(getClusterId());

	auto transformations = std::vector<mat4>();
	for (auto *clusterRenderer : clusterRenderers)
	{
		if (clusterRenderer->isEnabled())
			transformations.push_back(clusterRenderer->getObject().selectComponent<Transformation>().getLocalModelMatrix());
	}

	auto meshes = _modelFinder().getMeshes();
	if (meshes == nullptr)
	{
		Debug::logWarning("DebugModelRenderer", "Meshes are invalid.");
		markBad();
		return;
	}

	_shader->use(true);

	_shader->setProjection(_cameraFinder().getProjectionMatrix());
	_shader->setView(_cameraFinder().getViewMatrix());

	for (auto &mesh : *meshes)
	{
		mesh.bind(true);

		mesh.updateTransformations(transformations);

		_shader->setColor(_color);
		Environment::renderIndexedBuffer(mesh.getIndices().size(), transformations.size());

		mesh.bind(false);
	}

	_shader->use(false);
}

bool DebugModelRenderer::isClusterRenderer() const
{
	return true;
}

engine::string DebugModelRenderer::getClusterId() const
{
	return _clusterId;
}