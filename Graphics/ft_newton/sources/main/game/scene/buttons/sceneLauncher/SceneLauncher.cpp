#include "SceneLauncher.h"

#include "engine/core/processor/Processor.h"
#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

using namespace game;

void SceneLauncher::deserialize(SceneLauncher &instance, const YAML::Node &node)
{
	instance._sceneName = node["scene name"].as<std::string>();
}

SceneLauncher::SceneLauncher(Object &object) : Component(object)
{}

void SceneLauncher::onClicked()
{
	Processor::closeCurrentScene();
}
