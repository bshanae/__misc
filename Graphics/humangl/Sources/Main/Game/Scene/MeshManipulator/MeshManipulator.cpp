#include "MeshManipulator.h"

#include "Configuration.h"
#include "Input.h"
#include "Scene.h"
#include "MeshSelector.h"

using namespace Game;

MeshManipulator::MeshManipulator()
{
	_scalingSpeed = 0.f;
}

void MeshManipulator::setScalingSpeed(float scalingSpeed)
{
	_scalingSpeed = scalingSpeed;
}

void MeshManipulator::prepared()
{
	_meshSelector = getObject()->findMandatoryComponent<MeshSelector>();
}

void MeshManipulator::updated()
{
	const auto selectedMeshes = _meshSelector->getSelectedMeshes();
	if (selectedMeshes.empty())
		return;

	float scaleDelta = 1.f;

	if (Engine::Input::getInstance()->isPressedOrHeld(Engine::Input::Minus))
		scaleDelta -= _scalingSpeed;
	if (Engine::Input::getInstance()->isPressedOrHeld(Engine::Input::Plus))
		scaleDelta += _scalingSpeed;

	_meshSelector->updateMapNodeScale(scaleDelta);
}