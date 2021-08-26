#include "Object.h"

#include "Component.h"
#include "ComponentManipulator.h"

using namespace Engine;

const std::string &Object::getName() const
{
	return _name;
}

void Object::setName(const std::string &name)
{
	_name = name;
}

std::shared_ptr<Scene> Object::getScene() const
{
	return _scene;
}

void Object::addComponent(const std::shared_ptr<Component> &component)
{
	ComponentManipulator::initialize(component);

	component->_object = shared_from_this();
	_components.push_back(component);
}

const std::list<std::shared_ptr<Component>> &Object::getComponents() const
{
	return _components;
}