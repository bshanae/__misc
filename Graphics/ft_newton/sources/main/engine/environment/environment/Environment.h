#pragma once

#include "engine/environment/Environment.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"

class engine::Environment final
{
public :

	Environment() = delete;
	~Environment() = delete;

	static void initialize();
	static void configure();
	static void loadFunctionPointers();

	static void pollEvents();

	static void setRenderingOptions(RenderingOptions options);

	static void renderIndexedBuffer(unsigned numberOfIndices, unsigned numberOfInstances = 1);

	static float getRealTime();
	static float getScaledTime();

	static void checkErrors(string mark = "");

private :

	static void setFaceCulling(bool state);
	static void setWireframeMode(bool state);
};