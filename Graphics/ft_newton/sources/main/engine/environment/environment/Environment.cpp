#include "Environment.h"

#include "engine/core/settings/Settings.h"
#include "engine/tools/external/OpenGL.h"
#include "engine/tools/debug/Debug.h"
#include "engine/environment/renderingOptions/RenderingOptions.h"

using namespace engine;

void Environment::initialize()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void Environment::configure()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
}

void Environment::loadFunctionPointers()
{
	if (not gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		Debug::invokeFatalError("Environment", "Can't load OpenGL function");
}

void Environment::pollEvents()
{
	glfwPollEvents();
}

void Environment::setRenderingOptions(RenderingOptions options)
{
	setFaceCulling((options & RenderingOptions::FaceCulling) != 0);
	setWireframeMode((options & RenderingOptions::WireframeMode) != 0);
}

void Environment::renderIndexedBuffer(unsigned numberOfIndices, unsigned numberOfInstances)
{
	glDrawElementsInstanced(GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, 0, numberOfInstances);
}

float Environment::getRealTime()
{
	return glfwGetTime();
}

float Environment::getScaledTime()
{
	return getRealTime() * Settings::getTimeScale();
}

void Environment::checkErrors(string mark)
{
	GLenum err(glGetError());

	while (err != GL_NO_ERROR)
	{
		auto message = string();

		switch (err)
		{
			case GL_INVALID_OPERATION:
				message = "INVALID_OPERATION";
				break;

			case GL_INVALID_ENUM:
				message = "INVALID_ENUM";
				break;

			case GL_INVALID_VALUE:
				message = "INVALID_VALUE";
				break;

			case GL_OUT_OF_MEMORY:
				message = "OUT_OF_MEMORY";
				break;

			case GL_INVALID_FRAMEBUFFER_OPERATION:
				message = "INVALID_FRAMEBUFFER_OPERATION";
				break;

		}

		Debug::logWarning("Environment", "OpenGL error: " + message + (mark != "" ? (", mark: " + mark) : ""));
		err = glGetError();
	}
}

void Environment::setFaceCulling(bool state)
{
	if (state)
	{
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	}
	else
	{
		glDisable(GL_CULL_FACE);
	}
}

void Environment::setWireframeMode(bool state)
{
	if (state)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}