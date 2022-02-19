#include "Processor.h"

#include "engine/core/scene/serialization/Serialization.h"
#include "engine/core/scene/object/Object.h"
#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/debug/Debug.h"

using namespace engine;

void Processor::launchScene(const string &fileName)
{
	if (_scene == nullptr)
	{
		initialize();

		// First call : launch scene and start loop
		launchSceneNow(fileName);
		loop();

		deinitialize();
	}
	else
	{
		// Not first call : close current scene at end frame, loop new one
		delaySceneLaunching(fileName);
	}
}

void Processor::closeCurrentScene()
{
	notifyModulesAboutSceneClosing();

	_scene->close();
	_scene.release();
}

void Processor::launchSceneNow(const string &fileName)
{
	Debug::assume(_scene == nullptr, "Previous scene is not destroyed");

	auto [scene, metaNode] = serialization::deserializeScene(fileName);
	_scene = move(scene);

	notifyModulesAboutSceneLaunching(metaNode);
	_scene->launch();
	notifyModulesAboutSceneLaunched();
}

void Processor::delaySceneLaunching(const string &fileName)
{
	_delayedSceneFileName = fileName;
}

void Processor::tryLaunchDelayedScene()
{
	if (_delayedSceneFileName != "")
	{
		resetTimeInfo();

		closeCurrentScene();

		launchSceneNow(_delayedSceneFileName);
		_delayedSceneFileName = "";
	}
}

void Processor::traverseObjects(const function<void (Object &)> &action)
{
	_scene->traverseObjects(action);
}

void Processor::traverseComponentsOfAllObjects(const function<void (Component &)> &action)
{
	_scene->traverseObjects([&action](Object &object){ object.traverseComponents(action); });
}

void Processor::traverseComponentsOfEnabledObjects(const function<void (Component &)> &action)
{
	_scene->traverseObjects(
		[&action](Object &object)
		{
			if (object.isEnabled())
				object.traverseComponents(action);
		}
	);
}

void Processor::fetchScene()
{
	_scene->fetch();
}

void Processor::invokePrepareOnComponents()
{
	traverseComponentsOfEnabledObjects(
		[](Component &component)
		{
			if (not component.isMature() and component.isEnabled())
				component.prepare();
		}
	);
}

void Processor::invokeProcessInputOnComponents()
{
	traverseComponentsOfAllObjects(
		[](Component &component)
		{
			if (component.isMature())
				component.processInput();
		}
	);
}

void Processor::invokeUpdateOnComponents(float timeDelta)
{
	_scene->updating.invoke();

	traverseComponentsOfEnabledObjects(
		[timeDelta](Component &component)
		{
			if (component.isMature() and component.isEnabled())
				component.update(timeDelta);
		}
	);

	_scene->updated.invoke();
}

void Processor::notifyComponentsAboutEndOfFrame()
{
	traverseComponentsOfAllObjects([](Component &component){ component.notifyAboutEndOfFrame(); });
}