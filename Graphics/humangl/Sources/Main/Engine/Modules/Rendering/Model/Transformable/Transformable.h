#pragma once

#include <list>

#include "Matrix4x4.h"

namespace Engine
{
	class Transformable;
}

class Engine::Transformable : public std::enable_shared_from_this<Engine::Transformable>
{
public :

	Transformable();
	virtual ~Transformable() = default;

	Vector3 getScale() const;
	void setScale(const Vector3 &value);

	Vector3 getTranslation() const;
	void setTranslation(const Vector3 &value);

	Vector3 getRotation() const;
	void setRotation(const Vector3 &value);

	Matrix4x4 getTransformation() const;

	std::shared_ptr<Transformable> getParent() const;
	const std::list<std::shared_ptr<Transformable>> &getChildren() const;

	void linkChild(const std::shared_ptr<Transformable> &child);

protected :

	Vector3 _scale;
	Vector3 _translation;
	Vector3 _rotation;

private :

	std::shared_ptr<Transformable> _parent;
	std::list<std::shared_ptr<Transformable>> _children;

	Matrix4x4 makeRtsMatrix() const;
};