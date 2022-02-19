#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/modules/ui/components/text/Text.h"

class engine::ui::Switch final : public Text
{
public :

	inline static const string typeName = "switch";
	static void deserialize(Switch &instance, const YAML::Node &node);

	Switch(Object &object);
	~Switch() override = default;

protected :

	void initializeInternally() override;

	void onHovered(bool state) override;
	void onClicked() override;

private :

	Color _defaultColor;
	Color _hoverColor;
	Color _defaultActiveColor;
	Color _hoverActiveColor;

	bool _isHovering;
	bool _state;

	SwitchListener * _listener;

	using Text::setFontColor;
	using Text::getFontColor;

	void updateColor();
};
