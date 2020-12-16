package model.closed.gameObjects;

import application.common.Point;
import model.closed.gameObjects.creatures.Creature;
import model.closed.gameObjects.creatures.hero.Hero;
import model.closed.gameObjects.creatures.hero.HeroClass;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class						Map
{
	private final Point				size;
	private final List<Creature>	creatures;

	private static int				getSizeForLevel(int level)
	{
		return (level - 1 ) * 5 + 10 - (level % 2);
	}

	public Point					getSize()
	{
		return size;
	}

	public List<Creature>			getCreatures()
	{
		return Collections.unmodifiableList(creatures);
	}

	public 							Map(Hero hero)
	{
//		size = new Point(getSizeForLevel(hero.getLevel()));
		size = new Point(5, 10);
		creatures = new LinkedList<>();

		addCreature(hero);

		Hero test = new Hero("", HeroClass.ASSASSIN);
		test.setPosition(getSize().subtract(new Point(1)).divide(2).add(new Point(-1, 1)));
		addCreature(test);
	}

	public void 					addCreature(Creature creature)
	{
		creatures.add(creature);
	}
}
