#pragma once

#include "ComponentParser.h"
#include "MeshSelector.h"

template<>
class Engine::ComponentParser<Game::MeshSelector>
{
public :

	static std::string getTypeName()
	{
		return "mesh selector";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		return std::make_shared<Game::MeshSelector>();
	}
};