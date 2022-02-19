#pragma once

#include "engine/core/Core.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/std/string.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

namespace engine::serialization
{
	struct DeserializedScene
	{
		unique_ptr<Scene> scene;
		YAML::Node metaNode;
	};

	DeserializedScene deserializeScene(const string &fileName);
}