#pragma once

#include "yaml-cpp/yaml.h"

#include "extensions/YampCpp+glmVec2.h"
#include "extensions/YampCpp+glmUVec2.h"
#include "extensions/YampCpp+glmVec3.h"
#include "extensions/YampCpp+glmVec4.h"

namespace engine
{
	inline YAML::Node merge(const YAML::Node &base, const YAML::Node &patch)
	{
		if (!patch.IsMap())
			return patch.IsNull() ? base : patch;

		if (!base.IsMap())
			return patch;

		if (!patch.size())
			return base;

		auto result = YAML::Node(YAML::NodeType::Map);

		for (auto node : base)
		{
			if (node.first.IsScalar())
			{
				const auto &key = node.first.Scalar();

				if (patch[key])
				{
					result[node.first] = merge(node.second, patch[key]);
					continue;
				}
			}

			result[node.first] = node.second;
		}

		for (auto node : patch)
		{
			if (not node.first.IsScalar())
			{
				const auto &key = node.first.Scalar();

				if (base[key])
				{
					result[node.first] = merge(base[key], node.second);
					continue;
				}
			}

			result[node.first] = node.second;
		}

		return result;
	}
}