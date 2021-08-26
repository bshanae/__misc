#include "MeshSelector.h"

#include "Scene.h"
#include "Input.h"
#include "Model.h"
#include "Mesh.h"
#include "Material.h"

using namespace Game;

std::list<std::shared_ptr<Engine::Mesh>> MeshSelector::getSelectedMeshes() const
{
	return _selectedMeshes;
}

void MeshSelector::prepared()
{
	_model = getObject()->findMandatoryComponent<Engine::Model>();

	_mapNodeScale = _model->getMapNodeScale();
	_iterator = _mapNodeScale->cbegin();

	_selectionMaterial = std::make_shared<Engine::Material>();
	_selectionMaterial->setColor(Engine::Color(1, 1, 1));
}

void MeshSelector::updated()
{
	_isSelectionEnabled = Engine::Input::getInstance()->isHeld(Engine::Input::Command);

	if (Engine::Input::getInstance()->isPressed(Engine::Input::Left))
		decrementSelectedNode();
	else if (Engine::Input::getInstance()->isPressed(Engine::Input::Right))
		incrementSelectedNode();

	if (!_selectedMeshes.empty())
	{
		for (auto selectedMesh : _selectedMeshes)
			selectedMesh->setOverrideMaterial(nullptr);
	}

	updateSelectedMesh();

	if (!_selectedMeshes.empty())
	{
		for (auto selectedMesh : _selectedMeshes)
		{
			if (selectedMesh->getNodeName() == _iterator->first)
				selectedMesh->setOverrideMaterial(_selectionMaterial);
		}
	}
}

void MeshSelector::updateMapNodeScale(float valueScale)
{
	(*_mapNodeScale)[_iterator->first] = _iterator->second * valueScale;
}

void MeshSelector::incrementSelectedNode()
{
	_iterator++;

	if (_iterator == _mapNodeScale->end())
		_iterator = _mapNodeScale->cbegin();
}

void MeshSelector::decrementSelectedNode()
{
	if (_iterator == _mapNodeScale->begin())
		_iterator = --_mapNodeScale->cend();
	else
		_iterator--;
}

void MeshSelector::updateSelectedMesh()
{
	if (not _isSelectionEnabled)
	{
		_selectedMeshes.clear();
	}
	else
	{
		for (auto mesh : _model->getMeshes())
		{
			if (mesh->getNodeName() == _iterator->first)
				_selectedMeshes.push_back(mesh);
		}
	}
}