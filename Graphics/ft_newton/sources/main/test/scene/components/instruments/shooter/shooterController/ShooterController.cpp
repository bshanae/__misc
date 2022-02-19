#include "ShooterController.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/Object.h"
#include "test/scene/components/instruments/shooter/Shooter.h"

using namespace test;

ShooterController::ShooterController(Object &object) : Component(object)
{
	_shooter = nullptr;
}

void ShooterController::initializeInternally()
{
	const auto findManipulator = [this](Object &object)
	{
		if (auto *shooter = object.trySelectComponent<Shooter>(); shooter != nullptr)
			_shooter = shooter;
	};

	getObject().getScene().traverseObjects(findManipulator);

	if (_shooter == nullptr)
	{
		Debug::logError("ShooterController", "Shooter not found");
		markBad();
	}
}

void ShooterController::onClicked(bool newState)
{
	_shooter->setEnabled(newState);
}
