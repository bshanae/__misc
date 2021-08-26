#pragma once

#include <list>
#include <memory>
#include <string>

#include "Exception.h"

namespace Engine
{
	class Scene;
	class Object;
	class Component;
}

class Engine::Object final : public std::enable_shared_from_this<Engine::Object>
{
	friend class Scene;

public :

	Object() = default;
	virtual ~Object() = default;

	const std::string &getName() const;
	void setName(const std::string &name);

	std::shared_ptr<Scene> getScene() const;

	void addComponent(const std::shared_ptr<Component> &component);
	const std::list<std::shared_ptr<Component>> &getComponents() const;

	template <typename T>
	std::shared_ptr<T> findComponent()
	{
		for (const auto &component : _components)
		{
			auto typedComponent = std::dynamic_pointer_cast<T>(component);
			if (typedComponent != nullptr)
				return typedComponent;
		}

		return nullptr;
	}

	template <typename T>
	std::shared_ptr<T> findMandatoryComponent()
	{
		auto component = findComponent<T>();

		if (component == nullptr)
			throw Exception("Mandatory component not found");

		return component;
	}

	template <typename T>
	std::vector<std::shared_ptr<T>> findManyComponents()
	{
		auto vector = std::vector<std::shared_ptr<T>>();

		for (const auto &component : _components)
		{
			auto typedComponent = std::dynamic_pointer_cast<T>(component);
			if (typedComponent != nullptr)
				vector.push_back(typedComponent);
		}

		return vector;
	}

private :

	std::string _name;
	std::shared_ptr<Scene> _scene;
	std::list<std::shared_ptr<Component>> _components;
};