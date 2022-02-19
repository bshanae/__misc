#pragma once

#include "engine/environment/Environment.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/OpenGL.h"

class engine::Shader
{
public :

	Shader(const string &shaderName);
	virtual ~Shader();

	inline void use(bool state) const
	{
		glUseProgram(state ? _glObject : 0);
	}

	template <typename T>
	Uniform<T> makeUniform(const string &name)
	{
		return Uniform<T>(glGetUniformLocation(_glObject, name.c_str()));
	}

	inline bool isValid() const
	{
		return _isValid;
	}

private :

	static const inline string directory = "resources/shaders";

	GLuint _glObject;
	bool _isValid;

	void reportError() const;
};