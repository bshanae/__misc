#pragma once

#include "YamlCpp.h"
#include "Vector2.h"

namespace YAML
{
	template<>
	struct convert<Engine::Vector2>
	{
		static Node encode(const Engine::Vector2 &rhs)
		{
			Node node;

			node.push_back(rhs.x);
			node.push_back(rhs.y);

			return node;
		}

		static bool decode(const Node &node, Engine::Vector2 &rhs)
		{
			if (!node.IsSequence() || node.size() != 2)
				return false;

			rhs.x = node[0].as<float>();
			rhs.y = node[1].as<float>();

			return true;
		}
	};
}