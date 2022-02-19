#include "Launcher.h"

#include "engine/core/processor/Processor.h"
#include "engine/core/scene/object/serialization/Serialization.h"
#include "game/scene/sceneCloser/ComponentSerializer+SceneCloser.h"
#include "engine/modules/base/module/Module.h"
#include "engine/modules/rendering/module/Module.h"
#include "engine/modules/physics/module/Module.h"

using namespace game;

void Launcher::setupEngine()
{
	engine::Processor::loadSettings();
	engine::Processor::initialize();

	engine::Processor::registerModule<engine::BaseModule>();
	engine::Processor::registerModule<engine::RenderingModule>();
	engine::Processor::registerModule<engine::PhysicalModule>();
}

void Launcher::setupGame()
{
	engine::ObjectSerializer::registerComponentSerializer<game::SceneCloser>();
}

void Launcher::launch()
{
	engine::Processor::launchScene("box-test");
}