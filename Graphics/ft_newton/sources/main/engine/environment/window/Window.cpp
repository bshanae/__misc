#include "engine/environment/window/Window.h"

#include "engine/core/settings/Settings.h"
#include "engine/environment/environment/Environment.h"
#include "engine/tools/color/Color.h"
#include "engine/tools/debug/Debug.h"

using namespace engine;

void Window::initialize()
{
	Environment::initialize();

	setupWindow();
	setupContext();

	Environment::loadFunctionPointers();
	Environment::configure();

	setupViewport();
}

vec2 Window::getMousePosition()
{
	double x, y;

	glfwGetCursorPos(_window, &x, &y);
	return {(float)x, (float)y};
}

int Window::getKeyboardKeyState(int key)
{
	return glfwGetKey(_window, key);
}

int Window::getMouseKeyState(int key)
{
	return glfwGetMouseButton(_window, key);
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(_window);
}

void Window::clearColor(const Color &color)
{
	glClearColor(color.r, color.g, color.b, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::clearDepth()
{
	glClear(GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(_window);
}

void Window::setupWindow()
{
	const auto windowSize = Settings::getWindowSize();
	const auto windowTitle = Settings::getWindowTitle();

	_window = glfwCreateWindow(windowSize.x, windowSize.y, windowTitle.c_str(), nullptr, nullptr);
	if (_window == nullptr)
		Debug::invokeFatalError("Window", "Cant create GLFW window");

	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	_size = windowSize;
}

void Window::setupContext()
{
	glfwMakeContextCurrent(_window);
}

void Window::setupViewport()
{
	int framebufferWidth;
	int framebufferHeight;

	glfwGetFramebufferSize(_window, &framebufferWidth, &framebufferHeight);
	glViewport(0, 0, framebufferWidth, framebufferHeight);

	_scale.x = (float)framebufferWidth / _size.x;
	_scale.y = (float)framebufferHeight / _size.y;
}