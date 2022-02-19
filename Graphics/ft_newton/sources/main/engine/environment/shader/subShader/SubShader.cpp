#include "SubShader.h"

#include "engine/tools/debug/Debug.h"

using namespace engine;

SubShader::SubShader(Type type, const string &path)
{
	stringstream stream;
	writeFileToStream(stream, path);

	const string string = stream.str();
	const char *rawString = string.data();

	_glObject = glCreateShader((GLuint)type);
	glShaderSource(_glObject, 1, &rawString, nullptr);
	glCompileShader(_glObject);

	GLint success;
	glGetShaderiv(_glObject, GL_COMPILE_STATUS, &success);

	if (not success)
	{
		Debug::logError("SubShader", "Can't compile subshader.");
		if constexpr (constants::debug)
			reportError(rawString);
	}
}

SubShader::~SubShader()
{
	glDeleteShader(_glObject);
}

void SubShader::writeFileToStream(stringstream &stream, const string &path)
{
	ifstream file(path);

	if (not file.is_open())
	{
		Debug::logError("SubShader", "Can't read subshader source file.");
		file.close();
		return;
	}

	stream << file.rdbuf();
	file.close();
}

void SubShader::reportError(const string &shaderText) const
{
	GLchar log[1024];
	glGetShaderInfoLog(_glObject, 1024, nullptr, log);

	cerr << "// DEBUG START" << endl << endl;

	cerr << "// GLSL SHADER" << endl << endl;
	cerr << shaderText;

	cerr << "// GLSL LOG " << endl << endl;
	cerr << log << endl;

	cerr << "// DEBUG END" << endl;
}