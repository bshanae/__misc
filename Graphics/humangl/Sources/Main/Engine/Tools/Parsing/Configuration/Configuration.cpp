#include "Configuration.h"

using namespace Engine;

Configuration::Configuration(const std::string &configurationName)
{
	try
	{
		_root = YAML::LoadFile(directory + "/" + configurationName + ".yaml");
	}
	catch (const YAML::BadFile &exception)
	{
		throw FileNotFound();
	}
}