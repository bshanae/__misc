#include "Module.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/serialization/Serialization.h"
#include "engine/environment/environment/Environment.h"
#include "engine/environment/window/Window.h"
#include "engine/modules/rendering/settings/Settings.h"
#include "engine/modules/rendering/components/renderer/Renderer.h"
#include "engine/modules/rendering/components/camera/freeCamera/FreeCamera.h"
#include "engine/modules/rendering/components/light/ambientLight/AmbientLight.h"
#include "engine/modules/rendering/components/light/pointLight/PointLight.h"
#include "engine/modules/rendering/components/model/Model.h"
#include "engine/modules/rendering/components/model/modelStorage/ModelStorage.h"
#include "engine/modules/rendering/components/model/modelRenderer/ModelRenderer.h"

using namespace engine::rendering;

Module::Module() : _drawCallsInLastFrame(0)
{}

const engine::vector<Renderer *> &Module::getRenderersForCluster(const string &clusterId)
{
	if (auto iterator = getInstance()._clusters.find(clusterId); iterator != getInstance()._clusters.end())
	{
		return iterator->second;
	}
	else
	{
		Debug::invokeFatalError("rendering::Module", "Cluster with id '" + clusterId + "' not found");
		throw nullptr;
	}
}

void Module::render()
{
	Window::clearColor(rendering::Settings::getBackgroundColor());

	getInstance()._drawCallsInLastFrame = 0;

	auto renderedClusterIds = set<string>();
	for (const auto [layer, renderers] : getInstance()._layers)
	{
		Window::clearDepth();

		for (const auto renderer: renderers)
		{
			if (not renderer->isMature() or renderer->isDisabled())
				continue;

			if (renderer->isClusterRenderer() and renderedClusterIds.find(renderer->getClusterId()) != renderedClusterIds.end())
				continue;

			Environment::setRenderingOptions(renderer->getDesiredRenderingOptions());

			renderer->render();
			getInstance()._drawCallsInLastFrame++;

			if (renderer->isClusterRenderer())
				renderedClusterIds.insert(renderer->getClusterId());
		}
	}

	Window::swapBuffers();
}

void Module::initializeInternally()
{
	serialization::registerComponent<FreeCamera>();
	serialization::registerComponent<Model>();
	serialization::registerComponent<ModelRenderer>();
	serialization::registerComponent<AmbientLight>();
	serialization::registerComponent<PointLight>();
}

void Module::onSceneLaunchingInternal(const YAML::Node &metaNode)
{
	Settings::loadSettings();
	Settings::loadSceneMeta(metaNode);
}

void Module::onSceneLaunchedInternal()
{
	processComponentsInScene(getScene());
	subscribe(getScene().componentAddedToObject, [this](Object &object, Component &component){ processComponent(component); });
}

void Module::onSceneClosingInternal()
{
	ModelStorage::clear();
}

void Module::processComponentsInScene(Scene &scene)
{
	const auto processComponent = [this](Component &component){ this->processComponent(component); };
	const auto processObject = [&processComponent](Object &object){ object.traverseComponents(processComponent); };

	scene.traverseObjects(processObject);
}

void Module::processComponent(Component &component)
{
	if (auto *renderer = dynamic_cast<Renderer *>(&component); renderer != nullptr)
	{
		_layers[renderer->getLayer()].push_back(renderer);

		if (renderer->isClusterRenderer())
		{
			subscribe(
				renderer->prepared,
				[this, renderer]()
				{
					_clusters[renderer->getClusterId()].push_back(renderer);
					unsubscribe(renderer->prepared);
				}
			);
		}
	}
}