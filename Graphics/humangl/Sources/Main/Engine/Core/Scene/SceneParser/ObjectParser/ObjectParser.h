#pragma once

#include "YamlCpp.h"
#include "Object.h"
#include "ComponentParser.h"

namespace Engine
{
	class ObjectParser;
}

class Engine::ObjectParser
{
public :

	ObjectParser() = delete;

	static std::shared_ptr<Object> parse(const YAML::Node &objectNode);

	template <typename T>
	static void registerComponentParser()
	{
		auto componentParser = ComponentParser<T>();
		_componentParsingFunctors[componentParser.getTypeName()] = &componentParser.parse;
	}

private :

	using ComponentParsingFunctor = std::function<std::shared_ptr<Component>(const YAML::Node &node)>;
	static inline std::map<std::string, ComponentParsingFunctor> _componentParsingFunctors;

	static std::shared_ptr<Component> parseComponent(const YAML::Node &node);
	static ComponentParsingFunctor findComponentParsingFunction(const std::string &type);
};
