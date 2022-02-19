#include "SceneResetter.h"

#include "engine/core/processor/Processor.h"
#include "engine/core/scene/object/Object.h"

using namespace game;

SceneResetter::SceneResetter(Object &object) : Component(object)
{}

void SceneResetter::onClicked()
{
	Processor::launchScene(getObject().getScene().getFileName());
}
