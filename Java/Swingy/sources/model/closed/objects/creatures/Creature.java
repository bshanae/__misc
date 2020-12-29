package model.closed.objects.creatures;

import application.utils.Point;
import model.closed.objects.Attack;

import java.util.List;

public abstract class				Creature
{
// -------------------------------> Final attributes

	private final String			name;

// -------------------------------> Attributes

	private int						health;
	private int						defense;
	private Point					position;

// -------------------------------> Abstract properties

	public abstract int				getBaseHealth();

	public abstract List<Attack>	getAttacks();

// -------------------------------> Properties

	public String					getName()
	{
		return name;
	}

	public int						getHealth()
	{
		return health;
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
		this.position = position;
	}

// -------------------------------> Constructor

	protected						Creature(String name)
	{
		this.name = name;
	}

// -------------------------------> Public methods

	public boolean					isAlive()
	{
		return health > 0;
	}

	public boolean					isDead()
	{
		return !isAlive();
	}

// -------------------------------> Public methods : Health

	public void						resetHealth()
	{
		health = getBaseHealth();
	}

	public void						hit(int damage)
	{
		health = Math.max(0, health - damage);
	}
}
