#include "Processor.h"

#include "engine/core/settings/Settings.h"
#include "engine/environment/window/Window.h"
#include "engine/environment/input/Input.h"
#include "engine/environment/environment/Environment.h"
#include "engine/core/scene/object/Object.h"

using namespace engine;

void Processor::initialize()
{
	Settings::load();
	Window::initialize();
	Input::initialize();

	initializeModules();

	resetTimeInfo();
}

void Processor::deinitialize()
{
	deinitializeModules();
}

bool Processor::shouldBreak()
{
	return Window::shouldClose();
}

void Processor::loop()
{
	while (not shouldBreak())
	{
		if (_scene == nullptr)
			Debug::invokeFatalError("Processor", "Scene is not set");

		updateTimeInfo();

		processEvents();
		processInput();

		invokePrepareOnComponents();
		fetchScene();

		for (auto timeDelta = tryUpdateInternalTime(); timeDelta > 0.f; timeDelta = tryUpdateInternalTime())
			simulatePhysics(timeDelta);

		invokeProcessInputOnComponents();
		fetchScene();

		invokeUpdateOnComponents(_internalTimeBetweenFrames);
		fetchScene();

		render();

		notifyComponentsAboutEndOfFrame();

		tryLaunchDelayedScene();
	}
}