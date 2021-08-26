#pragma once

#include "YamlCpp.h"
#include "Color.h"

namespace YAML
{
	template<>
	struct convert<Engine::Color>
	{
		static Node encode(const Engine::Color &rhs)
		{
			Node node;

			node.push_back(rhs.r);
			node.push_back(rhs.g);
			node.push_back(rhs.b);

			return node;
		}

		static bool decode(const Node &node, Engine::Color &rhs)
		{
			if (!node.IsSequence() || node.size() != 3)
				return false;

			rhs.r = node[0].as<float>();
			rhs.g = node[1].as<float>();
			rhs.b = node[2].as<float>();

			return true;
		}
	};
}