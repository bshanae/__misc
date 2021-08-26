#pragma once

#include <vector>
#include <map>
#include <optional>

#include "Transformable.h"
#include "OpenGLIncludes.h"

#include "Bone.h"
#include "BoneInfo.h"
#include "Mesh.h"
#include "AssimpNodeInfo.h"

namespace Engine
{
	class Animation;
}

class Engine::Animation final
{
public :

	static constexpr auto NumberOfBones = 200;

	Animation() = default;
	Animation(const aiScene *aiScene);

	~Animation() = default;

	float getTicksPerSecond();
	float getDuration();
	const AssimpNodeInfo &getRootNode();
	const std::map<std::string, BoneInfo> &getMapBonesInfo();

	Bone *findBone(const std::string &name);

	void processBoneWeight(const std::shared_ptr<Mesh> &mesh, aiMesh *aiMesh, const aiScene *aiScene);

private :

	void readMissingBones(const aiAnimation* animation);
	AssimpNodeInfo readHierarchyData(const aiNode *src);

	void setBoneData(Vertex &vertex, int boneId, float boneWeight);

	float _duration;
	int _ticksPerSecond;

	std::vector<Bone> _bones;
	AssimpNodeInfo _rootNode;

	std::map<std::string, BoneInfo> _mapBonesInfo;
	int _boneCounter = 0;
};