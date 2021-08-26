#pragma once

#include "ComponentParser.h"
#include "DefaultRenderer.h"

template <>
class Engine::ComponentParser<Engine::DefaultRenderer>
{
public :

	static std::string getTypeName()
	{
		return "default renderer";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		return std::make_shared<DefaultRenderer>();
	}
};