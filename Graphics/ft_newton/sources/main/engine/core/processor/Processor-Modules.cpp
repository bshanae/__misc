#include "Processor.h"

#include "engine/modules/base/module/Module.h"
#include "engine/modules/rendering/module/Module.h"
#include "engine/modules/physics/module/Module.h"
#include "engine/modules/ui/module/Module.h"

using namespace engine;

void Processor::initializeModules()
{
	base::Module::initialize();
	rendering::Module::initialize();
	physics::Module::initialize();
	ui::Module::initialize();
}

void Processor::deinitializeModules()
{
	base::Module::deinitialize();
	rendering::Module::deinitialize();
	physics::Module::deinitialize();
	ui::Module::deinitialize();
}

void Processor::notifyModulesAboutSceneLaunching(const YAML::Node &metaNode)
{
	base::Module::onSceneLaunching(*_scene, metaNode);
	rendering::Module::onSceneLaunching(*_scene, metaNode);
	physics::Module::onSceneLaunching(*_scene, metaNode);
	ui::Module::onSceneLaunching(*_scene, metaNode);
}

void Processor::notifyModulesAboutSceneLaunched()
{
	base::Module::onSceneLaunched();
	rendering::Module::onSceneLaunched();
	physics::Module::onSceneLaunched();
	ui::Module::onSceneLaunched();
}

void Processor::notifyModulesAboutSceneClosing()
{
	base::Module::onSceneClosing();
	rendering::Module::onSceneClosing();
	physics::Module::onSceneClosing();
	ui::Module::onSceneClosing();
}

void Processor::simulatePhysics(float timeDelta)
{
	physics::Module::updateSimulation(timeDelta);
}

void Processor::render()
{
	rendering::Module::render();
}