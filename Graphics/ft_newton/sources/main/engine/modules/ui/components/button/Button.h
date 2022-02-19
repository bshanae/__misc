#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/modules/ui/components/text/Text.h"

class engine::ui::Button final : public Text
{
public :

	inline static const string typeName = "button";
	static void deserialize(Button &instance, const YAML::Node &node);

	Button(Object &object);
	~Button() override = default;

protected :

	void prepareInternally() override;

	void onHovered(bool state) override;
	void onClicked() override;

private :

	Color _defaultColor;
	Color _hoverColor;

	ButtonListener * _listener;

	using Text::setFontColor;
	using Text::getFontColor;
};
