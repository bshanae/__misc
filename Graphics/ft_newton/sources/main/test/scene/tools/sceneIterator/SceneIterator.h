#pragma once

#include "test/Test.h"

#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/std/function.h"
#include "engine/tools/templates/eventSystem/listener/Listener.h"

class test::SceneIterator final : public Listener
{
public :

	SceneIterator(Scene &scene, std::function<bool (Object &)> filter);
	~SceneIterator() = default;

	void loadTargets();

	bool hasTarget() const;
	Object *getTarget() const;

	void incrementTarget();

private :

	Scene &_scene;
	std::function<bool (Object &)> _filter;

	std::vector<Object *> _allTargets;
	int _targetIndex;
};
