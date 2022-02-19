#pragma once

#include "engine/environment/Environment.h"

#include "engine/tools/templates/AlwaysFalse.h"
#include "engine/tools/color/Color.h"
#include "engine/tools/constants/Constants.h"
#include "engine/tools/debug/Debug.h"

namespace engine
{
	template<typename T>
	void operator << (engine::Uniform<T> uniform, const T &object)
	{
		uniform.validate();

		if constexpr (std::is_same<T, bool>::value)
			glUniform1i(uniform._glObject, object);
		else if constexpr (std::is_same<T, int>::value)
			glUniform1i(uniform._glObject, object);
		else if constexpr (std::is_same<T, float>::value)
			glUniform1f(uniform._glObject, object);
		else if constexpr (std::is_same<T, vec3>::value)
			glUniform3f(uniform._glObject, object.x, object.y, object.z);
		else if constexpr (std::is_same<T, vec4>::value)
			glUniform4fv(uniform._glObject, 1, value_ptr(object));
		else if constexpr (std::is_same<T, mat4>::value)
			glUniformMatrix4fv(uniform._glObject, 1, GL_FALSE, value_ptr(object));
		else if constexpr (std::is_same<T, Color>::value)
			glUniform4fv(uniform._glObject, 1, &object.channels[0]);
		else
			static_assert(AlwaysFalse<T>);
	}
}

template <typename T>
class engine::Uniform final
{
	friend class Shader;

public :

	Uniform() : _glObject(-1)
	{}

	explicit Uniform(GLuint glObject) : _glObject(glObject)
	{
		validate();
	}

	template<typename U>
	friend void operator << (engine::Uniform<U> uniform, const U &object);

private :

	GLuint _glObject;

	void validate()
	{
		if constexpr (constants::debug)
		{
			if (_glObject == -1)
				Debug::logError("Uniform", "Invalid state.");
		}
	}
};