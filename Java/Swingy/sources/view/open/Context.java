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
	MAP;

	private static final
	Map<Class<?>, Context>	requestToContext = new HashMap<Class<?>, Context>()
	{{
		put(Requests.Error.class, ERROR);
		put(Requests.HeroSelector.class, HERO_SELECTOR);
		put(Requests.HeroNameEntry.class, NAME_ENTRY);
		put(Requests.ClassSelector.class, HERO_SELECTOR);
		put(Requests.Map.class, MAP);
	}};

	public static Context	getContext(Requests.Ui request)
	{
		assert requestToContext.containsKey(request.getClass());
		return requestToContext.get(request.getClass());
	}
}
