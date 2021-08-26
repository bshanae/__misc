#include "Processor.h"

#include "Environment.h"
#include "Input.h"
#include "Window.h"

using namespace Engine;

void Processor::processEvents()
{
	Environment::pollEvents();
}

void Processor::processInput()
{
	Input::getInstance()->refresh();
}

void Processor::startRendering()
{
	Window::getInstance()->clear();
}

void Processor::finishRendering()
{
	Window::getInstance()->swapBuffers();
}