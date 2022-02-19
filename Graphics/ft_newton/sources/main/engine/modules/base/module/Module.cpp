#include "Module.h"

#include "engine/core/scene/object/serialization/Serialization.h"
#include "engine/modules/base/components/transformation/Transformation.h"

using namespace engine::base;

void Module::initializeInternally()
{
	serialization::registerComponent<Transformation>();
}