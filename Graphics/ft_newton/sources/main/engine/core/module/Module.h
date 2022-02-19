#pragma once

#include "engine/core/Core.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/std/io.h"

template <typename TFinal>
class engine::Module
{
public :

	virtual ~Module() = default;

	static void initialize()
	{
		_instance = make_unique<TFinal>();
		getGenericInstance().initializeInternally();
	}

	static void deinitialize()
	{
		_instance.release();
	}

	static void onSceneLaunching(Scene &scene, const YAML::Node &metaNode)
	{
		_scene = &scene;
		getGenericInstance().onSceneLaunchingInternal(metaNode);
	}

	static void onSceneLaunched()
	{
		getGenericInstance().onSceneLaunchedInternal();
	}

	static void onSceneClosing()
	{
		_scene = nullptr;
		getGenericInstance().onSceneClosingInternal();
	}

protected :

	static inline TFinal &getInstance()
	{
		return *_instance;
	}

	inline Scene &getScene() const
	{
		return *_scene;
	}

	virtual void initializeInternally()
	{}

	virtual void onSceneLaunchingInternal(const YAML::Node &metaNode)
	{}

	virtual void onSceneLaunchedInternal()
	{}

	virtual void onSceneClosingInternal()
	{}

private :

	static inline unique_ptr<TFinal> _instance;
	static inline Scene *_scene;

	static inline Module<TFinal> &getGenericInstance()
	{
		return static_cast<Module<TFinal> &>(*_instance);
	}
};