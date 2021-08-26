#pragma once

#include <memory>

namespace Engine
{
	class Scene;
}

namespace Game
{
	class Launcher;
}

class Game::Launcher
{
public :

	static void setupEngine();
	static void setupGame();
	static void launch();

private :

	static inline std::shared_ptr<Engine::Scene> _scene;

	static void registerComponentParsers();
	static void parseScene();
};