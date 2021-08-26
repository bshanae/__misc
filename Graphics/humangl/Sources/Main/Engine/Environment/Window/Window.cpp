#include "Window.h"

#include "Environment.h"
#include "Input.h"

using namespace Engine;

Window::Window() : _window()
{
	Environment::initialize();

	setupWindow();
	setupContext();

	Environment::loadFunctionPointers();

	setupViewport();
	setupRenderingOptions();
}

Vector2 Window::getSize() const
{
	return _size;
}

Vector2 Window::getScale() const
{
	return _scale;
}

Vector2 Window::getMousePosition() const
{
	double x, y;

	glfwGetCursorPos(_window, &x, &y);
	return {(float)x, (float)y};
}

int Window::getKeyboardKeyState(int key) const
{
	return glfwGetKey(_window, key);
}

int Window::getMouseKeyState(int key) const
{
	return glfwGetMouseButton(_window, key);
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(_window);
}

void Window::clear()
{
	glClearColor(_backgroundColor.x, _backgroundColor.y, _backgroundColor.z, _backgroundColor.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(_window);
}

void Window::setupWindow()
{
	const auto configuration = Configuration("Window");

	const auto windowSize = configuration.get<Vector2>("window size");
	const auto windowTitle = configuration.get<std::string>("window title");
	const auto backgroundColor = configuration.get<Vector4>("background color");

	_window = glfwCreateWindow(
		(int)windowSize.x,
		(int)windowSize.y,
		windowTitle.c_str(),
		nullptr,
		nullptr);

	if (_window == nullptr)
		throw CantCreateGlfwWindow();

	this->_size = windowSize;
	this->_backgroundColor = backgroundColor;
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

void Window::setupRenderingOptions()
{
	glEnable(GL_DEPTH_TEST);
}