#pragma once

#include "OpenGLIncludes.h"
#include "Exception.h"
#include "Color.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

namespace Engine
{
	template <typename>
	class Uniform;
}

template<typename T>
class Engine::Uniform
{
	friend class Program;

public :

	Uniform &operator = (const T &object)
	{
		if constexpr (std::is_same<T, int>::value)
			glUniform1i(_glObject, object);
		else if constexpr (std::is_same<T, float>::value)
			glUniform1f(_glObject, object);
		else if constexpr (std::is_same<T, Color>::value)
			glUniform3f(_glObject, object.r, object.g, object.b);
		else if constexpr (std::is_same<T, Vector3>::value)
			glUniform3f(_glObject, object.x, object.y, object.z);
		else if constexpr (std::is_same<T, Vector4>::value)
			glUniform4f(_glObject, object.x, object.y, object.z, object.w);
		else if constexpr (std::is_same<T, Matrix4x4>::value)
			glUniformMatrix4fv(_glObject, 1, GL_FALSE, object.getData());
		else
			throw Exception("Uniform : Unknown data type");

		return *this;
	}

	explicit Uniform(GLuint glObject) : _glObject(glObject)
	{
		if (glObject == -1)
			throw Exception("Uniform : Invalid uniform object");
	}

private :

	GLuint _glObject;
};
