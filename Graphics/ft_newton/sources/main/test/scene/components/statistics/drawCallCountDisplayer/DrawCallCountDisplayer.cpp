#include "DrawCallCountDisplayer.h"

#include "engine/core/scene/object/Object.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/rendering/module/Module.h"
#include "engine/modules/ui/components/text/Text.h"
#include "engine/modules/ui/components/text/textRenderer/TextRenderer.h"

using namespace test;

DrawCallCountDisplayer::DrawCallCountDisplayer(Object &object) : Component(object), _textFinder(*this)
{
}

void DrawCallCountDisplayer::updateInternally(float deltaTime)
{
	_textFinder().setText("Draw calls: " + std::to_string(RenderingModule::getNumberOfDrawCalls()));
}