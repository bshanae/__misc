#include "Component.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/constants/Constants.h"
#include "engine/tools/debug/Debug.h"

using namespace engine;

Component::Component(Object &object) : _object(object)
{
	_isPrepared = false;
	_isEnabled = true;
	_isBad = false;
	_numberOfLivedFrames = 0;

	subscribe(_object.enabled, [this](){ onObjectEnabled(); });
	subscribe(_object.disabled, [this](){ onObjectDisabled(); });
}

bool Component::isEnabled() const
{
	return _object.isEnabled() and _isEnabled;
}

bool Component::isDisabled() const
{
	return _object.isDisabled() or not _isEnabled;
}

bool Component::isMature()
{
	return _isPrepared and _numberOfLivedFrames > 0;
}

void Component::enable()
{
	if (_isBad)
	{
		Debug::logWarning("Component", "Can't enabled bad component");
		return;
	}

	if (_isEnabled)
		return;

	_isEnabled = true;
	onEnabled();
}

void Component::disable()
{
	if (not _isEnabled)
		return;

	_isEnabled = false;
	onDisabled();
}

void Component::setEnabled(bool state)
{
	if (state)
		enable();
	else
		disable();
}

void Component::markBad()
{
	disable();
	_isBad = true;
}

void Component::initialize()
{
	initializeInternally();
}

void Component::deinitialize()
{
	deinitializeInternally();
}

void Component::prepare()
{
	assertImmature();

	preparing.invoke();

	prepareInternally();
	_isPrepared = true;

	prepared.invoke();
}

void Component::processInput()
{
	assertMature();
	processInputInternally();
}

void Component::update(float timeDelta)
{
	assertMature();
	updateInternally(timeDelta);
}

void Component::notifyAboutEndOfFrame()
{
	_numberOfLivedFrames++;
}

void Component::assertImmature()
{
	if constexpr (constants::debug)
	{
		if (isMature())
			Debug::invokeFatalError("Component", "Component expected to be immature");
	}
}

void Component::assertMature()
{
	if constexpr (constants::debug)
	{
		if (not isMature())
			Debug::invokeFatalError("Component", "Component expected to be mature");
	}
}

void Component::onObjectEnabled()
{
	onEnabled();
}

void Component::onObjectDisabled()
{
	onDisabled();
}