#pragma once

#include "engine/modules/base/Base.h"

#include "engine/core/module/Module.h"

class engine::base::Module : public engine::Module<engine::base::Module>
{
public :

	~Module() override = default;

protected :

	void initializeInternally() override;
};
