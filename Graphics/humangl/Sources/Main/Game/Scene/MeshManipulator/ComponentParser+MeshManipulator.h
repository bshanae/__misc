#pragma once

#include "ComponentParser.h"
#include "MeshManipulator.h"

template<>
class Engine::ComponentParser<Game::MeshManipulator>
{
public :

	static std::string getTypeName()
	{
		return "mesh manipulator";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		auto meshManipulator = std::make_shared<Game::MeshManipulator>();

		meshManipulator->setScalingSpeed(node["scaling speed"].as<float>());

		return meshManipulator;
	}
};