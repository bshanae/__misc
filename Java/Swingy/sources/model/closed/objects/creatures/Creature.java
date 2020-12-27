package model.closed.objects.creatures;

import application.utils.Point;
import model.closed.objects.Attack;

import java.util.List;

public abstract class				Creature
{
	private final String			name;

	private int						health;
	private int						defense;
	private Point					position;

	public String					getName()
	{
		return name;
	}

	public int						getHealth()
	{
		return health;
	}

	public void						setHealth(int health)
	{
		this.health = health;
	}

	public int						getDefense()
	{
		return defense;
	}

	public void						setDefense(int defense)
	{
		this.defense = defense;
	}

	public Point					getPosition()
	{
		return position;
	}

	public void						setPosition(Point position)
	{
		assert position != null;
		this.position = position;
	}

	public							Creature(String name)
	{
		this.name = name;
	}

	public abstract List<Attack>	getAttacks();

	public boolean					isAlive()
	{
		return health > 0;
	}

	public boolean					isDead()
	{
		return health <= 0;
	}
}
