#pragma once

#include "engine/tools/Tools.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/exception.h"

class engine::Exception : public exception
{
public :

	Exception(const string &message = "") : _message(message)
	{}

	const char *what() const noexcept override
	{
		return _message.c_str();
	}

	const string &getMessage() const
	{
		return _message;
	}

private :

	const string _message;
};