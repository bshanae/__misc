#include "engine/environment/shader/Shader.h"

#include "engine/environment/shader/subShader/SubShader.h"
#include "engine/tools/debug/Debug.h"

using namespace engine;

Shader::Shader(const string &shaderName) : _isValid(true)
{
	_glObject = glCreateProgram();

	const auto vertexSubShader = SubShader(SubShader::Vertex, directory + "/" + shaderName + ".vert");
	const auto fragmentSubShader = SubShader(SubShader::Fragment, directory + "/" + shaderName + ".frag");

	glAttachShader(_glObject, vertexSubShader.getGlObject());
	glAttachShader(_glObject, fragmentSubShader.getGlObject());

	glLinkProgram(_glObject);

	GLint success;
	glGetProgramiv(_glObject, GL_LINK_STATUS, &success);

	if (not success)
	{
		Debug::logError("Shader", "Can't compile shader.");
		_isValid = false;

		if constexpr (constants::debug)
			reportError();
	}
}

Shader::~Shader()
{
	glDeleteProgram(_glObject);
}

void Shader::reportError() const
{
	GLchar log[1024];
	glGetProgramInfoLog(_glObject, 1024, nullptr, log);

	cerr << "// DEBUG START" << endl << endl;

	cerr << "// GLSL LOG " << endl << endl;
	cerr << log << endl;

	cerr << "// DEBUG END" << endl;
}