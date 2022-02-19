#pragma once

#include "engine/tools/Tools.h"

namespace engine::constants
{
#if DEV
	static constexpr auto debug = true;
#else
	static constexpr auto debug = false;
#endif
};
