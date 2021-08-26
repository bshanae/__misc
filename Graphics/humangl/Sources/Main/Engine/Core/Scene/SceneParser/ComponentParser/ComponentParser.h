#pragma once

#include "YamlCpp.h"
#include "YamlCppExtensions.h"
#include "Component.h"

namespace Engine
{
	template <typename>
	class ComponentParser;
}

template <typename T>
class Engine::ComponentParser
{
public :

	static std::string getTypeName()
	{
		throw Exception("Method is not implemented");
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		throw Exception("Method is not implemented");
	}
};