#include "Prototype.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/set.h"
#include "engine/tools/debug/Debug.h"

using namespace engine;

Prototype::Prototype(const YAML::Node &node) : _node(node)
{}

YAML::Node Prototype::merge(const YAML::Node &patch) const
{
	try
	{
		auto result = YAML::Node(YAML::NodeType::Map);

		mergeObjectAttributes(result, _node, patch);
		mergeComponents(result, _node, patch);

		return result;
	}
	catch (YAML::Exception exception)
	{
		Debug::logError("Prototype", "Can't merge prototype and patch : " + exception.msg);
		return _node;
	}
}

void Prototype::mergeObjectAttributes(YAML::Node &target, const YAML::Node &base, const YAML::Node &patch)
{
	const auto insertIfAttribute = [&target](const string &key, const YAML::Node &value)
	{
		if (key != "components")
			target[key] = value;
	};

	for (auto iterator : base)
		insertIfAttribute(iterator.first.Scalar(), iterator.second);

	for (auto iterator : patch)
		insertIfAttribute(iterator.first.Scalar(), iterator.second);
}

void Prototype::mergeComponents(YAML::Node &target, const YAML::Node &base, const YAML::Node &patch)
{
	target["components"] = YAML::Node(YAML::NodeType::Sequence);
	auto targetComponentsNode = target["components"];

	auto targetComponentsMeta = set<string>();
	auto baseComponentsMeta = collectComponentsMeta(base["components"]);
	auto patchComponentsMeta = collectComponentsMeta(patch["components"]);

	for (auto [type, patchComponentNode] : patchComponentsMeta)
	{
		targetComponentsMeta.insert(type);
		targetComponentsNode.push_back(engine::merge(baseComponentsMeta[type], patchComponentNode));
	}

	for (auto [type, baseComponentNode] : baseComponentsMeta)
	{
		if (targetComponentsMeta.find(type) == targetComponentsMeta.end())
			targetComponentsNode.push_back(YAML::Node(baseComponentNode));
	}
}

map<string, YAML::Node> Prototype::collectComponentsMeta(const YAML::Node &componentList)
{
	auto result = map<string, YAML::Node>();

	for (auto iterator : componentList)
		result[iterator["type"].as<string>()] = YAML::Node(iterator);

	return result;
}