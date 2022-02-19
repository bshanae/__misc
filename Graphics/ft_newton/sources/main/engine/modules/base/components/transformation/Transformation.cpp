#include "Transformation.h"

#include "engine/core/scene/object/Object.h"
#include "engine/tools/external/yamlCpp/YamlCpp.h"
#include "engine/tools/mathematics/Mathematics.h"

using namespace engine::base;


#pragma mark serialization

void Transformation::deserialize(Transformation &instance, const YAML::Node &node)
{
	instance.moveTo(node["position"].as<vec3>(vec3(0)));
	instance.rotateBy(radians(node["orientation"].as<vec3>(vec3(0))));
	instance.setScale(node["scale"].as<vec3>(vec3(1)));
}


#pragma mark construction/destruction

Transformation::Transformation(Object &object) : Component(object), _parent(nullptr)
{
	_position = vec3();
	_orientation = quat(1.0f, 0.f, 0.f, 0.f);
	_scale = vec3(1);
}

Transformation::Transformation(Object &object, const vec3 &translation, const vec3 &orientation, const vec3 &scale) : Transformation(object)
{
	moveTo(translation);
	rotateBy(orientation);
	setScale(scale);
}


#pragma mark local properties

const engine::vec3 &Transformation::getScale() const
{
	return _scale;
}

void Transformation::setScale(float value)
{
	setScale(vec3(value));
}

void Transformation::setScale(const vec3 &value)
{
	_scale = value;
	recalculate();
}

const engine::quat &Transformation::getLocalOrientation() const
{
	return _orientation;
}

const engine::vec3 &Transformation::getLocalPosition() const
{
	return _position;
}

const engine::mat4 &Transformation::getScaleMatrix() const
{
	return _scaleMatrix;
}

const engine::mat4 &Transformation::getTranslationMatrix() const
{
	return _translationMatrix;
}

const engine::mat4 &Transformation::getRotationMatrix() const
{
	return _rotationMatrix;
}

const engine::mat4 &Transformation::getLocalModelMatrix() const
{
	return _modelMatrix;
}


#pragma mark global properties

engine::vec3 Transformation::getGlobalPosition() const
{
	return transformPoint(_position, getParentHeritageMatrix());
}

engine::mat4 Transformation::getGlobalModelMatrix() const
{
	return  getParentHeritageMatrix() * _modelMatrix;
}


#pragma mark hieararchy

Transformation *Transformation::getParent() const
{
	return _parent;
}

engine::mat4 Transformation::getOwnHeritageMatrix() const
{
	if (_parent == nullptr)
		return _heritageMatrix;

	return _parent->getOwnHeritageMatrix() * _heritageMatrix;
}

engine::mat4 Transformation::getParentHeritageMatrix() const
{
	if (_parent == nullptr)
		return mat4(1);

	return _parent->getOwnHeritageMatrix();
}


#pragma mark control

void Transformation::moveBy(const vec3 &offset)
{
	if (approximatelyZero(offset))
		return;

	_position += offset;
	recalculate();
}

void Transformation::moveTo(const vec3 &newPosition)
{
	if (approximately(newPosition, _position))
		return;

	_position = newPosition;
	recalculate();
}

void Transformation::setOrientation(const quat &value)
{
	_orientation = value;
	recalculate();
}

void Transformation::rotateBy(const quat &rotation)
{
	_orientation = rotation * _orientation;
	recalculate();
}

void Transformation::rotateBy(const vec3 &eulerAngles)
{
	if (approximatelyZero(eulerAngles))
			return;

	_orientation = quat(eulerAngles) * _orientation;
	recalculate();
}

void Transformation::rotateAround(const vec3 &axis, float angle)
{
	if (approximatelyZero(angle))
		return;

	_orientation = angleAxis(angle, axis) * _orientation;
	recalculate();
}


#pragma mark lifecycle

void Transformation::prepareInternally()
{
	if (getObject().getParent() != nullptr)
		_parent = getObject().getParent()->trySelectComponent<Transformation>();

	recalculate();
}


#pragma mark internal computations

void Transformation::recalculate()
{
	_scaleMatrix = scale(_scale);
	_rotationMatrix = mat4_cast(_orientation);
	_translationMatrix = translate(_position);

	const auto translationRotation = _translationMatrix * _rotationMatrix;
	const auto translationRotationScale = translationRotation * _scaleMatrix;

	_heritageMatrix = translationRotation;
	_modelMatrix = translationRotationScale;

	changed.invoke();
}