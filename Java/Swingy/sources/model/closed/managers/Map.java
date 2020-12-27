package model.closed.managers;

import application.utils.Point;
import model.closed.objects.creatures.Creature;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class						Map
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

	public 							Map(Point size)
	{
		this.size = size;
		this.creatures = new LinkedList<>();
	}

	public void 					addCreature(Creature creature)
	{
		creatures.add(creature);
	}

	public List<Creature>			getCreaturesAt(Point position)
	{
		List<Creature>				creatures;

		creatures = new LinkedList<>();
		for (Creature creature : this.creatures)
		{
			if (creature.getPosition().equals(position))
				creatures.add(creature);
		}

		return creatures;
	}
}
