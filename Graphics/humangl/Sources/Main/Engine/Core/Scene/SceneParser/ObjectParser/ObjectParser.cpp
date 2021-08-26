#include "ObjectParser.h"

using namespace Engine;

std::shared_ptr<Object> ObjectParser::parse(const YAML::Node &objectNode)
{
	auto object = std::make_shared<Object>();

	try
	{
		object->setName(objectNode["name"].as<std::string>());

		for (const auto &componentNode : objectNode["components"])
			object->addComponent(parseComponent(componentNode));

		return object;
	}
	catch (std::exception &exception)
	{
		throw Exception("Can't parse object : " + std::string(exception.what()));
	}
	catch (...)
	{
		throw Exception("Can't parse object");
	}
}

std::shared_ptr<Component> ObjectParser::parseComponent(const YAML::Node &node)
{
	const auto type = node["type"].as<std::string>();
	return findComponentParsingFunction(type)(node);
}

ObjectParser::ComponentParsingFunctor ObjectParser::findComponentParsingFunction(const std::string &type)
{
	if (const auto iterator = _componentParsingFunctors.find(type); iterator != _componentParsingFunctors.end())
		return iterator->second;
	else
		throw Exception("Component parser for type'" + type + "' not found");
}