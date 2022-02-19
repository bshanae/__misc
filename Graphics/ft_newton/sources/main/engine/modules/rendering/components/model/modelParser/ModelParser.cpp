#include "ModelParser.h"

#include "engine/tools/debug/Debug.h"
#include "engine/tools/color/Color.h"
#include "engine/modules/rendering/components/model/mesh/Mesh.h"
#include "engine/modules/rendering/components/model/material/Material.h"
#include "engine/modules/rendering/components/model/mesh/vertex/Vertex.h"

using namespace engine::rendering;

ModelParser::ModelParser(const string &modelName, unsigned numberOfInstances) : _numberOfInstances(numberOfInstances)
{
	_modelPath = "Resources/Models/" + modelName;
}

engine::shared_ptr<engine::vector<Mesh>> ModelParser::parse()
{
	auto importer = Assimp::Importer();
	const auto *scene = importer.ReadFile(_modelPath, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (scene == nullptr or scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE or scene->mRootNode == nullptr)
	{
		Debug::logError("Model", string("Assimp error : ") + importer.GetErrorString());
		return {};
	}

	auto meshes = make_shared<vector<Mesh>>();
	processNode(*meshes, scene->mRootNode, scene);

	return meshes;
}

void ModelParser::processNode(vector<Mesh> &meshes, aiNode *node, const aiScene *scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		auto vertices = move(extractMeshVertices(*scene->mMeshes[node->mMeshes[i]]));
		auto indices = move(extractMeshIndices(*scene->mMeshes[node->mMeshes[i]]));
		auto material = make_shared<Material>(Color(0.8, 0.8, 0.8));

		meshes.emplace_back(move(vertices), move(indices), _numberOfInstances, material);
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++)
		processNode(meshes, node->mChildren[i], scene);
}

engine::vector<Vertex> ModelParser::extractMeshVertices(const aiMesh &source)
{
	auto vertices = vector<Vertex>();

	for (auto i = 0; i < source.mNumVertices; i++)
	{
		auto vertex = Vertex{ .position = to_glm(source.mVertices[i]) };

		if (source.mNormals != nullptr)
			vertex.normal = to_glm(source.mNormals[i]);

		vertices.push_back(vertex);
	}

	return vertices;
}

engine::vector<unsigned> ModelParser::extractMeshIndices(const aiMesh &source)
{
	auto indices = vector<unsigned>();

	for (unsigned int i = 0; i < source.mNumFaces; i++)
	{
		aiFace face = source.mFaces[i];

		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	return indices;
}
