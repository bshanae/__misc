#pragma once

#include <memory>
#include <list>
#include <Shader.h>

#include "Mesh.h"
#include "Assimp.h"
#include "Exception.h"
#include "Component.h"
#include "Transformable.h"
#include "Material.h"

namespace Engine
{
	class Mesh;
	class Animation;
	class Model;
}

class Engine::Model : public Component
{
public :

	~Model() override = default;

	std::shared_ptr<std::map<std::string, Engine::Vector3>> &getMapNodeScale();
	const std::vector<std::shared_ptr<Mesh>> &getMeshes() const;
	const std::shared_ptr<Animation> &getAnimation() const;

	void load(const std::string &fileName);

private :

	Assimp::Importer _importer;
	const aiScene *_aiScene;

	std::shared_ptr<std::map<std::string, Engine::Vector3>> _mapNodeScale;
	std::vector<std::shared_ptr<Mesh>> _meshes;
	std::shared_ptr<Animation> _animation;

	std::string _path;

	void loadModel();

	void processNode(aiNode *node);

	std::shared_ptr<Mesh> processMesh(aiMesh *mesh, std::string nameNode);
};