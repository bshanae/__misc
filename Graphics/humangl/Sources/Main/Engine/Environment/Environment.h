#pragma once

#include "OpenGLIncludes.h"
#include "Exception.h"
#include "Singleton.h"
#include "Configuration.h"

namespace Engine
{
	class Environment;
}

class Engine::Environment final
{
public :

	class CantLoadOpenglFunctions : public Exception {};

	static void initialize();
	static void loadFunctionPointers();
	static void pollEvents();
	static void renderIndexedBuffer(uint numberOfIndices);

	static float getTime();
};