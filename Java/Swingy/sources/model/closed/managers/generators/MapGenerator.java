package model.closed.managers.generators;

import application.utils.Point;
import application.utils.SingletonMap;
import model.closed.managers.Map;
import model.closed.managers.Session;
import model.closed.objects.creatures.Creature;
import model.closed.objects.creatures.enemies.Enemy;
import model.closed.objects.creatures.hero.Hero;

public class							MapGenerator
{
	private Map							map;

	public static MapGenerator			getInstance()
	{
		return SingletonMap.getInstanceOf(MapGenerator.class);
	}

	private static int					getSizeForLevel(int level)
	{
		return (level - 1 ) * 5 + 10 - (level % 2);
	}

	private int							getNumberOfEnemies()
	{
		return (int)((float)map.getSize().x * 0.4f);
	}

	public Map							generate()
	{
		Hero							hero;
		int								level;

		int								numberOfEnemies;
		Enemy							enemy;

		hero = Session.getInstance().getHero();
		level = Session.getInstance().getLevel();

		map = new Map(new Point(getSizeForLevel(level)));

		hero.setPosition(map.getSize().subtract(new Point(1)).divide(2));
		map.addCreature(hero);

		numberOfEnemies = getNumberOfEnemies();
		for (int i = 0; i < numberOfEnemies; i++)
		{
			enemy = EnemyGenerator.generate();
			enemy.setPosition(getUniqueRandomPosition());

			map.addCreature(enemy);
		}

		return map;
	}

	private Point						getUniqueRandomPosition()
	{
		Point							position;

		do
		{
			position = Point.random(new Point(0), map.getSize());
		} while (!isPositionUnique(position));

		return position;
	}

	private boolean						isPositionUnique(Point position)
	{
		for (Creature creature : map.getCreatures())
		{
			if (position.equals(creature.getPosition()))
				return false;
		}

		return true;
	}
}
