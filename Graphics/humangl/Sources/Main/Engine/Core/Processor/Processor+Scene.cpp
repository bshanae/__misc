#include "Processor.h"

#include "Scene.h"
#include "Object.h"
#include "ComponentManipulator.h"

using namespace Engine;

void Processor::prepareObjects()
{
	for (const auto &object : _scene->getObjects())
	for (const auto &component : object->getComponents())
	{
		if (!ComponentManipulator::isMature(component))
			ComponentManipulator::prepare(component);
	}
}

void Processor::updateObjects()
{
	for (const auto &object : _scene->getObjects())
	for (const auto &component : object->getComponents())
	{
		if (ComponentManipulator::isMature(component))
			ComponentManipulator::update(component);
	}
}

void Processor::renderObjects()
{
	for (const auto &object : _scene->getObjects())
	for (const auto &component : object->getComponents())
	{
		if (ComponentManipulator::isMature(component))
			ComponentManipulator::render(component);
	}
}

void Processor::notifyObjectsAboutEndOfFrame()
{
	for (const auto &object : _scene->getObjects())
	for (const auto &component : object->getComponents())
	{
		ComponentManipulator::notifyAboutEndOfFrame(component);
	}
}