#include "Box.h"

#include "engine/tools/debug/Debug.h"
#include "engine/tools/mathematics/Mathematics.h"
#include "engine/modules/physics/algorithm/primitives/interval/Interval.h"

using namespace engine::physics;

Box::Box()
{
	_position = vec3();
	_size = vec3();
	_rotationMatrix = mat4(1);
	_translationMatrix = mat4(1);
	_isMetaDirty = true;
}

const engine::mat4 &Box::getModelMatrix() const
{
	return _modelMatrix;
}

const engine::mat4 &Box::getInverseModelMatrix() const
{
	return _inverseModelMatrix;
}

Interval Box::getInterval(const vec3 &axis) const
{
	auto interval = Interval(dot(axis, _vertices[0]));

	for (const auto &vertex : _vertices)
	{
		const auto projection = dot(axis, vertex);
		interval.min = min(interval.min, projection);
		interval.max = max(interval.max, projection);
	}

	return interval;
}

bool Box::isInside(const vec3 &point) const
{
	const auto pointInLCS = point - _position;

	for (auto i = 0; i < 3; i++)
	{
		const auto projection = dot(pointInLCS, _axes[i]);

		if (projection > _size[i] / 2)
			return false;
		if (projection < -_size[i] / 2)
			return false;
	}

	return true;
}

engine::vec3 Box::getClosestPoint(const vec3 &point) const
{
	auto result = _position;
	const auto direction = point - _position;

	for (int i = 0; i < 3; i++)
	{
		const auto &axis = _axes[i];
		const auto sizeComponent = _size[i];

		auto distance = dot(direction, axis);
		distance = clamp(distance, -sizeComponent / 2, sizeComponent / 2);

		result += axis * distance;
	}

	return result;
}

void Box::updateMeta()
{
	if constexpr (constants::debug)
		Debug::assume(_isMetaDirty, "Should not recalculate additional data at this point");

	computeHalfSize();
	computeAxes();
	computeVertices();
	computeEdges();
	computePlanes();

	_isMetaDirty = false;
}

void Box::computeHalfSize()
{
	_halfSize = _size / 2.f;
}

void Box::computeAxes()
{
	const auto rotationMatrix = _parentMatrix * _rotationMatrix;
	_axes = { rotationMatrix[0], rotationMatrix[1], rotationMatrix[2] };
}

void Box::computeVertices()
{
	const auto transformationMatrix = scale(_parentMatrix * _translationMatrix * _rotationMatrix, _size);

	/*
	 * back:
	 *   1 - 2
	 *   |   |
	 *   0 - 3
	 *
	 * front:
	 *   5 - 6
	 *   |   |
	 *   4 - 7
	 */

	_vertices =
	{
		transformPoint(vec3(-0.5, -0.5, -0.5), transformationMatrix),
		transformPoint(vec3(-0.5, +0.5, -0.5), transformationMatrix),
		transformPoint(vec3(+0.5, +0.5, -0.5), transformationMatrix),
		transformPoint(vec3(+0.5, -0.5, -0.5), transformationMatrix),
		transformPoint(vec3(-0.5, -0.5, +0.5), transformationMatrix),
		transformPoint(vec3(-0.5, +0.5, +0.5), transformationMatrix),
		transformPoint(vec3(+0.5, +0.5, +0.5), transformationMatrix),
		transformPoint(vec3(+0.5, -0.5, +0.5), transformationMatrix)
	};
}

void Box::computeEdges()
{
	_edges =
	{
		// front face
		Line(_vertices[0], _vertices[1]),
		Line(_vertices[1], _vertices[2]),
		Line(_vertices[2], _vertices[3]),
		Line(_vertices[3], _vertices[0]),

		// back face
		Line(_vertices[4], _vertices[5]),
		Line(_vertices[5], _vertices[6]),
		Line(_vertices[6], _vertices[7]),
		Line(_vertices[7], _vertices[4]),

		// edges between front and back faces
		Line(_vertices[0], _vertices[4]),
		Line(_vertices[1], _vertices[5]),
		Line(_vertices[2], _vertices[6]),
		Line(_vertices[3], _vertices[7])
	};
}

void Box::computePlanes()
{
	_planes =
	{
		Plane(_axes[0], dot(_axes[0], (_position + _axes[0] * _size.x / 2.f))),
		Plane(_axes[0] * -1.0f, -dot(_axes[0], (_position - _axes[0] * _size.x / 2.f))),
		Plane(_axes[1], dot(_axes[1], (_position + _axes[1] * _size.y / 2.f))),
		Plane(_axes[1] * -1.0f, -dot(_axes[1], (_position - _axes[1] * _size.y / 2.f))),
		Plane(_axes[2], dot(_axes[2], (_position + _axes[2] * _size.z / 2.f))),
		Plane(_axes[2] * -1.0f, -dot(_axes[2], (_position - _axes[2] * _size.z / 2.f)))
	};
}

void Box::validateMeta() const
{
	if constexpr (constants::debug)
		Debug::assume(!_isMetaDirty, "[Box] Meta is invalid");
}