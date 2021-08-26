#pragma once

#include <exception>
#include <string>

namespace Engine
{
	class Exception;
}

class Engine::Exception : public std::exception
{
public :

	Exception(const std::string &message = "") : _message(message)
	{}

	const char *what() const noexcept override
	{
		return _message.c_str();
	}

private :

	const std::string _message;
};