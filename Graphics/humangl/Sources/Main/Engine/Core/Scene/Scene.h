#pragma once

#include <vector>
#include <memory>

#include "Exception.h"

namespace Engine
{
	class Object;
	class Scene;
}

class Engine::Scene final : public std::enable_shared_from_this<Engine::Scene>
{
	friend class Processor;

public :

	Scene();

	bool isClosed() const;
	void close();

	void addObject(const std::shared_ptr<Object> &object);
	std::vector<std::shared_ptr<Object>> getObjects() const;

	std::shared_ptr<Object> findObject(const std::string &name) const;
	std::shared_ptr<Object> findMandatoryObject(const std::string &name) const;

private :

	bool _isClosed;
	std::vector<std::shared_ptr<Object>> _objects;
};