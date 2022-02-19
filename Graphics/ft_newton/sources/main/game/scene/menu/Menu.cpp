#include "Menu.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/environment/input/Input.h"
#include "game/scene/menu/page/Page.h"

using namespace game;

void Menu::deserialize(Menu &instance, const YAML::Node &node)
{
	instance._mainPage = node["main page"].as<std::string>();
	instance._width = node["width"].as<float>();
}

Menu::Menu(Object &object) : Component(object), _transformationFinder(*this)
{
	_isHidden = false;
	_isHiddenFuture = false;
	_isAnimating = false;
	_activePage = nullptr;
}

void Menu::navigateToPage(const std::string &name)
{
	if (auto iterator = _pages.find(name); iterator != _pages.end())
	{
		if (_activePage != nullptr)
			_activePage->deactivate();

		_activePage = iterator->second;
		_activePage->activate();
	}
	else
	{
		Debug::logError("Page", "Child page '" + name + "' not found.");
	}
}

void Menu::prepareInternally()
{
	Debug::logMessage("Menu", "'cmd' - open menu, 'up/down' - select buttons, 'escape' - go to parent page.");

	findPages();

	navigateToPage(_mainPage);
	hide(true);
}

void Menu::processInputInternally()
{
	if (Input::isPressed(Input::Command))
	{
		if (_isHidden)
			show();
		else
			hide();
	}

	if (_isHidden)
		return;

	if (Input::isPressed(Input::Escape) and _activePage != nullptr and _activePage->getParentName() != "")
		navigateToPage(_activePage->getParentName());
}

void Menu::updateInternally(float timeDelta)
{
	if (!_isAnimating)
		return;

	constexpr auto speed = 1000.f;

	const auto oldX = _transformationFinder().getGlobalPosition().x;
	const auto oldSign = _targetX > oldX ? +1.f : -1.f;

	_transformationFinder().moveBy(glm::vec3(speed * oldSign * timeDelta, 0, 0));

	const auto newX = _transformationFinder().getGlobalPosition().x;
	const auto delta = (newX - _targetX) * oldSign;

	if (delta > 0)
	{
		auto finalPosition  = _transformationFinder().getGlobalPosition();
		finalPosition.x = _targetX;

		_transformationFinder().moveTo(finalPosition);
		_isHidden = _isHiddenFuture;
		_isAnimating = false;

		if (_activePage != nullptr and _isHidden)
			_activePage->deactivate();
	}
}

void Menu::show()
{
	Debug::assume(_isHidden, "Menu is already shown");

	if (_activePage != nullptr)
		_activePage->activate();

	_isAnimating = true;
	_isHiddenFuture = false;
	_targetX = 0;
}

void Menu::hide(bool instant)
{
	Debug::assume(not _isHidden, "Menu is already hidden");

	if (instant)
	{
		_transformationFinder().moveBy(glm::vec3(-_width, 0, 0));
		_isHidden = true;
		return;
	}

	_isAnimating = true;
	_isHiddenFuture = true;
	_targetX = _width * -1.f;
}

void Menu::findPages()
{
	const auto lookForPage = [this](Object &child)
	{
		if (auto *page = child.trySelectComponent<Page>(); page != nullptr)
		{
			_pages[page->getName()] = page;
			page->deactivate();
		}
	};

	getObject().traverseDescendants(lookForPage);
}