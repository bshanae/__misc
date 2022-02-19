#pragma once

#include "game/Game.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/ui/components/button/buttonListener/ButtonListener.h"

class game::SceneLauncher final : public Component, public ButtonListener
{
public :

	inline static const std::string typeName = "scene launcher";
	static void deserialize(SceneLauncher &instance, const YAML::Node &node);

	SceneLauncher(Object &object);
	~SceneLauncher() override = default;

protected :

	void onClicked() override;

private :

	std::string _sceneName;
};
