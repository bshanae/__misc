#include "Manipulator.h"

#include "engine/core/scene/Scene.h"
#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/environment/input/Input.h"
#include "engine/modules/base/components/transformation/Transformation.h"
#include "engine/modules/rendering/components/model/Model.h"
#include "engine/modules/physics/components/rigidBody/RigidBody.h"
#include "test/scene/components/renderers/debugModelRenderer/DebugModelRenderer.h"

using namespace test;

void Manipulator::deserialize(Manipulator &instance, const YAML::Node &node)
{
	instance._impulseFactor = node["impulse factor"].as<float>();
}

Manipulator::Manipulator(Object &object) : Component(object), _cameraFinder(object.getScene()), _sceneIterator(object.getScene(), objectFilter)
{}

void Manipulator::initializeInternally()
{
	generateHint();
}

void Manipulator::prepareInternally()
{
	Debug::logMessage("Manipulator", "'t/g/f/h/r/y' - move an object, 'left/right/up/down' - rotate object, '+' - push, '-' - stop, 'enter' - switch object.");

	_sceneIterator.loadTargets();
	disable();
}

void Manipulator::updateInternally(float timeDelta)
{
	updateHint();

	processTargetChange();
	processMovement(timeDelta);
}

void Manipulator::onEnabled()
{
	_hint->enable();
}

void Manipulator::onDisabled()
{
	_hint->disable();
}

void Manipulator::generateHint()
{
	_hint = &getObject().getScene().addObject("hint");
	_hint->disable();

	_hint->addComponent<Transformation>();
	_hint->addComponent<Model>("cube.fbx");
	_hint->addComponent<DebugModelRenderer>(Color::red);
}

void Manipulator::updateHint()
{
	if (not _sceneIterator.hasTarget())
	{
		_hint->disable();
		return;
	}
	else
	{
		_hint->enable();
	}

	auto &hintTransformation = _hint->selectComponent<Transformation>();

	const auto &targetTransformation = _sceneIterator.getTarget()->selectComponent<Transformation>();
	const auto targetPosition = targetTransformation.getGlobalPosition();
	const auto targetRotation = targetTransformation.getRotationMatrix();
	const auto targetScale = targetTransformation.getScale();

	hintTransformation.setScale(vec3(targetScale[0] / 2.f + 1.f, 0.5f, 0.5f));
	hintTransformation.setOrientation(targetRotation);
	hintTransformation.moveTo(targetPosition + vec3(targetRotation[0]) * targetScale[0] / 2.f);
}

void Manipulator::processTargetChange()
{
	if (Input::isPressed(Input::Enter))
		_sceneIterator.incrementTarget();
}

void Manipulator::processMovement(float timeDelta)
{
	if (not _sceneIterator.hasTarget())
		return;

	static const auto movementSpeed = 14.f;
	static const auto rotationSpeed = 1.5f;

	auto &transformation = _sceneIterator.getTarget()->selectComponent<Transformation>();
	auto &rigidBody = _sceneIterator.getTarget()->selectComponent<RigidBody>();

	if (Input::isHeld(Input::F))
		transformation.moveBy(_cameraFinder().getRight() * -movementSpeed * timeDelta);
	else if (Input::isHeld(Input::H))
		transformation.moveBy(_cameraFinder().getRight() * +movementSpeed * timeDelta);
	else if (Input::isHeld(Input::T))
		transformation.moveBy(_cameraFinder().getFront() * +movementSpeed * timeDelta);
	else if (Input::isHeld(Input::G))
		transformation.moveBy(_cameraFinder().getFront() * -movementSpeed * timeDelta);
	else if (Input::isHeld(Input::R))
		transformation.moveBy(_cameraFinder().getUp() * +movementSpeed * timeDelta);
	else if (Input::isHeld(Input::Y))
		transformation.moveBy(_cameraFinder().getUp() * -movementSpeed * timeDelta);

	if (Input::isHeld(Input::Left))
		transformation.rotateAround(_cameraFinder().getUp(), -rotationSpeed * timeDelta);
	else if (Input::isHeld(Input::Right))
		transformation.rotateAround(_cameraFinder().getUp(), +rotationSpeed * timeDelta);
	else if (Input::isHeld(Input::Up))
		transformation.rotateAround(_cameraFinder().getRight(), -rotationSpeed * timeDelta);
	else if (Input::isHeld(Input::Down))
		transformation.rotateAround(_cameraFinder().getRight(), +rotationSpeed * timeDelta);

	if (Input::isHeld(Input::Plus))
	{
		rigidBody.applyForce(transformation.getRotationMatrix()[0] * rigidBody.getMass() * _impulseFactor);
	}
	else if (Input::isHeld(Input::Minus))
	{
		rigidBody.resetVelocity();
	}
}

bool Manipulator::objectFilter(Object &object)
{
	return object.getTag() == "interactable" and object.hasComponent<Transformation>() and object.hasComponent<RigidBody>();
}