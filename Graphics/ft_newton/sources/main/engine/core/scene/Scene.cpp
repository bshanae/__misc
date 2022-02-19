#include "engine/core/scene/Scene.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/std/algorithm.h"
#include "engine/tools/debug/Debug.h"
#include "engine/core/scene/object/component/Component.h"

using namespace engine;

Scene::Scene(const string &fileName) : _fileName(fileName)
{
	_isLaunched = false;
	_isClosed = false;
	_isTraversingObjects = false;
}

Scene::~Scene()
{}

void Scene::launch()
{
	_isLaunched = true;

	fetch();

	static const auto initializeComponent = [](Component &component){ component.initialize(); };
	static const auto initializeComponentsInObject = [](Object &object){ object.traverseComponents(initializeComponent); };
	traverseObjects(initializeComponentsInObject);

	launched.invoke();
}

void Scene::close()
{
	_isClosed = true;
	_objects.clear();
}

Object &Scene::addObject(const string &name, const string &tag)
{
	_newObjects.emplace(new Object(*this, nullptr, name, tag));
	return *_newObjects.back();
}

void Scene::fetch()
{
	if (not _isLaunched)
	{
		Debug::logError("Scene", "Fetching is not allowed before scene is launched.");
		return;
	}

	// Fetching should be done in this exact order.
	fetchObjects();
	traverseObjects(
		[](Object &object)
		{
			object.fetchChildren();
			object.fetchComponents();
		}
	);
}

vector<Object *> Scene::getTopObjects() const
{
	vector<Object *> result;
	transform(
		_objects.begin(),
		_objects.end(),
		back_inserter(result),
		[](const unique_ptr<Object> &object){ return object.get(); }
	);

	return result;
}

void Scene::traverseObjects(const function<void (Object &)> &action) const
{
	_isTraversingObjects = true;

	for (const auto &object : _objects)
	{
		action(*object);
		object->traverseDescendants(action);
	}

	_isTraversingObjects = false;
}

Object &Scene::selectObjectByTag(const string &tag) const
{
	auto *result = *_tagGroups.at(tag).begin();
	if (result == nullptr)
	{
		Debug::invokeFatalError("Scene", "Object with tag '" + tag + "' not found");
		throw nullptr;
	}

	return *result;
}

Object *Scene::trySelectObjectByTag(const string &tag) const
{
	if (const auto iterator = _tagGroups.find(tag); iterator != _tagGroups.end())
	{
		if (iterator->second.size() > 0)
			return *iterator->second.begin();
	}

	return nullptr;
}

const set<Object *> &Scene::selectAllObjectsByTag(const string &tag) const
{
	if (auto iterator = _tagGroups.find(tag); iterator != _tagGroups.end())
	{
		return iterator->second;
	}
	else
	{
		Debug::invokeFatalError("Scene", "Objects with tag '" + tag + "' not found");
		throw nullptr;
	}
}

void Scene::processNewObject(Object &object)
{
	if (object.getTag() != "")
		_tagGroups[object.getTag()].insert(&object);

	objectAdded.invoke(object);

	subscribe(object.childAdded,[this](Object &child){ processNewObject(child); });
	subscribe(object.componentAdded,[this, &object](Component &component){ componentAddedToObject.invoke(object, component); });

	for (auto *child : object.getChildren())
		processNewObject(*child);
}

void Scene::fetchObjects()
{
	if (_isTraversingObjects)
	{
		Debug::logError("Scene", "Can't fetch objects while traversing them.");
		return;
	}

	while (not _newObjects.empty())
	{
		auto newObject = move(_newObjects.front());
		_newObjects.pop();

		_objects.push_back(move(newObject));
		processNewObject(*_objects.back());
	}
}