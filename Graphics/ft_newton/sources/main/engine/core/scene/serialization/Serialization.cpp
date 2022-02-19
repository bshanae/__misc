#include "Serialization.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/serialization/Serialization.h"

using namespace engine::serialization;

DeserializedScene engine::serialization::deserializeScene(const string &fileName)
{
	static const auto directory = string("resources/scenes");

	auto result = DeserializedScene();

	try
	{
		const auto rootNode = YAML::LoadFile(directory + "/" + fileName + ".yaml");
		const auto sceneNode = rootNode["scene"];

		result.scene = make_unique<Scene>(fileName);
		result.metaNode = sceneNode["meta"];

		for (const auto &objectNode : sceneNode["objects"])
			deserializeObject(*result.scene, objectNode);

		return result;
	}
	catch (const YAML::Exception &exception)
	{
		Debug::invokeFatalError("Can't parse scene : " + string(exception.what()));
		throw nullptr;
	}
}