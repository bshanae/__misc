#include "SceneCloser.h"

#include "engine/core/processor/Processor.h"
#include "engine/core/scene/object/Object.h"

using namespace game;

SceneCloser::SceneCloser(Object &object) : Component(object)
{}

void SceneCloser::onClicked()
{
	Processor::closeCurrentScene();
}
