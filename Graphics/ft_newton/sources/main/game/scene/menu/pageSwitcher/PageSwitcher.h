#pragma once

#include "game/Game.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/ui/components/button/buttonListener/ButtonListener.h"

class game::PageSwitcher : public Component, public ButtonListener
{
public :

	inline static const std::string typeName = "page switcher";
	static void deserialize(PageSwitcher &instance, const YAML::Node &node);

	PageSwitcher(Object &object);
	~PageSwitcher() override = default;

protected :

	void prepareInternally() override;

	void onClicked() override;

private :

	std::string _targetPage;

	Menu *_menu;
};
