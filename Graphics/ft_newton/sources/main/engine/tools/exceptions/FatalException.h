#pragma once

#include "engine/tools/Tools.h"

#include "Exception.h"

class engine::FatalException : public Exception
{
public :

	FatalException(const string &message = "") : _message("Fatal error : " + message)
	{}

	const char *what() const noexcept override
	{
		return _message.c_str();
	}

private :

	const string _message;
};