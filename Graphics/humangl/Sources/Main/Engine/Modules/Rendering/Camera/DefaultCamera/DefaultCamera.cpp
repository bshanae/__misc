#include "DefaultCamera.h"

#include "Configuration.h"
#include "Window.h"
#include "Input.h"
#include "MathFunctions.h"

using namespace Engine;

DefaultCamera::DefaultCamera()
{
	getWindowAspect();

	setDefaultValues();
	reload();

	_positionOrRotationChanged = false;
}

void DefaultCamera::setMovementSpeed(float movementSpeed)
{
	_movementSpeed = movementSpeed;
}

void DefaultCamera::setRotationSpeed(float rotationSpeed)
{
	_rotationSpeed = rotationSpeed;
}

void DefaultCamera::setFov(float fov)
{
	_fov = fov;
}
void DefaultCamera::setNearPlane(float nearPlane)
{
	_nearPlane = nearPlane;
}
void DefaultCamera::setFarPlane(float farPlane)
{
	_farPlane = farPlane;
}

Vector3 DefaultCamera::getPosition() const
{
	return _position;
}

void DefaultCamera::setPosition(const Vector3 &position)
{
	_position = position;
}

void DefaultCamera::setYaw(float yaw)
{
	_yaw = MathUtilities::degreesToRadians(yaw);
}

void DefaultCamera::setPitch(float pitch)
{
	_pitch = MathUtilities::degreesToRadians(pitch);
}

Vector3 DefaultCamera::getDirection() const
{
	return _front;
}

Matrix4x4 DefaultCamera::getProjection() const
{
	return _projection;
}

Matrix4x4 DefaultCamera::getView() const
{
	return _view;
}

void DefaultCamera::reload()
{
	reloadVectors();
	reloadMatrices();
}

void DefaultCamera::updated()
{
	_positionOrRotationChanged = false;

	processRotationInput();
	processMovementInput();

	if (_positionOrRotationChanged)
		reload();
}

void DefaultCamera::setDefaultValues()
{
	_position = Vector3();
	_yaw = 0;
	_pitch = 0;
	_fov = MathUtilities::degreesToRadians(45);
	_nearPlane = 0.1;
	_farPlane = 1000;
}

void DefaultCamera::getWindowAspect()
{
	const auto windowWidth = Engine::Window::getInstance()->getSize().x;
	const auto windowHeight = Engine::Window::getInstance()->getSize().y;

	_windowAspect = windowWidth / windowHeight;
}

void DefaultCamera::processRotationInput()
{
	if (not Engine::Input::getInstance()->isPressedOrHeld(Engine::Input::RightMouse))
		return;

	const auto mouseOffset = Engine::Input::getInstance()->getMouseOffset();

	const auto yawChange = mouseOffset.x * _rotationSpeed;
	const auto pitchChange = -1.f * mouseOffset.y * _rotationSpeed;

	if (std::abs(yawChange) < epsilon and std::abs(pitchChange) < epsilon)
		return;

	static constexpr float yawMin = -(float)M_PI + epsilon;
	static constexpr float yawMax = +(float)M_PI - epsilon;

	static constexpr float pitchMin = -(float)M_PI_2 + epsilon;
	static constexpr float pitchMax = +(float)M_PI_2 - epsilon;

	const auto newYaw = std::clamp(_yaw + yawChange, yawMin, yawMax);
	const auto newPitch = std::clamp(_pitch + pitchChange, pitchMin, pitchMax);

	if (newYaw == _yaw and newPitch == _pitch)
		return;

	_yaw = newYaw;
	_pitch = newPitch;

	_positionOrRotationChanged = true;
}

void DefaultCamera::processMovementInput()
{
	Vector3 movement;

	if (Engine::Input::getInstance()->isPressedOrHeld(Engine::Input::A))
		movement += _right * -1;
	else if (Engine::Input::getInstance()->isPressedOrHeld(Engine::Input::D))
		movement += _right;

	if (Engine::Input::getInstance()->isPressedOrHeld(Engine::Input::W))
		movement += _front;
	else if (Engine::Input::getInstance()->isPressedOrHeld(Engine::Input::S))
		movement += _front * -1;

	if (Engine::Input::getInstance()->isHeld(Engine::Input::Space))
		movement += Vector3(0, 1, 0);

	if (movement != Vector3())
	{
		_position += Vector3::normalize(movement) * _movementSpeed;
		_positionOrRotationChanged = true;
	}
}

void DefaultCamera::reloadVectors()
{
	static const Vector3 constUp = {0, 1, 0};

	_front.x = cos(_yaw) * cos(_pitch);
	_front.y = sin(_pitch);
	_front.z = sin(_yaw) * cos(_pitch);

	_front = Vector3::normalize(_front);
	_right = Vector3::normalize(Vector3::cross(_front, constUp));
	_up = Vector3::normalize(Vector3::cross(_right, _front));
}

void DefaultCamera::reloadMatrices()
{
	_projection = Matrix4x4::makePerspectiveProjection(
		_fov,
		_windowAspect,
		_nearPlane,
		_farPlane);

	_view = Matrix4x4::makeLookAt(_position,_position + _front, _up);
}