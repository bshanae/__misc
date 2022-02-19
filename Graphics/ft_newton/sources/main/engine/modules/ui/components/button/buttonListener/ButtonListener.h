#pragma once

#include "engine/modules/ui/UI.h"

class engine::ui::ButtonListener
{
	friend class Button;

public :

	ButtonListener() = default;
	~ButtonListener() = default;

protected :

	virtual void onClicked() = 0;
};