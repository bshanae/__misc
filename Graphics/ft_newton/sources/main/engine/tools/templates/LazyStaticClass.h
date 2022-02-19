#pragma once

#include "engine/tools/Tools.h"

#include "engine/tools/external/std/pointers.h"
#include "engine/tools/debug/Debug.h"

template <typename TFinal>
class engine::LazyStaticClass
{
protected :

	static void initializeIfNeeded()
	{
		if (not _isInitialized)
		{
			TFinal::initialize();
			_isInitialized = true;
		}
	}

	static void assumeInitialized()
	{
		if (not _isInitialized)
			Debug::logWarning("A static class should be initialized at this point");
	}

private :

	static inline bool _isInitialized;
};