#pragma once

#include "engine/tools/Tools.h"

#include "engine/tools/external/std/vector.h"
#include "engine/tools/external/std/map.h"
#include "engine/tools/external/std/function.h"

template <typename ...T_ARGS>
class engine::Event final
{
	friend class EventSystemUtility;

public :

	Event() = default;
	Event(const Event &) = delete;

	~Event();

	Event &operator = (const Event &) = delete;

	void invoke(T_ARGS &&...args) const;

private :

	mutable map<Listener *, function<void (T_ARGS...)>> _listeners;
	mutable vector<Listener *> _unsubscribeRequests;
};