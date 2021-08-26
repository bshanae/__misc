#include "Animator.h"

#include "Environment.h"
#include "Model.h"

using namespace Engine;

void Animator::prepared()
{
	_animation = getObject()->findMandatoryComponent<Engine::Model>()->getAnimation();
	_nodesScales = getObject()->findMandatoryComponent<Engine::Model>()->getMapNodeScale();

	if (_animation == nullptr)
		throw Exception("[Animator] Animation is not present");

	_finalBoneMatrices.reserve(Animation::NumberOfBones);
	for (int i = 0; i < Animation::NumberOfBones; i++)
		_finalBoneMatrices.push_back(Matrix4x4::makeIdentity());
}

void Animator::updated()
{
	const auto currentTime = Environment::getTime();
	const auto deltaTime = currentTime - _lastFrameTime;

	updateAnimation(deltaTime);

	_lastFrameTime = currentTime;
}

void Animator::updateAnimation(float deltaTime)
{
	_animationTime += _animation->getTicksPerSecond() * deltaTime;
	_animationTime = fmod(_animationTime, _animation->getDuration());

	calculateBoneTransform(_animation->getRootNode(), Matrix4x4::makeIdentity());
}

void Animator::calculateBoneTransform(const AssimpNodeInfo &assimpNodeData, const Matrix4x4 &parentTransform)
{
	const auto nodeName = assimpNodeData.name;
	auto nodeTransform = assimpNodeData.transformation;

	const auto bone = _animation->findBone(nodeName);

	if (bone)
	{
		bone->update(_animationTime);
		nodeTransform = bone->getLocalTransform();
	}

	auto scale = Vector3(1.0f);

	for (auto nodeScale : *_nodesScales)
	{
		if ((nodeName.find(nodeScale.first)) != std::string::npos)
			scale = nodeScale.second;
	}

	const auto globalTransformation = parentTransform * nodeTransform * Matrix4x4().makeScale(scale);
	auto boneInfoMap = _animation->getMapBonesInfo();

	if (boneInfoMap.find(nodeName) != boneInfoMap.end())
	{
		auto index = boneInfoMap[nodeName].id;
		auto offset = boneInfoMap[nodeName].offset;

		_finalBoneMatrices[index] = globalTransformation * offset;
	}

	for (const auto &child : assimpNodeData.children)
		calculateBoneTransform(child, globalTransformation);
}

const std::vector<Matrix4x4> &Animator::getFinalBoneMatrices()
{
	return _finalBoneMatrices;
}