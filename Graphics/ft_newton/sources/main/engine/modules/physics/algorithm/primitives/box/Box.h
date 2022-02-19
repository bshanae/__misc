#pragma once

#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/std/array.h"
#include "engine/tools/external/std/mathematics.h"
#include "engine/modules/physics/algorithm/primitives/line/Line.h"
#include "engine/modules/physics/algorithm/primitives/plane/Plane.h"

class engine::physics::Box final
{
public :

	Box();

	inline const vec3 &getPosition() const
	{
		return _position;
	}

	inline void setPosition(const vec3 &value)
	{
		_position = value;
		_isMetaDirty = false;
	}

	inline const vec3 &getSize() const
	{
		return _size;
	}

	inline void setSize(const vec3 &value)
	{
		_size = value;
		_isMetaDirty = true;
	}

	inline void setParentMatrix(const mat4 &value)
	{
		_parentMatrix = value;
		_isMetaDirty = true;
	}

	inline void setModelMatrix(const mat4 &value)
	{
		_modelMatrix = value;
	}

	inline void setInverseModelMatrix(const mat4 &value)
	{
		_inverseModelMatrix = value;
	}

	inline void setTranslationMatrix(const mat4 &value)
	{
		_translationMatrix = value;
		_isMetaDirty = true;
	}

	inline void setRotationMatrix(const mat4 &value)
	{
		_rotationMatrix = value;
		_isMetaDirty = true;
	}

	inline const vec3 &getHalfSize() const
	{
		validateMeta();
		return _halfSize;
	}

	inline const array<vec3, 3> &getAxes() const
	{
		validateMeta();
		return _axes;
	}

	inline const array<vec3, 8> &getVertices() const
	{
		validateMeta();
		return _vertices;
	}

	inline const array<Line, 12> &getEdges() const
	{
		validateMeta();
		return _edges;
	}

	inline const array<Plane, 6> &getPlanes() const
	{
		validateMeta();
		return _planes;
	}

	const mat4 &getModelMatrix() const;

	const mat4 &getInverseModelMatrix() const;

	Interval getInterval(const vec3 &axis) const;

	bool isInside(const vec3 &point) const;

	vec3 getClosestPoint(const vec3 &point) const;

	void updateMeta();

private :

	vec3 _position;
	vec3 _size;
	mat4 _parentMatrix;
	mat4 _modelMatrix;
	mat4 _inverseModelMatrix;
	mat4 _rotationMatrix;
	mat4 _translationMatrix;

	bool _isMetaDirty;
	vec3 _halfSize;
	array<vec3, 3> _axes;
	array<vec3, 8> _vertices;
	array<Line, 12> _edges;
	array<Plane, 6> _planes;

	void computeHalfSize();
	void computeAxes();
	void computeVertices();
	void computeEdges();
	void computePlanes();

	void validateMeta() const;
};
