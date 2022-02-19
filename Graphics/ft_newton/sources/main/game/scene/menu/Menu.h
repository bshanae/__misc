#pragma once

#include "game/Game.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/base/tools/componentFinder/ComponentFinder.h"

class game::Menu : public Component
{
public :

	inline static const std::string typeName = "menu";
	static void deserialize(Menu &instance, const YAML::Node &node);

	Menu(Object &object);
	~Menu() override = default;

	void navigateToPage(const std::string &name);

protected :

	void prepareInternally() override;
	void processInputInternally() override;
	void updateInternally(float timeDelta) override;

private :

	std::string _mainPage;
	float _width;

	ComponentFinder<Transformation, Mandatory> _transformationFinder;

	bool _isHidden;
	bool _isHiddenFuture;
	bool _isAnimating;
	float _targetX;

	std::map<std::string, Page *> _pages;
	Page *_activePage;

	void show();
	void hide(bool instant = false);

	void findPages();
};
