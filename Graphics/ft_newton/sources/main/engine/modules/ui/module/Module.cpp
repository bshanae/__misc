#include "Module.h"

#include "engine/core/scene/object/serialization/Serialization.h"
#include "engine/modules/ui/components/text/Text.h"
#include "engine/modules/ui/components/text/textRenderer/TextRenderer.h"
#include "engine/modules/ui/components/button/Button.h"
#include "engine/modules/ui/components/switch/Switch.h"
#include "engine/modules/ui/components/background/Background.h"
#include "engine/modules/ui/components/background/backgroundRenderer/BackgroundRenderer.h"

using namespace engine::ui;

void Module::initializeInternally()
{
	serialization::registerComponent<Text>();
	serialization::registerComponent<TextRenderer>();

	serialization::registerComponent<Button>();
	serialization::registerComponent<Switch>();

	serialization::registerComponent<Background>();
	serialization::registerComponent<BackgroundRenderer>();
}

void Module::onSceneLaunchingInternal(const YAML::Node &metaNode)
{
	Settings::load();
}