#include "Transformable.h"

using namespace Engine;

Transformable::Transformable() : _scale(1)
{}

Vector3 Transformable::getScale() const
{
	return _scale;
}

void Transformable::setScale(const Vector3 &value)
{
	_scale = value;
}

Vector3 Transformable::getTranslation() const
{
	return _translation;
}

void Transformable::setTranslation(const Vector3 &value)
{
	_translation = value;
}

Vector3 Transformable::getRotation() const
{
	return _rotation;
}

void Transformable::setRotation(const Vector3 &value)
{
	_rotation = value;
}

Matrix4x4 Transformable::getTransformation() const
{
	if (_parent != nullptr)
		return _parent->getTransformation() * makeRtsMatrix();
	else
		return makeRtsMatrix();
}

std::shared_ptr<Transformable> Transformable::getParent() const
{
	return _parent;
}

const std::list<std::shared_ptr<Transformable>> &Transformable::getChildren() const
{
	return _children;
}

void Transformable::linkChild(const std::shared_ptr<Transformable> &child)
{
	_children.push_back(child);
	child->_parent = shared_from_this();
}

Matrix4x4 Transformable::makeRtsMatrix() const
{
	return
		Matrix4x4::makeTranslation(_translation) *
		Matrix4x4::makeRotation(_rotation) *
		Matrix4x4::makeScale(_scale);
}