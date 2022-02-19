#include "Settings.h"

#include "engine/tools/constants/Constants.h"
#include "engine/tools/debug/Debug.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

using namespace engine;

void Settings::load()
{
	try
	{
		const auto root = YAML::LoadFile(source);

		const auto windowNode = root["window"];
		_windowSize = windowNode["size"].as<uvec2>();
		_windowTitle = windowNode["title"].as<string>();

		const auto timeNode = root["time"];
		_timeScale = timeNode["scale"].as<float>();
		_fixedTimeStep = timeNode["fixed step"].as<float>();
	}
	catch (const YAML::Exception &exception)
	{
		Debug::invokeFatalError("Settings", "Can't parse settings");
	}
}