#pragma once

#include <string>

#include "OpenGLIncludes.h"
#include "Exception.h"
#include "Uniform.h"

namespace Engine
{
	class Program;
}

class Engine::Program final
{
public :

	class CantCompileProgramException : public Exception {};

	Program(const std::string &shaderName);
	~Program();

	void use(bool state);

	template <typename T>
	std::unique_ptr<Uniform<T>> makeUniform(const std::string &name)
	{
		return std::make_unique<Uniform<T>>(glGetUniformLocation(_glObject, name.c_str()));
	}

private :

	static const inline std::string directory = "Resources/Shaders";
	GLuint _glObject;

	void reportError() const;
};