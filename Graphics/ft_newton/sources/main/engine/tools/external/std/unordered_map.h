#pragma once

#include <unordered_map>

namespace engine
{
	template <typename T, typename U>
	using unordered_map = std::unordered_map<T, U>;
}