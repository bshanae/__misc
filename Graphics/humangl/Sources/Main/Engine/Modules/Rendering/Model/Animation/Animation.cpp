#include "Animation.h"

#include "Converter.h"

using namespace Engine;

Animation::Animation(const aiScene *aiScene)
{
	assert(aiScene && aiScene->mRootNode);

	auto animation = aiScene->mAnimations[0];

	_duration = animation->mDuration;
	_ticksPerSecond = animation->mTicksPerSecond;

	_rootNode = readHierarchyData(aiScene->mRootNode);
}

Bone *Animation::findBone(const std::string& name)
{
	const auto iterator = std::find_if(
		_bones.begin(),
		_bones.end(),
		[&](const Bone &Bone) { return Bone.getBoneName() == name; });

	if (iterator == _bones.end())
		return nullptr;
	else
		return &*iterator;
}

float Animation::getTicksPerSecond()
{
	return _ticksPerSecond;
}

float Animation::getDuration()
{
	return _duration;
}

const AssimpNodeInfo& Animation::getRootNode()
{
	return _rootNode;
}

const std::map<std::string,BoneInfo>& Animation::getMapBonesInfo()
{
	return _mapBonesInfo;
}

void Animation::processBoneWeight(const std::shared_ptr<Mesh> &mesh, aiMesh* aiMesh, const aiScene* aiScene)
{
	for (int boneIndex = 0; boneIndex < aiMesh->mNumBones; ++boneIndex)
	{
		const auto boneName = aiMesh->mBones[boneIndex]->mName.C_Str();
		auto boneId = -1;

		if (_mapBonesInfo.find(boneName) == _mapBonesInfo.end())
		{
			auto newBoneMatrix = BoneInfo{
				_boneCounter,
				Converter::convert(aiMesh->mBones[boneIndex]->mOffsetMatrix)};

			_mapBonesInfo[boneName] = newBoneMatrix;
			boneId = _boneCounter++;
		}
		else
		{
			boneId = _mapBonesInfo[boneName].id;
		}

		assert(boneId != -1);

		const auto weights = aiMesh->mBones[boneIndex]->mWeights;
		const auto numberOfWeights = aiMesh->mBones[boneIndex]->mNumWeights;

		for (int weightIndex = 0; weightIndex < numberOfWeights; ++weightIndex)
		{
			const auto vertexId = weights[weightIndex].mVertexId;
			const auto boneWeight = weights[weightIndex].mWeight;

			assert(vertexId <= mesh->getVertices().size());

			setBoneData(mesh->getVertices()[vertexId], boneId, boneWeight);
		}
	}

	readMissingBones(aiScene->mAnimations[0]);
}

void Animation::setBoneData(Vertex &vertex, int boneId, float boneWeight)
{
	for (int i = 0; i < 4; ++i)
	{
		if (vertex.bonesIds[i] < 0)
		{
			vertex.bonesWeights[i] = boneWeight;
			vertex.bonesIds[i] = boneId;
			break;
		}
	}
}

void Animation::readMissingBones(const aiAnimation *aiAnimation)
{
	const auto size = aiAnimation->mNumChannels;

	for (int i = 0; i < size; i++)
	{
		const auto channel = aiAnimation->mChannels[i];
		const auto boneName = channel->mNodeName.data;

		if (_mapBonesInfo.find(boneName) == _mapBonesInfo.end())
		{
			_mapBonesInfo[boneName].id = _boneCounter;
			_boneCounter++;
		}

		_bones.push_back(Bone(channel->mNodeName.data, channel));
	}
}

AssimpNodeInfo Animation::readHierarchyData(const aiNode* aiNode)
{
	assert(aiNode);

	AssimpNodeInfo nodeInfo;

	nodeInfo.name = aiNode->mName.data;
	nodeInfo.transformation = Converter::convert(aiNode->mTransformation);

	for (int i = 0; i < aiNode->mNumChildren; i++)
		nodeInfo.children.push_back(readHierarchyData(aiNode->mChildren[i]));

	return nodeInfo;
}