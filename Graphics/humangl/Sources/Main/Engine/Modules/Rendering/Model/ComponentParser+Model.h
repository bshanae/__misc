#pragma once

#include "ComponentParser.h"
#include "Model.h"

template <>
class Engine::ComponentParser<Engine::Model>
{
public :

	static std::string getTypeName()
	{
		return "model";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		auto model = std::make_shared<Model>();
		model->load(node["source"].as<std::string>());

		return model;
	}
};