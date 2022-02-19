#include "PageWithSelector.h"

#include "engine/core/scene/object/Object.h"
#include "engine/environment/input/Input.h"
#include "engine/modules/ui/components/control/Control.h"

using namespace game;

void PageWithSelector::deserialize(PageWithSelector &instance, const YAML::Node &node)
{
	Page::deserialize(instance, node);
}

PageWithSelector::PageWithSelector(Object &object) : Page(object)
{
	_hoveredControlIndex = std::nullopt;
	_wasJustActivated = false;
}

void PageWithSelector::activate()
{
	Page::activate();

	_wasJustActivated = true;

	if (isPrepared())
		hoverControl(0);
}

void PageWithSelector::prepareInternally()
{
	findControls();

	if (_wasJustActivated)
		hoverControl(0);
}

void PageWithSelector::updateInternally(float timeDelta)
{
	if (not _wasJustActivated)
	{
		if (Input::isPressed(Input::Down) and _hoveredControlIndex < _controls.size() - 1)
			hoverControl(*_hoveredControlIndex + 1);
		if (Input::isPressed(Input::Up) and _hoveredControlIndex > 0)
			hoverControl(*_hoveredControlIndex - 1);
		if (Input::isPressed(Input::Enter))
			clickHoveredControl();
	}

	_wasJustActivated = false;
}

void PageWithSelector::findControls()
{
	for (auto *child : getObject().getChildren())
	{
		if (auto *control = child->trySelectComponent<Control>(); control != nullptr)
			_controls.push_back(control);
	}

	if (_controls.empty())
	{
		Debug::logError("Page", "No child controls found");
		markBad();
	}
}

void PageWithSelector::hoverControl(unsigned index)
{
	if (index < 0 or index >= _controls.size())
	{
		Debug::logError("Page", "Can't hover a control, index " + std::to_string(index) + " is invalid.");
		markBad();
		return;
	}

	if (_hoveredControlIndex.has_value())
		_controls[*_hoveredControlIndex]->hover(false);

	_hoveredControlIndex = index;
	_controls[*_hoveredControlIndex]->hover(true);
}

void PageWithSelector::clickHoveredControl()
{
	if (_hoveredControlIndex < 0 or _hoveredControlIndex >= _controls.size())
	{
		Debug::logError("Page", "Can't click on hovered control");
		markBad();
		return;
	}

	_controls[*_hoveredControlIndex]->click();
}