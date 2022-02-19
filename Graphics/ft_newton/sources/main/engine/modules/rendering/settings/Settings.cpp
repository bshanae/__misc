#include "Settings.h"

#include "engine/tools/debug/Debug.h"
#include "engine/core/settings/Settings.h"

using namespace engine::rendering;

void Settings::loadSettings()
{
	try
	{
		const auto root = YAML::LoadFile(engine::Settings::source)["rendering"];

		_backgroundColor = root["background color"].as<Color>();
	}
	catch (const YAML::Exception &exception)
	{
		Debug::invokeFatalError("rendering::Settings", "Can't parse settings");
	}
}

void Settings::loadSceneMeta(const YAML::Node &metaNode)
{
	try
	{
		_modelsNumberOfInstances.clear();

		for (const auto &modelNode : metaNode["models"])
			_modelsNumberOfInstances[modelNode["file"].as<string>()] = modelNode["number of instances"].as<unsigned>();
	}
	catch (const YAML::Exception &exception)
	{
		Debug::invokeFatalError("rendering::Settings", "Can't parse scene meta");
	}
}