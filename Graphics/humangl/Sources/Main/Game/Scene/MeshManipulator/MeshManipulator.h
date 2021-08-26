#pragma once

#include "Exception.h"
#include "Component.h"

namespace Game
{
	class MeshSelector;
	class MeshManipulator;
}

class Game::MeshManipulator : public Engine::Component
{
public :

	MeshManipulator();
	~MeshManipulator() override = default;

	void setScalingSpeed(float scalingSpeed);

protected :

	void prepared() override;
	void updated() override;

private :

	std::shared_ptr<MeshSelector> _meshSelector;
	float _scalingSpeed;
};