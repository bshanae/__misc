#pragma once

#include "Color.h"

#include "engine/tools/external/yamlCpp/YamlCpp.h"

namespace YAML
{
	template<>
	struct convert<engine::Color>
	{
		static Node encode(const engine::Color &rhs)
		{
			Node node;

			node.push_back(rhs.r);
			node.push_back(rhs.g);
			node.push_back(rhs.b);
			node.push_back(rhs.a);

			return node;
		}

		static bool decode(const Node &node, engine::Color &rhs)
		{
			if (!node.IsSequence() or (node.size() != 3 and node.size() != 4))
				return false;

			rhs.r = node[0].as<float>();
			rhs.g = node[1].as<float>();
			rhs.b = node[2].as<float>();
			rhs.a = node[3].as<float>(1.f);

			return true;
		}
	};
}