#pragma once

#include "EventSystemUtility.h"
#include "engine/tools/debug/Debug.h"
#include "engine/tools/templates/eventSystem/event/Event.h"
#include "engine/tools/templates/eventSystem/listener/Listener.h"
#include "engine/tools/exceptions/Exception.h"

namespace engine
{
	template<typename T_FUNC, typename ...T_ARGS>
	void EventSystemUtility::subscribeListenerToEvent(Event<T_ARGS...> &event, Listener &listener, T_FUNC &&functor)
	{
		if (event._listeners.find(&listener) != event._listeners.end())
			Debug::logWarning("EventSystemUtility", "Listener is already subscribed to event");

		event._listeners[&listener] = function<void(T_ARGS...)>(functor);
		listener._eventsAndUnsubscribeFunctions[&event] = [&event, &listener](){ event._listeners.erase(&listener); };
	}

	template<class ...T_ARGS>
	void EventSystemUtility::unsubscribeListenerFromEvent(Event<T_ARGS...> &event, Listener &listener)
	{
		event._unsubscribeRequests.push_back(&listener);
		listener._eventsAndUnsubscribeFunctions.erase(&event);
	}

	template<class ...T_ARGS>
	void EventSystemUtility::destroyEvent(Event<T_ARGS...> &event)
	{
		for (auto [listener, functor]: event._listeners)
			listener->_eventsAndUnsubscribeFunctions.erase(&event);
	}

	inline void EventSystemUtility::destroyListener(Listener &listener)
	{
		for (auto &[event, unsubscribeFunction]: listener._eventsAndUnsubscribeFunctions)
			unsubscribeFunction();
	}
}