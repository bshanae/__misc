#pragma once

#include "engine/core/Core.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/set.h"
#include "engine/tools/external/glm/glm.h"

class engine::Settings
{
	friend class Processor;

public :

	static inline const string source = "resources/settings.yaml";

	Settings() = delete;
	~Settings() = delete;

	inline static uvec2 getWindowSize()
	{
		return _windowSize;
	}

	inline static string getWindowTitle()
	{
		return _windowTitle;
	}

	static inline float getTimeScale()
	{
		return _timeScale;
	};

	static inline float getFixedTimeStep()
	{
		return _fixedTimeStep;
	};

private :

	static inline uvec2 _windowSize;
	static inline string _windowTitle;

	static inline float _timeScale;
	static inline float _fixedTimeStep;

	static void load();
};