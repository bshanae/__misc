#pragma once

#include "Component.h"

namespace Game
{
	class SceneCloser;
}

class Game::SceneCloser : public Engine::Component
{
public :

	SceneCloser() = default;
	~SceneCloser() override = default;

protected :

	void updated() override;
};