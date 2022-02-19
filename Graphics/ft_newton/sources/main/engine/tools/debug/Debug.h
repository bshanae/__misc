#pragma once

#include "engine/tools/Tools.h"

#include "engine/tools/constants/Constants.h"
#include "engine/tools/exceptions/FatalException.h"
#include "engine/tools/debug/ColorModifier.h"

class engine::Debug
{
public :

	Debug() = delete;
	~Debug() = delete;

	static inline void assume(bool state, const string &message = "")
	{
		if constexpr (constants::debug)
		{
			if (!state)
				throw FatalException("Assumption failed : " + message);
		}
	}

	static inline void logMessage(const string &message)
	{
		cout << message << endl;
	}

	static inline void logMessage(const string &entity, const string &message)
	{
		cout << "[" << entity << "] " << message << endl;
	}

	static inline void logWarning(const string &message)
	{
		cout << ColorModifier::Yellow() << message << ColorModifier::Default() << endl;
	}

	static inline void logWarning(const string &entity, const string &message)
	{
		cout << ColorModifier::Yellow() << "[" << entity << "] " << message << ColorModifier::Default() << endl;
	}

	static inline void logError(const string &entity, const string &message)
	{
		cout << ColorModifier::Red() << "[" << entity << "] " << message << ColorModifier::Default() << endl;
	}

	static inline void invokeFatalError(const string &message)
	{
		throw FatalException(message);
	}

	static inline void invokeFatalError(const string &entity, const string &message)
	{
		throw FatalException("[" + entity + "] " + message);
	}
};