#pragma once

#include "YamlCpp.h"
#include "YamlCppExtensions.h"
#include "Exception.h"

namespace Engine
{
	class Configuration;
}

class Engine::Configuration final
{
public :

	class FileNotFound : public Exception {};
	class FieldNotFound : public Exception {};

	explicit Configuration(const std::string &configurationName);

	template <typename T>
	T get(const std::string &key) const
	{
		try
		{
			return _root[key].as<T>();
		}
		catch (const YAML::InvalidNode &exception)
		{
			throw FieldNotFound();
		}
	}

private :

	static const inline std::string directory = "Resources/Configurations";
	YAML::Node _root;
};