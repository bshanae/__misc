package model.closed.gameObjects.creatures.hero;

import application.common.Describable;

import java.util.HashMap;
import java.util.Map;

public enum						HeroClass implements Describable
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

	@Override
	public String				getShortDescription()
	{
		return toString();
	}

	@Override
	public String			getLongDescription()
	{
		return "[HeroClass : value = " + toString() + "]";
	}

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