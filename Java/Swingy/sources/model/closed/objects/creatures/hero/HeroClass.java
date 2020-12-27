package model.closed.objects.creatures.hero;

import java.util.HashMap;
import java.util.Map;

public enum						HeroClass
{
	WARRIOR,
	SWORDSMAN,
	ASSASSIN,
	MAGE;

	public static class			ClassNotFoundException extends Exception {}

	private static final
	Map<HeroClass, String>		classToString = new HashMap<HeroClass, String>()
	{{
		put(WARRIOR, "Warrior");
		put(SWORDSMAN, "Swordsman");
		put(ASSASSIN, "Assassin");
		put(MAGE, "Mage");
	}};


	private static final
	Map<String, HeroClass>		stringToClass = new HashMap<String , HeroClass>()
	{{
		put("Warrior", WARRIOR);
		put("Swordsman", SWORDSMAN);
		put("Assassin", ASSASSIN);
		put("Mage", MAGE);
	}};

	public String				toString()
	{
		assert classToString.containsKey(this);
		return classToString.get(this);
	}

	public static HeroClass		fromString(String string) throws ClassNotFoundException
	{
		string = string.toLowerCase();

		for (Map.Entry<String, HeroClass> entry : stringToClass.entrySet())
		{
			if (string.equals(entry.getKey().toLowerCase()))
				return entry.getValue();
		}

		throw new ClassNotFoundException();
	}
}
