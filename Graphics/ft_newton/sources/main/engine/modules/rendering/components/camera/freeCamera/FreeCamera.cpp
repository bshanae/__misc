#include "FreeCamera.h"

#include "engine/core/scene/object/Object.h"
#include "engine/environment/window/Window.h"
#include "engine/environment/input/Input.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/tools/mathematics/Mathematics.h"

using namespace engine::rendering;

void FreeCamera::deserialize(FreeCamera &instance, const YAML::Node &node)
{
	instance._rotationSpeed = node["rotation speed"].as<float>();
	instance._movementSpeed = node["movement speed"].as<float>();

	instance._fov = radians(node["fov"].as<float>(radians(45.f)));

	instance._nearPlane = node["near plane"].as<float>(1.f);
	instance._farPlane = node["far plane"].as<float>(1000.f);
}

FreeCamera::FreeCamera(Object &object) : Camera(object)
{
	_fov = 0;
	_nearPlane = 0;
	_farPlane = 0;
}

void FreeCamera::initializeInternally()
{
	Camera::initializeInternally();
	recalculate();
}

void FreeCamera::updateInternally(float timeDelta)
{
	const auto wasRotated = processRotationInput(timeDelta);
	const auto wasMoved = processMovementInput(timeDelta);

	if (wasMoved or wasRotated)
		recalculate();
}

bool FreeCamera::processRotationInput(float timeDelta)
{
	const auto mouseOffset = engine::Input::getMouseOffset();

	const auto pitchChange = mouseOffset.y * _rotationSpeed * timeDelta;
	const auto yawChange = mouseOffset.x * _rotationSpeed * timeDelta;

	if (approximatelyZero(yawChange) and approximatelyZero(pitchChange))
		return false;

	_transformationFinder().rotateAround(vec3(1.f, 0.f, 0.f), pitchChange);
	_transformationFinder().rotateAround(_transformationFinder().getLocalOrientation() * glm::vec3(0.0f, 1.0f, 0.0f), yawChange);

	return true;
}

bool FreeCamera::processMovementInput(float timeDelta)
{
	auto movement = vec3();

	if (engine::Input::isPressedOrHeld(engine::Input::A))
		movement += getRight() * -1.f;
	else if (engine::Input::isPressedOrHeld(engine::Input::D))
		movement += getRight();

	if (engine::Input::isPressedOrHeld(engine::Input::W))
		movement += getFront();
	else if (engine::Input::isPressedOrHeld(engine::Input::S))
		movement += getFront() * -1.f;

	if (engine::Input::isHeld(engine::Input::Q))
		movement += vec3(0, -1, 0);

	if (engine::Input::isHeld(engine::Input::E))
		movement += vec3(0, 1, 0);

	if (approximatelyZero(movement))
		return false;

	_transformationFinder().moveBy(normalize(movement) * _movementSpeed * timeDelta);
	return true;
}

void FreeCamera::recalculate()
{
	_projection = perspective(_fov, Window::getAspectRatio(), _nearPlane, _farPlane);
	_view = lookAt(getPosition(), getPosition() + getFront(), getUp());
}