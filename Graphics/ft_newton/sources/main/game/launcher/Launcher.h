#pragma once

namespace engine
{
	class Scene;
}

namespace game
{
	class Launcher;
}

class game::Launcher
{
public :

	static void setupEngine();
	static void setupGame();
	static void launch();
};