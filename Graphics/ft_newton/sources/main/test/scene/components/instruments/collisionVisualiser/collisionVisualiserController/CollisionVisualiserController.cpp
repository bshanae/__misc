#include "CollisionVisualiserController.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/Object.h"
#include "test/scene/components/instruments/collisionVisualiser/CollisionVisualiser.h"

using namespace test;

CollisionVisualiserController::CollisionVisualiserController(Object &object) : Component(object)
{
	_collisionVisualiser = nullptr;
}

void CollisionVisualiserController::initializeInternally()
{
	const auto findManipulator = [this](Object &object)
	{
		if (auto *collisionVisualiser = object.trySelectComponent<CollisionVisualiser>(); collisionVisualiser != nullptr)
			_collisionVisualiser = collisionVisualiser;
	};

	getObject().getScene().traverseObjects(findManipulator);

	if (_collisionVisualiser == nullptr)
	{
		Debug::logError("CollisionVisualiserController", "Collision visualiser not found");
		markBad();
	}
}

void CollisionVisualiserController::onClicked(bool newState)
{
	_collisionVisualiser->setEnabled(newState);
}
