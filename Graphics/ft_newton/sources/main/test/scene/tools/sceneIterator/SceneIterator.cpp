#include "SceneIterator.h"

#include "engine/core/scene/Scene.h"

using namespace test;

SceneIterator::SceneIterator(Scene &scene, std::function<bool (Object &)> filter) : _scene(scene), _filter(filter)
{
	_targetIndex = 0;
}

void SceneIterator::loadTargets()
{
	const auto processObject = [this](Object &object)
	{
		if (_filter(object))
			_allTargets.push_back(&object);
	};

	_scene.traverseObjects(processObject);
}

bool SceneIterator::hasTarget() const
{
	return _allTargets.size() > 0;
}

Object *SceneIterator::getTarget() const
{
	return _allTargets[_targetIndex];
}

void SceneIterator::incrementTarget()
{
	_targetIndex++;
	if (_targetIndex >= _allTargets.size())
		_targetIndex = 0;
}