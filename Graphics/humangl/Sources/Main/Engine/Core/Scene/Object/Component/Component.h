#pragma once

#include <memory>

namespace Engine
{
	class Object;
	class Component;
}

class Engine::Component
{
public :

	Component();
	virtual ~Component() = default;

	std::shared_ptr<Object> getObject() const;

protected :

	virtual void initialized();
	virtual void deinitialized();

	virtual void prepared();
	virtual void updated();
	virtual void rendered();

private :

	friend class Object;
	friend class ComponentManipulator;

	bool _isPrepared;
	int _numberOfLivedFrames;

	std::shared_ptr<Object> _object;
};