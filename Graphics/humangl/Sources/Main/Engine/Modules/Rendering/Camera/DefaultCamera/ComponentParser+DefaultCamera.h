#pragma once

#include "ComponentParser.h"
#include "DefaultCamera.h"

template <>
class Engine::ComponentParser<Engine::DefaultCamera>
{
public :

	static std::string getTypeName()
	{
		return "default camera";
	}

	static std::shared_ptr<Component> parse(const YAML::Node &node)
	{
		auto camera = std::make_shared<DefaultCamera>();

		camera->setPosition(node["position"].as<Vector3>());

		camera->setRotationSpeed(node["rotation speed"].as<float>());
		camera->setMovementSpeed(node["movement speed"].as<float>());

		camera->setFov(node["fov"].as<float>());

		camera->setYaw(node["yaw"].as<float>());
		camera->setPitch(node["pitch"].as<float>());

		if (const auto pitchNode = node["near place"])
			camera->setNearPlane(pitchNode.as<float>());

		if (const auto pitchNode = node["far place"])
			camera->setFarPlane(pitchNode.as<float>());

		camera->reload();

		return camera;
	}
};