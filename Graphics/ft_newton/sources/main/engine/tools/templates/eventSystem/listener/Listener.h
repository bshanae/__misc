#pragma once

#include "engine/tools/Tools.h"

#include "engine/tools/external/std/map.h"
#include "engine/tools/external/std/function.h"

class engine::Listener
{
	friend class EventSystemUtility;

public :

	Listener() = default;
	Listener(const Listener &) = delete;

	virtual ~Listener();

	Listener &operator = (const Listener &) = delete;

	template <typename T_FUNC, typename ...T_ARGS>
	void subscribe(Event<T_ARGS...> &event, T_FUNC &&functor);

	template <typename ...T_ARGS>
	void unsubscribe(Event<T_ARGS...> &event);

private :

	map<void *, function<void(void)>> _eventsAndUnsubscribeFunctions;
};