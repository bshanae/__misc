#pragma once

#include "Matrix4x4.h"
#include "Component.h"

namespace Engine
{
	class DefaultCamera;
}

class Engine::DefaultCamera : public Engine::Component
{
public :

	DefaultCamera();
	~DefaultCamera() override = default;

	void setMovementSpeed(float movementSpeed);
	void setRotationSpeed(float rotationSpeed);
	void setFov(float fov);
	void setNearPlane(float nearPlane);
	void setFarPlane(float farPlane);

	Vector3 getPosition() const;
	void setPosition(const Vector3 &position);

	void setYaw(float yaw);
	void setPitch(float pitch);

	Vector3 getDirection() const;

	Matrix4x4 getProjection() const;
	Matrix4x4 getView() const;

	void reload();

protected :

	void updated() override;

private :

	static constexpr float epsilon = 0.0001f;

	float _windowAspect;

	float _movementSpeed;
	float _rotationSpeed;
	float _fov;
	float _nearPlane;
	float _farPlane;

	Vector3 _position;
	float _yaw;
	float _pitch;

	Vector3 _front;
	Vector3 _up;
	Vector3 _right;
	Matrix4x4 _projection;
	Matrix4x4 _view;

	bool _positionOrRotationChanged;

	void getWindowAspect();

	void setDefaultValues();

	void processRotationInput();
	void processMovementInput();

	void reloadVectors();
	void reloadMatrices();
};