#pragma once

#include <functional>

namespace engine
{
	template <typename ...T>
	using function = std::function<T...>;
}