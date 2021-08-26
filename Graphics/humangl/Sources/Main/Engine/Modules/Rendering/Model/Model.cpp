#include "Model.h"

#include "Animation.h"

using namespace Engine;

std::shared_ptr<std::map<std::string, Engine::Vector3>> &Model::getMapNodeScale()
{
	return _mapNodeScale;
}

const std::vector<std::shared_ptr<Mesh>> &Model::getMeshes() const
{
	return _meshes;
}

const std::shared_ptr<Animation> &Model::getAnimation() const
{
	return _animation;
}

void Model::load(const std::string &fileName)
{
	_path = "Resources/Models/" + fileName;
	loadModel();
}

void Model::loadModel()
{
	_aiScene = _importer.ReadFile(_path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!_aiScene || _aiScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !_aiScene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << _importer.GetErrorString() << std::endl;
		return;
	}

	_animation = std::make_shared<Animation>(_aiScene);
	_mapNodeScale = std::make_shared<std::map<std::string, Engine::Vector3>>();

	processNode(_aiScene->mRootNode);

	for (const auto &mesh : _meshes)
		mesh->pack();
}

void Model::processNode(aiNode *node)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		auto aiMesh = _aiScene->mMeshes[node->mMeshes[i]];
		auto mesh = processMesh(aiMesh, node->mName.C_Str());

		_animation->processBoneWeight(mesh, aiMesh, _aiScene);

		(*_mapNodeScale)[node->mName.C_Str()] = Vector3(1.0f);
		_meshes.push_back(std::shared_ptr<Mesh>(mesh));
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++)
		processNode(node->mChildren[i]);
}

std::shared_ptr<Mesh> Model::processMesh(aiMesh *aiMesh, std::string nameNode)
{
	const auto mesh = std::make_shared<Mesh>();

	mesh->setDirectory(_path);
	mesh->setNodeName(nameNode);
	mesh->processVertices(aiMesh);

	mesh->processIndices(aiMesh);
	mesh->processTextures(aiMesh, _aiScene);

	auto material = std::make_shared<Material>();
	material->setColor(Color(0.8, 0.1, 0.1));

	mesh->setBaseMaterial(material);

	return mesh;
}