package model.open;

import application.common.Point;

import java.util.*;

public abstract class					Pockets
{
	private static final
	HashMap<Class<?>, Class<?>>			objectToPocket = new HashMap<Class<?>, Class<?>>()
	{{
		put(model.closed.gameObjects.creatures.enemies.Enemy.class, Enemy.class);
		put(model.closed.gameObjects.creatures.hero.Hero.class, Hero.class);
	}};

	public static Abstract				build(Object object)
	{
		final Class<?>					objectClass = object.getClass();

		try
		{
			assert objectToPocket.containsKey(objectClass);
			return (Abstract)objectToPocket.get(objectClass).getConstructor(objectClass).newInstance(object);
		}
		catch (Exception exception)
		{
			exception.printStackTrace();
			assert false;
			return null;
		}
	}

	public interface					Abstract {}

	public static class					Creature implements Abstract
	{
		private final Point				position;

		public Point					getPosition()
		{
			return position;
		}

		public							Creature(Point position)
		{
			this.position = position;
		}
	}

	public static class					Enemy extends Creature
	{
		public 							Enemy(model.closed.gameObjects.creatures.enemies.Enemy enemy)
		{
			super(enemy.getPosition());
		}
	}

	public static class					Hero extends Creature
	{
		private final String			name;

		public String					getName()
		{
			return name;
		}

		public 							Hero(model.closed.gameObjects.creatures.hero.Hero hero)
		{
			super(hero.getPosition());
			this.name = hero.getName();
		}
	}

	public static class					Map implements Abstract
	{
		private final Point				size;
		private final List<Creature>	creatures;

		public Point					getSize()
		{
			return size;
		}

		public List<Creature>			getCreatures()
		{
			return Collections.unmodifiableList(creatures);
		}

		public							Map(model.closed.gameObjects.Map map)
		{
			size = map.getSize();
			creatures = new LinkedList<>();

			for (model.closed.gameObjects.creatures.Creature creature : map.getCreatures())
			{
				if (creature instanceof model.closed.gameObjects.creatures.hero.Hero)
					creatures.add(new Hero((model.closed.gameObjects.creatures.hero.Hero)(creature)));
				else if (creature instanceof model.closed.gameObjects.creatures.enemies.Enemy)
					creatures.add(new Enemy((model.closed.gameObjects.creatures.enemies.Enemy)(creature)));
			}
		}
	}
}