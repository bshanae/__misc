#include "Switch.h"

#include "engine/core/scene/object/Object.h"
#include "engine/modules/ui/components/switch/switchListener/SwitchListener.h"

using namespace engine::ui;

void Switch::deserialize(Switch &instance, const YAML::Node &node)
{
	Text::deserialize(instance, node);

	instance._defaultColor = node["default color"].as<Color>();
	instance._hoverColor = node["hover color"].as<Color>();
	instance._defaultActiveColor = node["default active color"].as<Color>();
	instance._hoverActiveColor = node["hover active color"].as<Color>();
}

Switch::Switch(Object &object) : Text(object)
{
	_state = false;
	_isHovering = false;
}

void Switch::initializeInternally()
{
	Text::initializeInternally();

	updateColor();

	_listener = getObject().trySelectComponent<SwitchListener>();
	if (_listener == nullptr)
	{
		Debug::logError("Switch", "Listener is not found");
		markBad();
	}
}

void Switch::onHovered(bool state)
{
	_isHovering = state;
	updateColor();
}

void Switch::onClicked()
{
	_state = not _state;
	updateColor();

	_listener->onClicked(_state);
}

void Switch::updateColor()
{
	if (not _state)
	{
		if (_isHovering)
			setFontColor(_hoverColor);
		else
			setFontColor(_defaultColor);
	}
	else
	{
		if (_isHovering)
			setFontColor(_hoverActiveColor);
		else
			setFontColor(_defaultActiveColor);
	}
}