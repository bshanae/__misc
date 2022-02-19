#include "Camera.h"

#include "engine/modules/base/components/transformation/Transformation.h"

using namespace engine::rendering;

Camera::Camera(Object &object) : Component(object), _transformationFinder(*this)
{}

engine::vec3 Camera::getPosition() const
{
	return _transformationFinder().getLocalPosition();
}

engine::quat Camera::getOrientation() const
{
	return _transformationFinder().getLocalOrientation();
}

engine::vec3 Camera::getFront() const
{
	return conjugate(_transformationFinder().getLocalOrientation()) * glm::vec3(0.0f, 0.0f, -1.0f);
}

engine::vec3 Camera::getUp() const
{
	return conjugate(_transformationFinder().getLocalOrientation()) * glm::vec3(0.0f, 1.0f, 0.0f);
}

engine::vec3 Camera::getRight() const
{
	return conjugate(_transformationFinder().getLocalOrientation()) * glm::vec3(1.0f, 0.0f, 0.0f);
}

void Camera::initializeInternally()
{
	if (_transformationFinder().getParent() != nullptr)
		Debug::logWarning("Camera", "A camera shouldn't have a parent. The parent transformation will be ignored.");
}