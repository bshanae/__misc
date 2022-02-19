#pragma once

#include "engine/core/Core.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/map.h"

class engine::PrototypeStorage final
{
public :

	PrototypeStorage() = delete;
	~PrototypeStorage() = delete;

	static const Prototype &get(const string &path);

private :

	inline static const string _directory = "resources/prototypes";
	inline static map<string, Prototype> _prototypes;
};
