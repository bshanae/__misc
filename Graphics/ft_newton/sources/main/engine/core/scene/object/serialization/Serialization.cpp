#include "Serialization.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/prototype/Prototype.h"
#include "engine/core/scene/object/prototype/prototypeStorage/PrototypeStorage.h"
#include "engine/tools/debug/Debug.h"


namespace engine::serialization
{
	void deserializeObject(Scene &scene, Object *parent, const YAML::Node &node);
	void deserializeComponent(Object &object, const YAML::Node &node);
}

using namespace engine::serialization;

void engine::serialization::deserializeObject(Scene &scene, const YAML::Node &node)
{
	return deserializeObject(scene, nullptr, node);
}

void engine::serialization::deserializeObject(Scene &scene, Object *parent, const YAML::Node &node)
{
	try
	{
		const auto prototype = node["prototype"].as<string>("");
		const auto finalNode = prototype != "" ? PrototypeStorage::get(prototype).merge(node) : (YAML::Node) node;

		const auto name = finalNode["name"].as<string>();
		const auto tag = finalNode["tag"].as<string>("");

		auto &object = parent != nullptr ? parent->addChild(name, tag) : scene.addObject(name, tag);

		for (const auto &childNode: finalNode["children"])
			deserializeObject(scene, &object, childNode);

		for (const auto &componentNode: finalNode["components"])
			deserializeComponent(object, componentNode);
	}
	catch (const YAML::Exception &exception)
	{
		Debug::invokeFatalError("Can't deserialize object : " + string(exception.what()));
	}
}

void engine::serialization::deserializeComponent(Object &object, const YAML::Node &node)
{
	try
	{
		const auto type = node["type"].as<string>();

		const auto iterator = componentDeserializers.find(type);
		if (iterator == componentDeserializers.end())
			throw Exception(string() + "Deserializer for type '" + type + "' not found");

		iterator->second(object, node);
	}
	catch (const YAML::Exception &exception)
	{
		Debug::invokeFatalError("Can't parse a component: " + exception.msg);
	}
}