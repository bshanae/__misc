#pragma once

#include "engine/core/Core.h"

#include "engine/modules/base/tools/componentFinder/ComponentImportance.h"

namespace engine::base
{
	class Module;

	class Transformation;

	template <typename, ComponentImportance>
	class ComponentFinder;
}