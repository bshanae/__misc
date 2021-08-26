#pragma once

#include "YamlCpp.h"
#include "Scene.h"
#include "ObjectParser.h"

namespace Engine
{
	class SceneParser;
}

class Engine::SceneParser
{
public :

	SceneParser() = delete;

	static std::shared_ptr<Scene> parse(const std::string &fileName);

private :

	static const inline std::string directory = "Resources/Scenes";
};