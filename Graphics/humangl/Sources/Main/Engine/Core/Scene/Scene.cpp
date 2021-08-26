#include "Scene.h"

#include "Object.h"

using namespace Engine;

Scene::Scene()
{
	_isClosed = false;
}

bool Scene::isClosed() const
{
	return _isClosed;
}

void Scene::close()
{
	_isClosed = true;
}

std::vector<std::shared_ptr<Object>> Scene::getObjects() const
{
	return _objects;
}

void Scene::addObject(const std::shared_ptr<Object> &object)
{
	_objects.push_back(object);
	object->_scene = shared_from_this();
}

std::shared_ptr<Object> Scene::findObject(const std::string &name) const
{
	for (const auto &object : _objects)
	{
		if (object->_name == name)
			return object;
	}

	return nullptr;
}

std::shared_ptr<Object> Scene::findMandatoryObject(const std::string &name) const
{
	auto object = findObject(name);

	if (object == nullptr)
		throw Exception("Can't find mandatory object '" + name + "'");

	return object;
}