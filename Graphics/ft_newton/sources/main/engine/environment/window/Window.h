#pragma once

#include "engine/environment/Environment.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/OpenGL.h"
#include "engine/tools/external/glm/glm.h"

class engine::Window
{
public :

	Window() = delete;
	~Window() = delete;

	static void initialize();

	inline static uvec2 getSize()
	{
		return _size;
	}

	inline static float getAspectRatio()
	{
		return (float)_size.x / (float)_size.y;
	}

	inline static vec2 getScale()
	{
		return _scale;
	}

	static vec2 getMousePosition();

	static int getKeyboardKeyState(int key);
	static int getMouseKeyState(int key);

	static bool shouldClose();

	static void clearColor(const Color &color);
	static void clearDepth();

	static void swapBuffers();

private :

	static inline GLFWwindow *_window;
	static inline uvec2 _size;
	static inline vec2 _scale;

	static void setupWindow();
	static void setupContext();
	static void setupViewport();
};
