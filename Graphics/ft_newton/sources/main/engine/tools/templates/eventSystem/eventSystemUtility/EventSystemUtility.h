#pragma once

#include "engine/tools/Tools.h"

#include "engine/tools/templates/eventSystem/event/Event.h"
#include "engine/tools/templates/eventSystem/listener/Listener.h"

class engine::EventSystemUtility
{
public :

	~EventSystemUtility() = delete;

	template <typename T_FUNC, typename ...T_ARGS>
	static void subscribeListenerToEvent(Event<T_ARGS...> &event, Listener &listener, T_FUNC &&functor);

	template<class ...T_ARGS>
	static void unsubscribeListenerFromEvent(Event<T_ARGS...> &event, Listener &listener);

	template<class ...T_ARGS>
	static void destroyEvent(Event<T_ARGS...> &event);

	static void destroyListener(Listener &listener);
};