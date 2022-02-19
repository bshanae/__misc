#pragma once

#include "engine/core/Core.h"
#include "engine/tools/Tools.h"

#include "engine/core/module/Module.h"
#include "engine/core/scene/Scene.h"
#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/std/function.h"
#include "engine/tools/debug/Debug.h"

class engine::Processor
{
public :

	Processor() = delete;
	~Processor() = delete;

	static void launchScene(const string &fileName);
	static void closeCurrentScene();

private :

	static void initialize();
	static void deinitialize();

	static bool shouldBreak();
	static void loop();

	// ENVIRONMENT

	static void processEvents();
	static void processInput();

	static inline float _timeAtLastFrame;
	static inline float _timeBetweenFrames;

	static inline float _timeAccumulator;
	static inline float _internalTime;
	static inline float _internalTimeBetweenFrames;

	static void resetTimeInfo();
	static void updateTimeInfo();
	static float tryUpdateInternalTime();

	// MODULE

	static void initializeModules();
	static void deinitializeModules();
	static void notifyModulesAboutSceneLaunching(const YAML::Node &meta);
	static void notifyModulesAboutSceneLaunched();
	static void notifyModulesAboutSceneClosing();
	static void simulatePhysics(float timeDelta);
	static void render();

	// SCENE

	static inline unique_ptr<Scene> _scene;
	static inline string _delayedSceneFileName;

	static void launchSceneNow(const string &fileName);

	static void delaySceneLaunching(const string &fileName);
	static void tryLaunchDelayedScene();

	static void traverseObjects(const function<void (Object &)> &action);
	static void traverseComponentsOfAllObjects(const function<void (Component &)> &action);
	static void traverseComponentsOfEnabledObjects(const function<void (Component &)> &action);

	static void fetchScene();
	static void invokePrepareOnComponents();
	static void invokeProcessInputOnComponents();
	static void invokeUpdateOnComponents(float timeDelta);
	static void notifyComponentsAboutEndOfFrame();
};