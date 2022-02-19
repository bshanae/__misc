#include "Mesh.h"

#include "engine/tools/debug/Debug.h"
#include "engine/tools/external/OpenGL.h"
#include "engine/modules/rendering/components/model/mesh/vertex/Vertex.h"

using namespace engine::rendering;

Mesh::Mesh(vector<Vertex> &&vertices, vector<unsigned> &&indices, unsigned numberOfInstances, const shared_ptr<Material> &baseMaterial) :
	_maxNumberOfInstances(numberOfInstances),
	_indices(move(indices)),
	_vertices(move(vertices)),
	_vertexArray(0),
	_elementBuffer(0),
	_vertexBuffer(0),
	_transformationBuffer(0),
	_baseMaterial(baseMaterial)
{
	buildVertexArray();
	bindVertexArray(true);

	buildVertexBuffer();
	buildTransformationBuffer();

	buildElementBuffer();

	bindVertexArray(false);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertexArray);

	glDeleteBuffers(1, &_elementBuffer);
	glDeleteBuffers(1, &_vertexBuffer);
	glDeleteBuffers(1, &_transformationBuffer);
}

void Mesh::updateTransformations(const vector<mat4> &transformations) const
{
	auto numberOfInstances = transformations.size();
	if (numberOfInstances > _maxNumberOfInstances)
	{
		Debug::logError("Mesh", "Current number of instances exceeded expected number of instances.");
		numberOfInstances = _maxNumberOfInstances;
	}

	glBindBuffer(GL_ARRAY_BUFFER, _transformationBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, numberOfInstances * sizeof(mat4), transformations.data());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::buildVertexArray()
{
	glGenVertexArrays(1, &_vertexArray);
}

void Mesh::buildVertexBuffer()
{
	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), _vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::buildTransformationBuffer()
{
	glGenBuffers(1, &_transformationBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _transformationBuffer);

	glBufferData(GL_ARRAY_BUFFER, _maxNumberOfInstances * sizeof(glm::mat4), nullptr, GL_STREAM_DRAW);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(vec4), (void*)0);

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(vec4), (void*)(1 * sizeof(vec4)));

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(vec4), (void*)(2 * sizeof(vec4)));

	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(vec4), (void*)(3 * sizeof(vec4)));

	glVertexAttribDivisor(2, 1);
	glVertexAttribDivisor(3, 1);
	glVertexAttribDivisor(4, 1);
	glVertexAttribDivisor(5, 1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::buildElementBuffer()
{
	glGenBuffers(1, &_elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBuffer);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);
}

void Mesh::bindVertexArray(bool state) const
{
	glBindVertexArray(state ? _vertexArray : 0);
}