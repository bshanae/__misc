#pragma once

#include "game/Game.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/ui/components/button/buttonListener/ButtonListener.h"

class game::SceneResetter final : public Component, public ButtonListener
{
public :

	inline static const std::string typeName = "scene resetter";

	SceneResetter(Object &object);
	~SceneResetter() override = default;

protected :

	void onClicked() override;
};
