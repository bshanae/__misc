#include <iostream>

#include "Shader.h"
#include "Program.h"

using namespace Engine;

Program::Program(const std::string &shaderName)
{
	_glObject = glCreateProgram();

	const auto vertex_shader = Shader(Shader::Vertex, directory + "/" + shaderName + ".vert");
	const auto fragment_shader = Shader(Shader::Fragment, directory + "/" + shaderName + ".frag");

	glAttachShader(_glObject, vertex_shader._glObject);
	glAttachShader(_glObject, fragment_shader._glObject);

	glLinkProgram(_glObject);

	GLint success;
	glGetProgramiv(_glObject, GL_LINK_STATUS, &success);

	if (not success)
	{
		reportError();
		throw CantCompileProgramException();
	}
}

Program::~Program()
{
	glDeleteProgram(_glObject);
}

void Program::use(bool state)
{
	glUseProgram(state ? _glObject : 0);
}

void Program::reportError() const
{
	GLchar log[1024];
	glGetProgramInfoLog(_glObject, 1024, nullptr, log);

	std::cerr << "// DEBUG START" << std::endl << std::endl;

	std::cerr << "// GLSL LOG " << std::endl << std::endl;
	std::cerr << log << std::endl;

	std::cerr << "// DEBUG END" << std::endl;
}