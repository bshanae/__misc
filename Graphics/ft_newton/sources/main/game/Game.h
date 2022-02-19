#pragma once

#include "engine/core/Core.h"
#include "engine/environment/Environment.h"
#include "engine/tools/Tools.h"
#include "engine/modules/base/Base.h"
#include "engine/modules/rendering/Rendering.h"
#include "engine/modules/physics/Physics.h"
#include "engine/modules/ui/UI.h"

namespace game
{
	class Menu;
	class Page;
	class PageWithSelector;
	class PageSwitcher;

	class SceneLauncher;
	class SceneResetter;
	class SceneCloser;

	class Launcher;
}

namespace game
{
	// CORE

	using engine::Processor;

	using engine::Scene;
	using engine::Object;
	using engine::Component;

	// TOOLS

	using engine::Debug;

	// ENVIRONMENT

	using engine::Environment;
	using engine::Input;

	// BASE MODULE

	using engine::base::Transformation;
	using engine::base::ComponentFinder;

	using engine::base::ComponentImportance::Mandatory;
	using engine::base::ComponentImportance::Optional;

	// UI MODULE

	using engine::ui::Control;
	using engine::ui::Button;
	using engine::ui::ButtonListener;
}