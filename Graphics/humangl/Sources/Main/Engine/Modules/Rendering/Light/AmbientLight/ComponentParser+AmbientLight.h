#pragma once

#include "ComponentParser.h"
#include "AmbientLight.h"

template<>
class Engine::ComponentParser<Engine::AmbientLight>
{
public :

	static std::string getTypeName()
	{
		return "ambient light";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		auto light = std::make_shared<AmbientLight>();

		if (const auto colorNode = node["color"])
			light->setColor(colorNode.as<Color>());

		if (const auto intensityNode = node["intensity"])
			light->setIntensity(intensityNode.as<float>());

		return light;
	}
};