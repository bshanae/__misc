#pragma once

#include <vector>
#include <optional>
#include <list>
#include <map>

#include "Shader.h"
#include "Vertex.h"
#include "Texture.h"

#include "Object.h"
#include "OpenGLIncludes.h"
#include "Exception.h"
#include "Transformable.h"

namespace Engine
{
	class Material;
	class Mesh;
}

class Engine::Mesh final : public Transformable
{
public :

	Mesh();
	~Mesh() override;

	std::vector<Vertex> &getVertices();

	const std::vector<uint> &getIndices() const;

	const std::vector<Texture> &getTextures() const;

	std::shared_ptr<Material> getBaseMaterial() const;
	void setBaseMaterial(const std::shared_ptr<Material> &material);

	std::shared_ptr<Material> getOverrideMaterial() const;
	void setOverrideMaterial(const std::shared_ptr<Material> &material);

	std::shared_ptr<Material> getActualMaterial() const;

	void use(bool state);

	void setDirectory(std::string path);

	void setNodeName(const std::string &nameNode);
	const std::string &getNodeName();

	void processVertices(aiMesh *aiMesh);
	void processIndices(aiMesh *aiMesh);

	void processTextures(aiMesh *aiMesh, const aiScene *scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mMaterial, aiTextureType type, std::string typeName);

	void pushVertex(const Vertex &vertex);
	void pushIndex(GLuint index);

	void pack();

private :

	std::string _nodeName;

	std::vector<Vertex> _vertices;
	std::vector<uint> _indices;

	std::vector<Texture> _textures;
	std::vector<Texture> _loadedTextures;
	std::string _directory;

	GLuint _vao;
	GLuint _ebo;
	GLuint _vbo;

	std::shared_ptr<Material> _baseMaterial;
	std::shared_ptr<Material> _overrideMaterial;
};
