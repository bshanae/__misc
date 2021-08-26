#include "Vertex.h"

using namespace Engine;

Vertex::Vertex(aiVector3D mVertex, aiVector3D mNormal, aiVector3D mTextureCoord, bool hasTexture)
{
		this->position.x = mVertex.x;
		this->position.y = mVertex.y;
		this->position.z = mVertex.z;

		this->normal.x = mNormal.x;
		this->normal.y = mNormal.y;
		this->normal.z = mNormal.z;

		if (hasTexture)
		{
			this->textureCoordinates.x = mTextureCoord.x;
			this->textureCoordinates.y = mTextureCoord.y;
		} else
			this->textureCoordinates = {0.f, 0.f};

		for (int i = 0; i < 4; i++)
		{
			bonesIds[i] = -1;
			bonesWeights[i] = 0.0f;
		}
}