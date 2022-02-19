#include "PageSwitcher.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "game/scene/menu/Menu.h"

using namespace game;

void PageSwitcher::deserialize(PageSwitcher &instance, const YAML::Node &node)
{
	instance._targetPage = node["target page"].as<std::string>();
}

PageSwitcher::PageSwitcher(Object &object) : Component(object)
{
	_menu = nullptr;
}

void PageSwitcher::prepareInternally()
{
	for (auto *parent = getObject().getParent(); parent != nullptr and _menu == nullptr; parent = parent->getParent())
		_menu = parent->trySelectComponent<Menu>();

	if (_menu == nullptr)
	{
		Debug::logError("PageSwitcher", "Menu not found");
		markBad();
	}
}

void PageSwitcher::onClicked()
{
	if (_menu != nullptr)
		_menu->navigateToPage(_targetPage);
}