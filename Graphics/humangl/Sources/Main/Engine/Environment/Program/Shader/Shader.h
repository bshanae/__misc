#pragma once

#include <string>
#include <sstream>

#include "OpenGLIncludes.h"
#include "Exception.h"

namespace Engine
{
	class Shader;
}

class Engine::Shader final
{
private :

	class CantReadFileException : public Exception {};
	class CantCompileShader : public Exception {};

	enum Type : GLuint
	{
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	friend class Program;

	Shader(Type type, const std::string &path);

public :

	~Shader();

private :

	GLuint _glObject;

	static void writeFileToStream(std::stringstream &stream, const std::string &path);
	void reportError(const std::string &shaderText) const;
};