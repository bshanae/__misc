#pragma once

#include "engine/modules/ui/UI.h"

class engine::ui::Settings final
{
	friend class Module;

public :

	Settings() = delete;
	~Settings() = delete;

private :

	static void load();
};