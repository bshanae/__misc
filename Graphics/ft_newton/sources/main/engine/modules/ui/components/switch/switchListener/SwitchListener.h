#pragma once

#include "engine/modules/ui/UI.h"

class engine::ui::SwitchListener
{
	friend class Switch;

public :

	SwitchListener() = default;
	~SwitchListener() = default;

protected :

	virtual void onClicked(bool newState) = 0;
};