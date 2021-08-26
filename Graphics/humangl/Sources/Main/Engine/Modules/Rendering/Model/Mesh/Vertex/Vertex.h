#pragma once

#include "Vector3.h"
#include "Vector2.h"
#include "Assimp.h"

namespace Engine
{
	class Vertex;
}

class Engine::Vertex
{
public :

	Vertex(aiVector3D mVertex, aiVector3D mNormal, aiVector3D mTextureCoord, bool hasTexture);

	Vector3 position;
	Vector3 normal;
	Vector2 textureCoordinates;

	int bonesIds[4];
	float bonesWeights[4];
};