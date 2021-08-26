#include "Shader.h"

#include <fstream>
#include <iostream>

using namespace Engine;

Shader::Shader(Type type, const std::string &path)
{
	std::stringstream stream;
	writeFileToStream(stream, path);

	const std::string string = stream.str();
	const char *rawString = string.data();

	_glObject = glCreateShader((GLuint)type);
	glShaderSource(_glObject, 1, &rawString, nullptr);
	glCompileShader(_glObject);

	GLint success;
	glGetShaderiv(_glObject, GL_COMPILE_STATUS, &success);

	if (not success)
	{
		reportError(rawString);
		throw CantCompileShader();
	}
}

Shader::~Shader()
{
	glDeleteShader(_glObject);
}

void Shader::writeFileToStream(std::stringstream &stream, const std::string &path)
{
	std::ifstream file(path);

	if (not file.is_open())
		throw CantReadFileException();

	stream << file.rdbuf();
	file.close();
}

void Shader::reportError(const std::string &shaderText) const
{
	GLchar log[1024];
	glGetShaderInfoLog(_glObject, 1024, nullptr, log);

	std::cerr << "// DEBUG START" << std::endl << std::endl;

	std::cerr << "// GLSL SHADER" << std::endl << std::endl;
	std::cerr << shaderText;

	std::cerr << "// GLSL LOG " << std::endl << std::endl;
	std::cerr << log << std::endl;

	std::cerr << "// DEBUG END" << std::endl;
}