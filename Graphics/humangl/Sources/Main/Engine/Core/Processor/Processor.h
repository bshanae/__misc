#pragma once

#include <vector>
#include <Singleton.h>

namespace Engine
{
	class Scene;
	class Component;
	class Processor;
}

class Engine::Processor final : public Singleton<Engine::Processor>
{
public :

	void launchScene(const std::shared_ptr<Scene> &scene);

private :

	std::shared_ptr<Scene> _scene;

	bool shouldBreak();

	// Environment

	static void processEvents();
	static void processInput();
	static void startRendering();
	static void finishRendering();

	// Scene

	void prepareObjects();
	void renderObjects();
	void updateObjects();
	void notifyObjectsAboutEndOfFrame();
};