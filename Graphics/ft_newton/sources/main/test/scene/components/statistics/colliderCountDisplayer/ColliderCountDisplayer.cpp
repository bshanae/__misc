#include "ColliderCountDisplayer.h"

#include "engine/core/scene/object/Object.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/physics/module/Module.h"
#include "engine/modules/ui/components/text/Text.h"
#include "engine/modules/ui/components/text/textRenderer/TextRenderer.h"

using namespace test;

ColliderCountDisplayer::ColliderCountDisplayer(Object &object) : Component(object), _textFinder(*this)
{
}

void ColliderCountDisplayer::updateInternally(float deltaTime)
{
	_textFinder().setText("Colliders: " + std::to_string(PhysicsModule::getNumberOfColliders()));
}