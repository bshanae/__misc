#include "CollisionVisualiser.h"

#include "engine/core/processor/Processor.h"
#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/Object.h"
#include "engine/core/scene/object/component/Component.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/rendering/components/model/Model.h"
#include "engine/modules/physics/module/Module.h"
#include "test/scene/components/renderers/debugModelRenderer/DebugModelRenderer.h"

using namespace test;

CollisionVisualiser::CollisionVisualiser(Object &object) : Component(object)
{}

void CollisionVisualiser::prepareInternally()
{
	for (auto i = 0; i < 10; i++)
		generateSphere();

	disable();
}

void CollisionVisualiser::updateInternally(float timeDelta)
{
	auto i = 0;

	for (const auto &collision : PhysicsModule::getCollisions())
	for (const auto &contact : collision.getContacts())
	{
		if (i >= _spheres.size())
		{
			generateSphere();
		}
		else
		{
			_spheres[i]->enable();
			_spheres[i]->selectComponent<Transformation>().moveTo(contact.position);
		}

		i++;
	}

	for (; i < _spheres.size(); i++)
		_spheres[i]->disable();
}

void CollisionVisualiser::onDisabled()
{
	for (auto *sphere : _spheres)
		sphere->disable();
}

void CollisionVisualiser::generateSphere()
{
	auto &object = getObject().getScene().addObject("sphere-" + std::to_string(_spheres.size() - 1));

	auto &transformation = object.addComponent<Transformation>();
	transformation.setScale(0.5f);

	object.addComponent<Model>("sphere.fbx");
	object.addComponent<DebugModelRenderer>(Color::red);

	_spheres.push_back(&object);
}