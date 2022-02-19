#pragma once

#include "Listener.h"
#include "engine/tools/templates/eventSystem/eventSystemUtility/EventSystemUtility.h"

namespace engine
{
	template<typename T_FUNC, typename ...T_ARGS>
	void Listener::subscribe(Event<T_ARGS...> &event, T_FUNC &&functor)
	{
		EventSystemUtility::subscribeListenerToEvent(event, *this, functor);
	}

	template<typename ...T_ARGS>
	void Listener::unsubscribe(Event<T_ARGS...> &event)
	{
		EventSystemUtility::unsubscribeListenerFromEvent(event, *this);
	}

	inline Listener::~Listener()
	{
		EventSystemUtility::destroyListener(*this);
	}
}