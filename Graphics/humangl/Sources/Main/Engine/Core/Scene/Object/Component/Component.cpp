#include "Component.h"

using namespace Engine;

Component::Component()
{
	_isPrepared = false;
	_numberOfLivedFrames = 0;
}

void Component::initialized() {}

void Component::deinitialized() {}

void Component::prepared() {}

void Component::updated() {}

void Component::rendered() {}

std::shared_ptr<Object> Component::getObject() const
{
	return _object;
}