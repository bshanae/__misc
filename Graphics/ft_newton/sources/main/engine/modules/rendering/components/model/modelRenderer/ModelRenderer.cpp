#include "ModelRenderer.h"

#include "engine/environment/environment/Environment.h"
#include "engine/core/scene/Scene.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/rendering/tools/layer/Layer.h"
#include "engine/modules/rendering/module/Module.h"
#include "engine/modules/rendering/components/model/Model.h"
#include "engine/modules/rendering/components/model/material/Material.h"
#include "engine/modules/rendering/components/model/mesh/Mesh.h"
#include "engine/modules/rendering/components/light/pointLight/PointLight.h"
#include "engine/modules/rendering/components/light/ambientLight/AmbientLight.h"
#include "engine/modules/rendering/tools/shaders/litShader/LitShader.h"

using namespace engine::rendering;

ModelRenderer::ModelRenderer(Object &object) : Renderer(object, rendering::Layer::Scene), _modelFinder(*this), _cameraFinder(object.getScene())
{
}

void ModelRenderer::initializeInternally()
{
	_shader = make_unique<LitShader>();
	if (not _shader->isValid())
	{
		Debug::logError("ModelRenderer", "Shader is not valid.");
		markBad();
		return;
	}
}

void ModelRenderer::prepareInternally()
{
	for (auto *object : getObject().getScene().selectAllObjectsByTag("light"))
	{
		if (auto *ambientLight = object->trySelectComponent<AmbientLight>(); ambientLight != nullptr)
			_ambientLights.push_back(ambientLight);
		if (auto *pontLight = object->trySelectComponent<PointLight>(); pontLight != nullptr)
			_pointLights.push_back(pontLight);
	}

	_shader->use(true);

	_shader->setNumberOfAmbientLights(_ambientLights.size());
	for (int i = 0; i < _ambientLights.size(); i++)
		_shader->setAmbientLight(i, _ambientLights[i]->getColor(), _ambientLights[i]->getIntensity());

	_shader->setNumberOfPointLights(_pointLights.size());
	for (int i = 0; i < _pointLights.size(); i++)
		_shader->setPointLight(i, _pointLights[i]->getPosition(), _pointLights[i]->getColor(), _pointLights[i]->getIntensity());

	_shader->use(false);
}

void ModelRenderer::render()
{
	const auto &clusterRenderers = Module::getRenderersForCluster(getClusterId());

	auto transformations = vector<mat4>();
	for (auto *clusterRenderer : clusterRenderers)
	{
		if (clusterRenderer->isEnabled())
			transformations.push_back(clusterRenderer->getObject().selectComponent<Transformation>().getGlobalModelMatrix());
	}

	auto meshes = _modelFinder().getMeshes();
	if (meshes == nullptr)
	{
		Debug::logWarning("ModelRenderer", "Meshes are invalid.");
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

		_shader->setMaterialColor(mesh.getActualMaterial()->getColor());
		Environment::renderIndexedBuffer(mesh.getIndices().size(), transformations.size());

		mesh.bind(false);
	}

	_shader->use(false);
}

bool ModelRenderer::isClusterRenderer() const
{
	return true;
}

engine::string ModelRenderer::getClusterId() const
{
	return "model-renderer:" + _modelFinder().getFileName();
}
