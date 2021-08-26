#include "SceneParser.h"

using namespace Engine;

std::shared_ptr<Scene> SceneParser::parse(const std::string &fileName)
{
	try
	{
		const auto rootNode = YAML::LoadFile(directory + "/" + fileName + ".yaml");
		const auto sceneNode = rootNode["scene"];

		auto scene = std::make_shared<Scene>();

		for (const auto &objectNode : sceneNode["objects"])
			scene->addObject(ObjectParser::parse(objectNode));

		return scene;
	}
	catch (const YAML::Exception &exception)
	{
		throw Exception();
	}
}