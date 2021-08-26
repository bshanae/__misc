#pragma once

#include "ComponentParser.h"
#include "SceneCloser.h"

template<>
class Engine::ComponentParser<Game::SceneCloser>
{
public :

	static std::string getTypeName()
	{
		return "scene closer";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		return std::make_shared<Game::SceneCloser>();
	}
};