#include "ManipulatorController.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/Object.h"
#include "test/scene/components/instruments/manipulator/Manipulator.h"

using namespace test;

ManipulatorController::ManipulatorController(Object &object) : Component(object)
{
	_manipulator = nullptr;
}

void ManipulatorController::initializeInternally()
{
	const auto findManipulator = [this](Object &object)
	{
		if (auto *manipulator = object.trySelectComponent<Manipulator>(); manipulator != nullptr)
			_manipulator = manipulator;
	};

	getObject().getScene().traverseObjects(findManipulator);

	if (_manipulator == nullptr)
	{
		Debug::logError("ManipulatorController", "Manipulator not found");
		markBad();
	}
}

void ManipulatorController::onClicked(bool newState)
{
	_manipulator->setEnabled(newState);
}
