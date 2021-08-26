#pragma once

#include "Assimp.h"
#include "Transformable.h"

namespace Engine
{
	class Texture;
}

class Engine::Texture : public Transformable
{
public :

	static unsigned int textureFromFile(const char *path, const std::string &directory);

	// TODO Getters and setters
	unsigned int _glObject;
	std::string _type;

	// TODO Remove
	aiString _path;
};