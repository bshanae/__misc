#include "SceneCloser.h"

#include "Input.h"
#include "Object.h"
#include "Scene.h"

using namespace Game;

void SceneCloser::updated()
{
	if (Engine::Input::getInstance()->isPressedOrHeld(Engine::Input::Key::Escape))
		getObject()->getScene()->close();
}