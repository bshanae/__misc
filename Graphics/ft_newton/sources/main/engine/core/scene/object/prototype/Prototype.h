#pragma once

#include "engine/core/Core.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/map.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

class engine::Prototype final
{
public :

	Prototype(const YAML::Node &node);
	~Prototype() = default;

	YAML::Node merge(const YAML::Node &patch) const;

private :

	const YAML::Node _node;

	static void mergeObjectAttributes(YAML::Node &target, const YAML::Node &base, const YAML::Node &patch);
	static void mergeComponents(YAML::Node &target, const YAML::Node &base, const YAML::Node &patch);

	static map<string, YAML::Node> collectComponentsMeta(const YAML::Node &componentList);
};
