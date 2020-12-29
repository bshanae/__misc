package view.open;

import model.open.Requests;

import java.util.HashMap;
import java.util.Map;

public enum					Context
{
	ERROR,
	HERO_SELECTOR,
	NAME_ENTRY,
	CLASS_SELECTOR,
	MAP,
	BATTLE;

	private static final
	Map<Class<?>, Context>	requestToContext = new HashMap<Class<?>, Context>()
	{{
		put(Requests.Error.class, ERROR);
		put(Requests.HeroSelector.class, HERO_SELECTOR);
		put(Requests.NameEntry.class, NAME_ENTRY);
		put(Requests.ClassSelector.class, HERO_SELECTOR);
		put(Requests.Map.class, MAP);
		put(Requests.Battle.class, BATTLE);
	}};

	public static Context	parse(Requests.Abstract request)
	{
		assert requestToContext.containsKey(request.getClass());
		return requestToContext.get(request.getClass());
	}
}
