#include "Processor.h"

#include "engine/core/settings/Settings.h"
#include "engine/environment/environment/Environment.h"
#include "engine/environment/input/Input.h"

using namespace engine;

void Processor::processEvents()
{
	Environment::pollEvents();
}

void Processor::processInput()
{
	Input::refresh();
}

void Processor::resetTimeInfo()
{
	_timeAtLastFrame = Environment::getScaledTime();
	_timeBetweenFrames = 0;

	_timeAccumulator = 0;
	_internalTime = 0;
}

void Processor::updateTimeInfo()
{
	const auto timeAtCurrentFrame = Environment::getScaledTime();

	_timeBetweenFrames = timeAtCurrentFrame - _timeAtLastFrame;
	_timeAtLastFrame = timeAtCurrentFrame;

	_timeAccumulator += _timeBetweenFrames;
	_internalTimeBetweenFrames = 0;
}

float Processor::tryUpdateInternalTime()
{
	const auto fixedTimeStep = Settings::getFixedTimeStep();

	if (_timeAccumulator > fixedTimeStep)
	{
		_timeAccumulator -= fixedTimeStep;

		_internalTime += fixedTimeStep;
		_internalTimeBetweenFrames += fixedTimeStep;

		return fixedTimeStep;
	}
	else
	{
		return 0;
	}
}