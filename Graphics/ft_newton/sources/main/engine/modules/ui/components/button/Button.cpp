#include "Button.h"

#include "engine/core/scene/object/Object.h"
#include "engine/modules/ui/components/button/buttonListener/ButtonListener.h"

using namespace engine::ui;

void Button::deserialize(Button &instance, const YAML::Node &node)
{
	Text::deserialize(static_cast<Text &>(instance), node);

	instance._defaultColor = node["default color"].as<Color>();
	instance._hoverColor = node["hover color"].as<Color>();
}

Button::Button(Object &object) : Text(object)
{}

void Button::prepareInternally()
{
	_listener = getObject().trySelectComponent<ButtonListener>();
	if (_listener == nullptr)
	{
		Debug::logError("Button", "Listener is not found");
		markBad();
	}

	onHovered(false);
}

void Button::onHovered(bool state)
{
	if (state)
		setFontColor(_hoverColor);
	else
		setFontColor(_defaultColor);
}

void Button::onClicked()
{
	_listener->onClicked();
}