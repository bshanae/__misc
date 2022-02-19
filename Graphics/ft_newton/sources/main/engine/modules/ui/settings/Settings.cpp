#include "Settings.h"

#include "engine/tools/debug/Debug.h"
#include "engine/core/settings/Settings.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/modules/ui/tools/font/fontLibrary/FontLibrary.h"

using namespace engine::ui;

void Settings::load()
{
	try
	{
		const auto uiNode = YAML::LoadFile(engine::Settings::source)["ui"];

		for (const auto &font : uiNode["fonts"])
			FontLibrary::loadFont(font["name"].as<string>(), font["height"].as<float>());
	}
	catch (const YAML::Exception &exception)
	{
		Debug::invokeFatalError("ui::Settings", "Can't parse settings");
	}
}