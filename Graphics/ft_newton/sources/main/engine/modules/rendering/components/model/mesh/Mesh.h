#pragma once

#include "engine/tools/Tools.h"
#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/std/pointers.h"

class engine::rendering::Mesh final
{
public :

	Mesh(vector<Vertex> &&vertices, vector<unsigned> &&indices, unsigned numberOfInstances, const shared_ptr<Material> &baseMaterial);
	~Mesh();

	inline const vector<Vertex> &getVertices() const
	{
		return _vertices;
	}

	inline const vector<unsigned> &getIndices() const
	{
		return _indices;
	}

	inline shared_ptr<Material> getBaseMaterial() const
	{
		return _baseMaterial;
	}

	inline shared_ptr<Material> getOverrideMaterial() const
	{
		return _overrideMaterial;
	}

	inline void setOverrideMaterial(const shared_ptr<Material> &material)
	{
		_overrideMaterial = material;
	}

	inline shared_ptr<Material> getActualMaterial() const
	{
		return _overrideMaterial != nullptr ? _overrideMaterial : _baseMaterial;
	}

	inline void bind(bool state) const
	{
		bindVertexArray(state);
	}

	void updateTransformations(const vector<mat4> &transformations) const;

private :

	const unsigned _maxNumberOfInstances;

	vector<Vertex> _vertices;
	vector<unsigned> _indices;

	unsigned _vertexArray;
	unsigned _elementBuffer;
	unsigned _vertexBuffer;
	unsigned _transformationBuffer;

	shared_ptr<Material> _baseMaterial;
	shared_ptr<Material> _overrideMaterial;

	void buildVertexArray();
	void buildVertexBuffer();
	void buildTransformationBuffer();
	void buildElementBuffer();

	void bindVertexArray(bool state) const;
};
