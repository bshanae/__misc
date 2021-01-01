package model.closed.objects.creatures.enemies;

import model.closed.objects.creatures.Creature;

public abstract class				Enemy extends Creature
{
// -------------------------------> Attributes

	private final int				level;

// -------------------------------> Constructor

	public 							Enemy(String name, int level)
	{
		super(name);
		this.level = level;
	}

// -------------------------------> Properties

	@Override
	public int						getLevel()
	{
		return level;
	}

	public int						getExperienceForDefeating()
	{
		return 200 * (level + 1) * (level + 1);
	}
}