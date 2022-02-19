#pragma once

#include "engine/tools/Tools.h"
#include "engine/modules/physics/Physics.h"

#include "engine/tools/external/std/move.h"
#include "engine/tools/templates/eventSystem/listener/Listener.h"
#include "engine/core/module/Module.h"
#include "engine/modules/physics/algorithm/collision/Collision.h"

class engine::physics::Module : public engine::Module<engine::physics::Module>, public Listener
{
public :

	~Module() override = default;

	static inline const vector<Collision> &getCollisions()
	{
		return getInstance()._collisions;
	}

	static inline unsigned getNumberOfColliders()
	{
		return getInstance()._colliders.size();
	}

	static void updateSimulation(float deltaTime);

protected :

	void initializeInternally() override;

	void onSceneLaunchingInternal(const YAML::Node &metaNode) override;
	void onSceneLaunchedInternal() override;
	void onSceneClosingInternal() override;

private :

	map<Object *, Collider *> _colliders;
	map<Object *, RigidBody *> _rigidBodies;
	vector<Collision> _collisions;

	void resetSimulation();

	void resetCollisions();
	void detectCollisions();
	void resolveCollisions(float deltaTime);
	void integrate(float deltaTime);
	void performLinearProjection();

	void processScene(Scene &scene);
	void processComponent(Object &object, Component &component);
};
