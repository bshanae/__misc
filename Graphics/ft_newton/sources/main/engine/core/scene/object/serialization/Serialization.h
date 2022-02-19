#pragma once

#include "engine/core/Core.h"
#include "engine/tools/Tools.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

template <typename T, typename = int>
struct HasDeserializer : std::false_type {};

template <typename T>
struct HasDeserializer<T, decltype(&T::deserialize, 0)> : std::true_type {};

template<typename T>
static inline constexpr void tryCallDeserializer(T &instance, const YAML::Node &node)
{
    if constexpr (HasDeserializer<T>::value)
		T::deserialize(instance, node);
}

namespace engine::serialization
{
	void deserializeObject(Scene &scene, const YAML::Node &node);

	inline map<string, function<void (Object &, const YAML::Node &)>> componentDeserializers;

	template <typename TComponent>
	void registerComponent()
	{
		componentDeserializers[TComponent::typeName] = [](Object &object, const YAML::Node &node)
		{
			auto &instance = object.addComponent<TComponent>();
			tryCallDeserializer<TComponent>(instance, node);
		};
	}
};
