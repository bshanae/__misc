#pragma once

#include "engine/tools/templates/EnableBitmaskOperators.h"

namespace engine
{
	enum class RenderingOptions : unsigned
	{
		FaceCulling = 1u << 0,
		WireframeMode = 1u << 2
	};
}

template<>
struct EnableBitmaskOperators<engine::RenderingOptions>
{
	static const bool enable = true;
};