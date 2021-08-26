#include "Processor.h"

#include "Environment.h"
#include "Window.h"
#include "Scene.h"
#include "Object.h"

using namespace Engine;

void Processor::launchScene(const std::shared_ptr<Scene> &scene)
{
	_scene = scene;

	while (true)
	{
		if (shouldBreak())
			break;

		processEvents();
		processInput();

		prepareObjects();

		startRendering();
		renderObjects();
		finishRendering();

		updateObjects();

		notifyObjectsAboutEndOfFrame();
	}
}

bool Processor::shouldBreak()
{
	return Window::getInstance()->shouldClose() or _scene->isClosed();
}