#pragma once

#include "engine/modules/rendering/Rendering.h"

#include "engine/tools/external/std/string.h"
#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/std/pointers.h"
#include "engine/tools/external/Assimp.h"

class engine::rendering::ModelParser final
{
public :

	ModelParser(const string &modelName, unsigned numberOfInstances);
	~ModelParser() = default;

	shared_ptr<vector<Mesh>> parse();

private :

	string _modelPath;
	unsigned _numberOfInstances;

	void processNode(vector<Mesh> &meshes, aiNode *node, const aiScene *scene);

	vector<Vertex> extractMeshVertices(const aiMesh &source);
	vector<unsigned> extractMeshIndices(const aiMesh &source);
};
