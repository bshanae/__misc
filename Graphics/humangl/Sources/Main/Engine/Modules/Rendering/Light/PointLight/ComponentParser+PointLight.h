#pragma once

#include "ComponentParser.h"
#include "PointLight.h"

template<>
class Engine::ComponentParser<Engine::PointLight>
{
public :

	static std::string getTypeName()
	{
		return "point light";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		auto light = std::make_shared<PointLight>();

		light->setPosition(node["position"].as<Vector3>());

		if (const auto colorNode = node["color"])
			light->setColor(colorNode.as<Color>());

		if (const auto intensityNode = node["intensity"])
			light->setIntensity(intensityNode.as<float>());

		return light;
	}
};