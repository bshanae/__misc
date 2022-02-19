#pragma once

#include "engine/core/Core.h"

#include "engine/tools/external/std/set.h"
#include "engine/tools/external/std/queue.h"
#include "engine/tools/external/std/pointers.h"
#include "engine/tools/templates/eventSystem/EventSystem.h"

class engine::Scene final : public Listener
{
//	friend class Processor;

#pragma mark events

public :

	Event<Object &> objectAdded;
	Event<Object &, Component &> componentAddedToObject;
	Event<> launched;
	Event<> updating;
	Event<> updated;

#pragma mark construction/desctruction

public :

	Scene(const string &sourceFileName);
	Scene(const Scene &) = delete;

	~Scene() override;

#pragma mark operators

public :

	Scene &operator = (const Scene &) = delete;

#pragma mark properties

public :

	inline const string &getFileName() const
	{
		return _fileName;
	}

#pragma mark lifetime

public :

	inline bool isLaunched() const
	{
		return _isLaunched;
	}

	inline bool isClosed() const
	{
		return _isClosed;
	}

	void launch();

	void close();

private :

	const string _fileName;
	bool _isLaunched;
	bool _isClosed;

#pragma mark objects

public :

	/// Important: new object doesn't appear in scene' objects list immediately
	Object &addObject(const string &name, const string &tag = "");

	void fetch();

	/// Return copy of vector with objects. Costly operation.
	vector<Object *> getTopObjects() const;

	/// Visit all objects recursively.
	void traverseObjects(const function<void (Object &)> &action) const;

	Object &selectObjectByTag(const string &tag) const;
	Object *trySelectObjectByTag(const string &tag) const;
	const set<Object *> &selectAllObjectsByTag(const string &tag) const;

private :

	vector<unique_ptr<Object>> _objects;
	queue<unique_ptr<Object>> _newObjects;
	map<string, set<Object *>> _tagGroups;
	mutable bool _isTraversingObjects;

	void processNewObject(Object &object);
	void fetchObjects();
};