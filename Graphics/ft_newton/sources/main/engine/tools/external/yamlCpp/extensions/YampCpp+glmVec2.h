#pragma once

#include "engine/tools/external/glm/glm.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

namespace YAML
{
	template<>
	struct convert<glm::vec2>
	{
		static Node encode(const glm::vec2 &rhs)
		{
			Node node;

			node.push_back(rhs.x);
			node.push_back(rhs.y);

			return node;
		}

		static bool decode(const Node &node, glm::vec2 &rhs)
		{
			if (!node.IsSequence() || node.size() != 2)
				return false;

			rhs.x = node[0].as<float>();
			rhs.y = node[1].as<float>();

			return true;
		}
	};
}