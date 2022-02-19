#pragma once

#include "engine/environment/Environment.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/io.h"
#include "engine/tools/external/OpenGL.h"

class engine::SubShader final
{
public :

	enum Type : GLuint
	{
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	SubShader(Type type, const string &path);
	~SubShader();

	inline GLuint getGlObject() const
	{
		return _glObject;
	}

private :

	GLuint _glObject;

	static void writeFileToStream(stringstream &stream, const string &path);
	void reportError(const string &shaderText) const;
};