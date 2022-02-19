#pragma once

#include "engine/core/Core.h"

#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/external/std/type.h"
#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/std/queue.h"
#include "engine/tools/external/std/pair.h"
#include "engine/tools/debug/Debug.h"
#include "engine/tools/templates/eventSystem/EventSystem.h"

class engine::Object final
{
#pragma mark events

public :

	Event<> enabled;
	Event<> disabled;
	Event<Object &> childAdded;
	Event<Component &> componentAdded;

#pragma mark construction/desctruction

public :

	Object(Scene &scene, Object *parent, const string &name, const string &tag);
	Object(const Object &) = delete;

	~Object();

#pragma mark operators

public :

	Object &operator = (const Object &) = delete;

#pragma mark properties

public :

	inline Scene &getScene() const
	{
		return _scene;
	}

	inline const string &getName() const
	{
		return _name;
	}

	inline const string &getTag() const
	{
		return _tag;
	}

private :

	Scene &_scene;
	string _name;
	string _tag;

#pragma mark hierarchy

public :

	inline const Object *getParent() const
	{
		return _parent;
	}

	Object &addChild(const string &name, const string &tag = "");

	void fetchChildren();

	/// Return copy of vector with children. Costly operation.
	vector<Object *> getChildren() const;

	/// Visit children, grandchildren and so on.
	void traverseDescendants(const function<void (Object &)> &action) const;

	Object *findChild(const function<bool (Object &)> &selector) const;

private :

	Object *_parent;
	vector<unique_ptr<Object>> _children;
	queue<unique_ptr<Object>> _newChildren;
	mutable bool _isTraversingDescendants;

#pragma mark components

public :

	template <typename TComponent, typename ...TArgs>
	TComponent &addComponent(TArgs &&...args)
	{
		auto *component = new TComponent(*this, args...);
		if (isSceneLaunched())
			component->initialize();

		_newComponents.emplace(unique_ptr<Component>(component), type_index(typeid(TComponent)));
		return *component;
	}

	void fetchComponents();

	template <typename T>
	T &selectComponent() const
	{
		const auto result = trySelectComponent<T>();

		if (result == nullptr)
			Debug::invokeFatalError("Object", "A component not found.");

		return *result;
	}

	template <typename T>
	T *trySelectComponent() const
	{
		if constexpr (std::is_final<T>::value and std::is_base_of<Component, T>::value)
			return trySelectComponentFast<T>();
		else
			return trySelectComponentSlowly<T>();
	}

	template <typename T>
	bool hasComponent() const
	{
		return trySelectComponent<T>() != nullptr;
	}

	/// Return copy of vector with components. Costly operation.
	const vector<Component *> getComponents() const;

	void traverseComponents(const function<void (Component &)> &action) const;

private :

	vector<unique_ptr<Component>> _components;
	queue<pair<unique_ptr<Component>, type_index>> _newComponents;
	map<type_index, Component *> _componentsByType;
	mutable bool _isTraversingComponents;

	bool isSceneLaunched() const;

	template <typename T>
	T *trySelectComponentFast() const
	{
		if (auto iterator = _componentsByType.find(type_index(typeid(T))); iterator != _componentsByType.end())
		{
			if constexpr (constants::debug)
				Debug::assume(dynamic_cast<T *>(iterator->second) != nullptr, "Selected component has wrong type.");

			return static_cast<T *>(iterator->second);
		}

		return nullptr;
	}

	template <typename T>
	T *trySelectComponentSlowly() const
	{
		for (const auto &component : _components)
		{
			if (auto typedComponent = dynamic_cast<T *>(component.get()); typedComponent != nullptr)
				return typedComponent;
		}

		return nullptr;
	}

#pragma mark properties

public :

	inline bool isEnabled() const
	{
		return _isEnabled and isParentEnabled();
	}

	inline bool isDisabled() const
	{
		return not _isEnabled or not isParentEnabled();
	}

	void enable();

	void disable();

private :

	bool _isEnabled;

	bool isParentEnabled() const;
};