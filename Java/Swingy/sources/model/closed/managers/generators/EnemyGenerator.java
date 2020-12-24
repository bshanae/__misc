package model.closed.managers.generators;

import model.closed.objects.creatures.enemies.Enemy;

public abstract class	EnemyGenerator
{
	public static Enemy	generate()
	{
		return new Enemy();
	}
}
