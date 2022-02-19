#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/core/module/Module.h"
#include "engine/tools/templates/eventSystem/listener/Listener.h"
#include "engine/modules/ui/settings/Settings.h"

#include "engine/modules/ui/components/text/Text.h"
#include "engine/modules/ui/components/text/textRenderer/TextRenderer.h"

class engine::ui::Module : public engine::Module<engine::ui::Module>
{
public :

	Module() = default;
	~Module() override = default;

protected :

	void initializeInternally() override;
	void onSceneLaunchingInternal(const YAML::Node &metaNode) override;
};
