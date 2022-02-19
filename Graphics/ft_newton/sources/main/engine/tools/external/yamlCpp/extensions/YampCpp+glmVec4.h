#pragma once

#include "engine/tools/external/glm/glm.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

namespace YAML
{
	template<>
	struct convert<glm::vec4>
	{
		static Node encode(const glm::vec4 &vector)
		{
			Node node;

			node.push_back(vector.x);
			node.push_back(vector.y);
			node.push_back(vector.z);
			node.push_back(vector.w);

			return node;
		}

		static bool decode(const Node &node, glm::vec4 &vector)
		{
			if (!node.IsSequence() || node.size() != 4)
				return false;

			vector.x = node[0].as<float>();
			vector.y = node[1].as<float>();
			vector.z = node[2].as<float>();
			vector.w = node[3].as<float>();

			return true;
		}
	};
}