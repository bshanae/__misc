#pragma once

#include "engine/modules/ui/UI.h"

#include "engine/core/scene/object/component/Component.h"

class engine::ui::Control : public Component
{
public :

	~Control() override = default;

	void hover(bool state)
	{
		if (isDisabled())
		{
			Debug::logWarning("Control", "Can't hover on disabled control");
			return;
		}

		onHovered(state);
	}

	void click()
	{
		if (isDisabled())
		{
			Debug::logWarning("Control", "Can't click on disabled control");
			return;
		}

		onClicked();
	}

protected :

	Control(Object &object) : Component(object)
	{}

	virtual void onHovered(bool state)
	{}

	virtual void onClicked()
	{}
};