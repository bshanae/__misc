#include "FpsDisplayer.h"

#include "engine/core/scene/object/Object.h"
#include "engine/environment/environment/Environment.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/rendering/module/Module.h"
#include "engine/modules/ui/components/text/Text.h"
#include "engine/modules/ui/components/text/textRenderer/TextRenderer.h"

using namespace test;

FpsDisplayer::FpsDisplayer(Object &object) : Component(object), _textFinder(*this)
{
	_lastSecondStartTime = 0.f;
	_framesCount = 0.f;
}

void FpsDisplayer::updateInternally(float deltaTime)
{
	auto currentTime = Environment::getRealTime();
	if (currentTime - _lastSecondStartTime >= 1.f)
	{
		_textFinder().setText("FPS: " + std::to_string(_framesCount));

		_lastSecondStartTime = currentTime;
		_framesCount = 0;
	}

	_framesCount++;
}