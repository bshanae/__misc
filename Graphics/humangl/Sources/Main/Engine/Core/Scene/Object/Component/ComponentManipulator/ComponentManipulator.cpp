#include "ComponentManipulator.h"

#include "Exception.h"
#include "Component.h"

using namespace Engine;

bool ComponentManipulator::isMature(const std::shared_ptr<Component> &component)
{
	return component->_isPrepared and component->_numberOfLivedFrames > 0;
}

void ComponentManipulator::initialize(const std::shared_ptr<Component> &component)
{
	component->initialized();
}

void ComponentManipulator::deinitialize(const std::shared_ptr<Component> &component)
{
	component->deinitialized();
}

void ComponentManipulator::prepare(const std::shared_ptr<Component> &component)
{
	assertImmature(component);
	component->prepared();
	component->_isPrepared = true;
}

void ComponentManipulator::update(const std::shared_ptr<Component> &component)
{
	assertMature(component);
	component->updated();
}

void ComponentManipulator::render(const std::shared_ptr<Component> &component)
{
	assertMature(component);
	component->rendered();
}

void ComponentManipulator::notifyAboutEndOfFrame(const std::shared_ptr<Component> &component)
{
	component->_numberOfLivedFrames++;
}

void ComponentManipulator::assertImmature(const std::shared_ptr<Component> &component)
{
	if (isMature(component))
		throw Exception("Component expected to be immature");
}

void ComponentManipulator::assertMature(const std::shared_ptr<Component> &component)
{
	if (not isMature(component))
		throw Exception("Component expected to be mature");
}
