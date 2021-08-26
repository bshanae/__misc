#pragma once

#include <memory>

#include "Exception.h"

namespace Engine
{
	template <typename>
	class Singleton;
}

template <typename T>
class Engine::Singleton
{
public :

	class InstanceAlreadyConstructed : public Exception {};

	Singleton() = default;
	virtual ~Singleton() = default;

	static void instantiate()
	{
		if (_instance != nullptr)
			throw InstanceAlreadyConstructed();

		_instance = std::make_shared<T>();
	}

	static std::shared_ptr<T> getInstance()
	{
		if (_instance == nullptr)
			instantiate();

		return _instance;
	}

private :

	static inline std::shared_ptr<T> _instance;
};