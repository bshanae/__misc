#pragma once

#include <vector>
#include <optional>

#include "game/Game.h"

#include "game/scene/menu/page/Page.h"

class game::PageWithSelector : public Page
{
public :

	inline static const std::string typeName = "page with selector";
	static void deserialize(PageWithSelector &instance, const YAML::Node &node);

	PageWithSelector(Object &object);
	~PageWithSelector() override = default;

	void activate() override;

protected :

	void prepareInternally() override;
	void updateInternally(float timeDelta) override;

private :

	std::vector<Control *> _controls;
	std::optional<unsigned> _hoveredControlIndex;
	bool _wasJustActivated;

	void findControls();

	void hoverControl(unsigned index);
	void clickHoveredControl();
};
