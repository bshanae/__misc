#include "engine/core/scene/object/Object.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/external/std/algorithm.h"

using namespace engine;

Object::Object(Scene &scene, Object *parent, const string &name, const string &tag) : _scene(scene), _parent(parent), _name(name), _tag(tag)
{
	_isEnabled = true;
	_isTraversingDescendants = false;
	_isTraversingComponents = false;
}

Object::~Object()
{
	for (const auto &component : _components)
		component->deinitialize();
}

Object &Object::addChild(const string &name, const string &tag)
{
	_newChildren.emplace(new Object(getScene(), this, name, tag));
	return *_newChildren.back();
}

void Object::fetchChildren()
{
	if (_isTraversingDescendants)
	{
		Debug::logError("Object", "Can't fetch children while traversing them.");
		return;
	}

	while (not _newChildren.empty())
	{
		auto newChild = move(_newChildren.front());
		_newChildren.pop();

		_children.push_back(move(newChild));
		childAdded.invoke(*_children.back());
	}
}

vector<Object *> Object::getChildren() const
{
	vector<Object *> result;
	transform(
		_children.begin(),
		_children.end(),
		back_inserter(result),
		[](const unique_ptr<Object> &object){ return object.get(); }
	);

	return result;
}

void Object::traverseDescendants(const function<void (Object &)> &action) const
{
	_isTraversingDescendants = true;

	for (const auto &child : _children)
	{
		action(*child);
		child->traverseDescendants(action);
	}

	_isTraversingDescendants = false;
}

Object *Object::findChild(const function<bool (Object &)> &selector) const
{
	for (const auto &child : _children)
	{
		if (selector(*child))
			return child.get();

		if (auto *result = child->findChild(selector); result != nullptr)
			return result;
	}

	return nullptr;
}

void Object::fetchComponents()
{
	if (_isTraversingComponents)
	{
		Debug::logError("Object", "Can't fetch components while traversing them.");
		return;
	}

	while (not _newComponents.empty())
	{
		auto [newComponent, typeIndex] = move(_newComponents.front());
		_newComponents.pop();

		_components.push_back(move(newComponent));

		if (_componentsByType.find(typeIndex) != _componentsByType.end())
			Debug::logWarning("Object", "Component of the same type already present.");
		_componentsByType[typeIndex] = _components.back().get();

		componentAdded.invoke(*_components.back());
	}
}

const vector<Component *> Object::getComponents() const
{
	vector<Component *> result;
	transform(
		_components.begin(),
		_components.end(),
		back_inserter(result),
		[](const unique_ptr<Component> &component){ return component.get(); }
	);

	return result;
}

void Object::traverseComponents(const function<void (Component &)> &action) const
{
	_isTraversingComponents = true;

	for (const auto &component : _components)
		action(*component);

	_isTraversingComponents = false;
}

bool Object::isSceneLaunched() const
{
	return _scene.isLaunched();
}

void Object::enable()
{
	if (_isEnabled)
		return;

	_isEnabled = true;
	enabled.invoke();

	traverseDescendants([](Object &child){ child.enabled.invoke(); });
}

void Object::disable()
{
	if (not _isEnabled)
		return;

	_isEnabled = false;
	disabled.invoke();

	traverseDescendants([](Object &child){ child.disabled.invoke(); });
}

bool Object::isParentEnabled() const
{
	return _parent != nullptr ? _parent->isEnabled() : true;
}