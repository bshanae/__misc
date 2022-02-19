#include "Module.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/serialization/Serialization.h"
#include "engine/modules/physics/settings/Settings.h"
#include "engine/modules/physics/algorithm/collision/collisionResolver/CollisionResolver.h"
#include "engine/modules/physics/components/rigidBody/RigidBody.h"
#include "engine/modules/physics/components/collider/planeCollider/PlaneCollider.h"
#include "engine/modules/physics/components/collider/sphereCollider/SphereCollider.h"
#include "engine/modules/physics/components/collider/boxCollider/BoxCollider.h"

using namespace engine::physics;

void Module::updateSimulation(float deltaTime)
{
	getInstance().resetCollisions();
	getInstance().detectCollisions();
	getInstance().resolveCollisions(deltaTime);

	getInstance().integrate(deltaTime);

	getInstance().performLinearProjection();
}

void Module::initializeInternally()
{
	serialization::registerComponent<RigidBody>();
	serialization::registerComponent<PlaneCollider>();
	serialization::registerComponent<SphereCollider>();
	serialization::registerComponent<BoxCollider>();

	Settings::load();
}

void Module::onSceneLaunchingInternal(const YAML::Node &metaNode)
{
	Settings::load();
}

void Module::onSceneLaunchedInternal()
{
	processScene(getScene());
	subscribe(getScene().componentAddedToObject, [this](Object &object, Component &component){ processComponent(object, component); });
}

void Module::onSceneClosingInternal()
{
	resetSimulation();
}

void Module::resetSimulation()
{
	resetCollisions();

	_colliders.clear();
	_rigidBodies.clear();
}

void Module::resetCollisions()
{
	for (auto [object, collider]: _colliders)
		collider->setCollision(nullptr);

	_collisions.clear();
}

void Module::detectCollisions()
{
	for (auto [object1, collider1] : _colliders)
	{
		if (collider1->isDisabled() or not collider1->isPrepared())
			continue;

		for (auto[object2, collider2]: _colliders)
		{
			if (collider1 == collider2)
				continue;

			if (collider2->isDisabled() or not collider2->isPrepared())
				continue;

			if (auto collision = collider1->testCollision(*collider2); collision != nullopt)
			{
				collision->complementWithColliders(collider1, collider2);

				_collisions.push_back(move(*collision));

				collider1->setCollision(&_collisions.back());
				collider2->setCollision(&_collisions.back());
			}
		}
	}
}

void Module::resolveCollisions(float deltaTime)
{
	for (const auto &collision : _collisions)
	{
		auto rigidBodyIterator1 = _rigidBodies.find(&collision.getCollider1()->getObject());
		auto rigidBodyIterator2 = _rigidBodies.find(&collision.getCollider2()->getObject());

		if (rigidBodyIterator1 != _rigidBodies.end() && rigidBodyIterator2 != _rigidBodies.end())
			CollisionResolver::resolveCollision(*rigidBodyIterator1->second, *rigidBodyIterator2->second, collision, deltaTime);
	}
}

void Module::integrate(float deltaTime)
{
	for (auto [object, rigidBody]: _rigidBodies)
		rigidBody->integrate(deltaTime);
}

void Module::performLinearProjection()
{
//	for (const auto &collision : _collisions)
//	{
//		auto rigidBodyIterator1 = _rigidBodies.find(&collision.getCollider1()->getObject());
//		auto rigidBodyIterator2 = _rigidBodies.find(&collision.getCollider2()->getObject());
//
//		if (rigidBodyIterator1 != _rigidBodies.end() && rigidBodyIterator2 != _rigidBodies.end())
//			::performLinearProjection(*rigidBodyIterator1->second, *rigidBodyIterator2->second, collision);
//	}
}

void Module::processScene(Scene &scene)
{
	scene.traverseObjects(
		[this](Object &object)
		{
			object.traverseComponents([this, &object](Component &component){ processComponent(object, component); });
		}
	);
}

void Module::processComponent(Object &object, Component &component)
{
	if (auto *collider = dynamic_cast<Collider *>(&component); collider != nullptr)
		_colliders[&object] = collider;
	if (auto *rigidBody = dynamic_cast<RigidBody *>(&component); rigidBody != nullptr)
		_rigidBodies[&object] = rigidBody;
}