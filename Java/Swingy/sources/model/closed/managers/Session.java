package model.closed.managers;

import application.utils.SingletonMap;
import model.closed.objects.creatures.hero.Hero;

public class				Session
{
	private Hero			hero;

	public static Session	getInstance()
	{
		return SingletonMap.getInstanceOf(Session.class);
	}

	public Hero				getHero()
	{
		return hero;
	}

	public void				setHero(Hero hero)
	{
		this.hero = hero;
	}

	public int				getLevel()
	{
		return hero.getLevel();
	}
}
