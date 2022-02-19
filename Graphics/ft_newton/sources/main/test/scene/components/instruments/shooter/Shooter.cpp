#include "Shooter.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/component/Component.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/environment/input/Input.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/rendering/components/camera/freeCamera/FreeCamera.h"
#include "engine/modules/rendering/components/model/Model.h"
#include "engine/modules/physics/components/rigidBody/RigidBody.h"
#include "engine/modules/physics/components/collider/sphereCollider/SphereCollider.h"
#include "engine/modules/physics/components/collider/boxCollider/BoxCollider.h"
#include "test/scene/components/renderers/debugModelRenderer/DebugModelRenderer.h"

using namespace test;

void Shooter::deserialize(Shooter &instance, const YAML::Node &node)
{
	instance._bulletKind = node["bullet kind"].as<std::string>();
	instance._bulletSize = node["bullet size"].as<glm::vec3>();
	instance._bulletMass = node["bullet mass"].as<float>();
	instance._shotForce = node["shot force"].as<float>();
}

Shooter::Shooter(Object &object) : Component(object)
{}

void Shooter::prepareInternally()
{
	Debug::logMessage("Shooter", "'Left mouse' - shoot.");

	findCamera();
	generateBullet();
	disable();
}

void Shooter::updateInternally(float timeDelta)
{
	if (Input::isPressed(Input::LeftMouse))
		shootBullet();
}

void Shooter::onDisabled()
{
	_bullet->disable();
}

void Shooter::findCamera()
{
	_camera = &getObject().getScene().selectObjectByTag("camera").selectComponent<FreeCamera>();
}

void Shooter::generateBullet()
{
	_bullet = &getObject().getScene().addObject("bullet");
	_bullet->disable();

	auto &transformation = _bullet->addComponent<Transformation>();
	transformation.setScale(_bulletSize);

	if (_bulletKind == "sphere")
	{
		transformation.setScale(_bulletSize[0]);
		_bullet->addComponent<Model>("sphere.fbx");

		auto &collider = _bullet->addComponent<SphereCollider>();
		collider.setRadius(_bulletSize[0] / 2.f);
	}
	else if (_bulletKind == "box")
	{
		transformation.setScale(_bulletSize);
		_bullet->addComponent<Model>("cube.fbx");

		auto &collider = _bullet->addComponent<BoxCollider>();
		collider.setSize(_bulletSize);
	}
	else
	{
		Debug::logError("Shooter", "Unknown bullet kind");
		markBad();
		return;
	}

	_bullet->addComponent<DebugModelRenderer>(Color::white);

	auto &rigidBody = _bullet->addComponent<RigidBody>();
	rigidBody.setMass(_bulletMass);
}

void Shooter::shootBullet()
{
	_bullet->enable();

	const auto orientation = engine::makeMatrixFromBasis(_camera->getFront(), _camera->getUp(), _camera->getRight());

	_bullet->selectComponent<Transformation>().setOrientation(orientation);
	_bullet->selectComponent<Transformation>().moveTo(_camera->getPosition() + _camera->getFront() * 5.f);

	_bullet->selectComponent<RigidBody>().resetVelocity();
	_bullet->selectComponent<RigidBody>().applyForce(_camera->getFront() * _shotForce);
}