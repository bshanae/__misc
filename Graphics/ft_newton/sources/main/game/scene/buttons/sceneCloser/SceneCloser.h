#pragma once

#include "game/Game.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/ui/components/button/buttonListener/ButtonListener.h"

class game::SceneCloser final : public Component, public ButtonListener
{
public :

	inline static const std::string typeName = "scene closer";

	SceneCloser(Object &object);
	~SceneCloser() override = default;

protected :

	void onClicked() override;
};
