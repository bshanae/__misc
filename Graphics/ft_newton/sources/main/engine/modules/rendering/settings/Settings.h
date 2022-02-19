#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/color/Color.h"
#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/map.h"

class engine::rendering::Settings final
{
	friend class Module;

public :

	Settings() = delete;
	~Settings() = delete;

	static inline Color getBackgroundColor()
	{
		return _backgroundColor;
	};

	static inline unsigned getNumberOfInstancesOfModel(const string &fileName)
	{
		if (auto iterator = _modelsNumberOfInstances.find(fileName); iterator != _modelsNumberOfInstances.end())
			return iterator->second;
		else
			return 1;
	}

private :

	static inline Color _backgroundColor;
	static inline map<string, unsigned> _modelsNumberOfInstances;

	static void loadSettings();
	static void loadSceneMeta(const YAML::Node &metaNode);
};