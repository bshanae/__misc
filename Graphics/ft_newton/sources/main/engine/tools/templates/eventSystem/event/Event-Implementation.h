#pragma once

#include "Event.h"
#include "engine/tools/templates/eventSystem/eventSystemUtility/EventSystemUtility.h"

namespace engine
{
	template<typename ...T_ARGS>
	Event<T_ARGS...>::~Event()
	{
		EventSystemUtility::destroyEvent(*this);
	}

	template<typename ...T_ARGS>
	void Event<T_ARGS...>::invoke(T_ARGS &&...args) const
	{
		for (auto *unsubscribeRequest: _unsubscribeRequests)
			_listeners.erase(unsubscribeRequest);

		_unsubscribeRequests.clear();

		for (const auto &[listener, function]: _listeners)
			function(args...);
	}
}
