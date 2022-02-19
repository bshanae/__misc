#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/core/module/Module.h"
#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/std/type.h"
#include "engine/tools/templates/eventSystem/listener/Listener.h"
#include "engine/modules/rendering/tools/layer/Layer.h"

class engine::rendering::Module : public engine::Module<engine::rendering::Module>, public Listener
{
public :

	Module();
	~Module() override = default;

	static inline unsigned getNumberOfDrawCalls()
	{
		return getInstance()._drawCallsInLastFrame;
	}

	static const vector<Renderer *> &getRenderersForCluster(const string &clusterId);

	static void render();

protected :

	void initializeInternally() override;

	void onSceneLaunchingInternal(const YAML::Node &metaNode) override;
	void onSceneLaunchedInternal() override;
	void onSceneClosingInternal() override;

private :

	map<rendering::Layer, vector<Renderer *>> _layers;
	map<string, vector<Renderer *>> _clusters;

	unsigned _drawCallsInLastFrame;

	void processComponentsInScene(Scene &scene);
	void processComponent(Component &component);
};
