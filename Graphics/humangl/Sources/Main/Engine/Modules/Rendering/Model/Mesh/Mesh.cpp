#include "Mesh.h"

using namespace Engine;

Mesh::Mesh() : _vao(0), _ebo(0)
{
	glGenVertexArrays(1, &_vao);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_ebo);
	glDeleteBuffers(1, &_vbo);
}

std::vector<Vertex> &Mesh::getVertices()
{
	return _vertices;
}

const std::vector<uint> &Mesh::getIndices() const
{
	return _indices;
}

const std::vector<Texture> &Mesh::getTextures() const
{
	return _textures;
}

std::shared_ptr<Material> Mesh::getBaseMaterial() const
{
	return _baseMaterial;
}

void Mesh::setBaseMaterial(const std::shared_ptr<Material> &material)
{
	if (_baseMaterial != nullptr)
		throw Exception("Base material is already set");

	_baseMaterial = material;
}

std::shared_ptr<Material> Mesh::getOverrideMaterial() const
{
	return _overrideMaterial;
}

void Mesh::setOverrideMaterial(const std::shared_ptr<Material> &material)
{
	_overrideMaterial = material;
}

std::shared_ptr<Material> Mesh::getActualMaterial() const
{
	if (_overrideMaterial != nullptr)
		return _overrideMaterial;

	if (_baseMaterial == nullptr)
		throw Exception("Base material is not set");

	return _baseMaterial;
}

void Mesh::use(bool state)
{
	glBindVertexArray(state ? _vao : 0);
}

void Mesh::setDirectory(std::string path)
{
	_directory = path.substr(0, path.find_last_of('/'));
}

void Mesh::setNodeName(const std::string &nodeName)
{
	_nodeName = nodeName;
}

const std::string &Mesh::getNodeName()
{
	return _nodeName;
}

void Mesh::processVertices(aiMesh *aiMesh)
{
	const auto isTexturePresent = aiMesh->mTextureCoords[0] != nullptr;

	for (auto i = 0; i < aiMesh->mNumVertices; i++)
		pushVertex({aiMesh->mVertices[i], aiMesh->mNormals[i], aiMesh->mTextureCoords[0][i], isTexturePresent});
}

void Mesh::processIndices(aiMesh *aiMesh)
{
	for (unsigned int i = 0; i < aiMesh->mNumFaces; i++)
	{
		aiFace face = aiMesh->mFaces[i];

		for (unsigned int j = 0; j < face.mNumIndices; j++)
		{
			pushIndex(face.mIndices[j]);
		}
	}
}

void Mesh::processTextures(aiMesh *aiMesh, const aiScene *scene)
{
	std::vector<Texture> textures;

	if (aiMesh->mMaterialIndex >= 0)
	{
		aiMaterial *material = scene->mMaterials[aiMesh->mMaterialIndex];

		std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

		std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

		std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

		std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
		textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
	}
}

std::vector<Texture> Mesh::loadMaterialTextures(aiMaterial *mMaterial, aiTextureType type, std::string typeName)
{
	std::vector<Texture> textures;

	for(unsigned int i = 0; i < mMaterial->GetTextureCount(type); i++)
	{
		aiString str;
		bool skip = false;

		mMaterial->GetTexture(type, i, &str);

		for (unsigned int j = 0; j < _loadedTextures.size(); j++)
		{
			if (std::strcmp(_loadedTextures[j]._path.C_Str(), str.C_Str()) == 0)
			{
				textures.push_back(_loadedTextures[j]);
				skip = true;
				break;
			}
		}

		if (!skip)
		{
			Texture texture;

			texture._glObject = Texture::textureFromFile(str.C_Str(), _directory);
			texture._type = typeName;
			texture._path = str;

			textures.push_back(texture);
			_loadedTextures.push_back(texture);
		}
	}
	return textures;
}

void Mesh::pushIndex(GLuint index)
{
	_indices.push_back(index);
}

void Mesh::pushVertex(const Vertex &vertex)
{
	_vertices.push_back(vertex);
}

void Mesh::pack()
{
	use(true);

	GLuint VBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoordinates));

	glEnableVertexAttribArray(3);
	glVertexAttribIPointer(3, 4, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, bonesIds));

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, bonesWeights));

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &_ebo);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), &_indices[0], GL_STATIC_DRAW);

	use(false);

	if (_baseMaterial == nullptr)
		throw Exception("Base material should be set before packing model");
}