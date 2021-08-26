#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "DefaultCamera.h"
#include "Model.h"

namespace Game
{
	class MeshSelector;
}

class Game::MeshSelector : public Engine::Component
{
public :

	~MeshSelector() override = default;

	std::list<std::shared_ptr<Engine::Mesh>> getSelectedMeshes() const;
	void updateMapNodeScale(float valueScale);

protected :

	void prepared() override;
	void updated() override;

private :

	std::shared_ptr<Engine::Model> _model;

	std::shared_ptr<std::map<std::string, Engine::Vector3>> _mapNodeScale;
	std::map<std::string, Engine::Vector3>::const_iterator _iterator;

	std::shared_ptr<Engine::Material> _selectionMaterial;
	std::list<std::shared_ptr<Engine::Mesh>> _selectedMeshes;

	bool _isSelectionEnabled;

	void incrementSelectedNode();
	void decrementSelectedNode();

	void updateSelectedMesh();
};