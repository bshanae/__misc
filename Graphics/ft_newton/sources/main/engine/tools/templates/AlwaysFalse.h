#pragma once

#include <type_traits>

template <class ...> constexpr std::false_type AlwaysFalse{};