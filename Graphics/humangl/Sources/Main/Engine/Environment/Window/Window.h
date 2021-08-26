#pragma once

#include <string>

#include "OpenGLIncludes.h"
#include "Singleton.h"
#include "Vector2.h"
#include "Vector4.h"

namespace Engine
{
	class Window;
}

class Engine::Window final : public Singleton<Engine::Window>
{
public :

	class CantCreateGlfwWindow : public Exception {};

	Window();

	Vector2 getSize() const;
	Vector2 getScale() const;
	Vector2 getMousePosition() const;

	int getKeyboardKeyState(int key) const;
	int getMouseKeyState(int key) const;

	bool shouldClose();
	void clear();
	void swapBuffers();

private :

	Vector4 _backgroundColor;

	GLFWwindow *_window;
	Vector2 _size;
	Vector2 _scale;

	void setupWindow();
	void setupContext();
	void setupViewport();
	void setupRenderingOptions();
};
