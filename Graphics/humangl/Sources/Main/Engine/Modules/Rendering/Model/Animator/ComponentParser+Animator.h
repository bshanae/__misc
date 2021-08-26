#pragma once

#include "ComponentParser.h"
#include "Animator.h"

template <>
class Engine::ComponentParser<Engine::Animator>
{
public :

	static std::string getTypeName()
	{
		return "animator";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		return std::make_shared<Animator>();
	}
};