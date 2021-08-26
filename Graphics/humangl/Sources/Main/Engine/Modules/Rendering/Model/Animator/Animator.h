#pragma once

#include "Component.h"
#include "Animation.h"

namespace Engine
{
	class Animator;
}

class Engine::Animator final : public Component
{
public :

	~Animator() override = default;

	const std::vector<Matrix4x4> &getFinalBoneMatrices();

	void prepared() override;
	void updated() override;

private :

	std::shared_ptr<std::map<std::string, Vector3>> _nodesScales;
	std::shared_ptr<Animation> _animation;
	std::vector<Matrix4x4> _finalBoneMatrices;

	float _animationTime;
	float _lastFrameTime;

	void updateAnimation(float deltaTime);
	void calculateBoneTransform(const AssimpNodeInfo &assimpNodeData, const Matrix4x4 &parentTransform);
};

