#pragma once

#include "YamlCpp.h"
#include "Vector3.h"

namespace YAML
{
	template<>
	struct convert<Engine::Vector3>
	{
		static Node encode(const Engine::Vector3 &rhs)
		{
			Node node;

			node.push_back(rhs.x);
			node.push_back(rhs.y);
			node.push_back(rhs.z);

			return node;
		}

		static bool decode(const Node &node, Engine::Vector3 &rhs)
		{
			if (!node.IsSequence() || node.size() != 3)
				return false;

			rhs.x = node[0].as<float>();
			rhs.y = node[1].as<float>();
			rhs.z = node[2].as<float>();

			return true;
		}
	};
}