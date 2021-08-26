#include "OpenGLIncludes.h"
#include "Environment.h"

using namespace Engine;

void Environment::initialize()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void Environment::loadFunctionPointers()
{
	if (not gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw CantLoadOpenglFunctions();
}

void Environment::pollEvents()
{
	glfwPollEvents();
}

void Environment::renderIndexedBuffer(uint numberOfIndices)
{
	glDrawElements(GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, nullptr);
}

float Environment::getTime()
{
	return glfwGetTime();
}