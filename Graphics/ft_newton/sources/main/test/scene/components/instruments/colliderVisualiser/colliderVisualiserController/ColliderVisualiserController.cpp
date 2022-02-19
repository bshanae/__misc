#include "ColliderVisualiserController.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/Object.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/physics/components/collider/Collider.h"
#include "test/scene/components/instruments/colliderVisualiser/ColliderVisualiser.h"

using namespace test;

ColliderVisualiserController::ColliderVisualiserController(Object &object) : Component(object)
{
}

void ColliderVisualiserController::onClicked(bool newState)
{
	const auto selectObjectWithColliderRenderer = [](Object &testObject)
	{
		return testObject.trySelectComponent<ColliderVisualiser>() != nullptr;
	};

	const auto createObjectWithColliderRenderer = [](Object &parent)
	{
		auto &object = parent.addChild("collider renderer");

		object.addComponent<Transformation>();
		object.addComponent<ColliderVisualiser>(parent.selectComponent<Collider>());

		return &object;
	};

	const auto processObject = [newState, &selectObjectWithColliderRenderer, &createObjectWithColliderRenderer](Object &object)
	{
		if (object.trySelectComponent<Collider>() != nullptr)
		{
			auto childWithColliderRenderer = object.findChild(selectObjectWithColliderRenderer);

			if (childWithColliderRenderer == nullptr)
				childWithColliderRenderer = createObjectWithColliderRenderer(object);

			if (newState)
				childWithColliderRenderer->enable();
			else
				childWithColliderRenderer->disable();
		}
	};

	getObject().getScene().traverseObjects(processObject);
}
