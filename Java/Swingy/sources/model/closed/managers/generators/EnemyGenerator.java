package model.closed.managers.generators;

import model.closed.objects.creatures.enemies.Enemy;
import model.closed.objects.creatures.enemies.Ghost;

public abstract class	EnemyGenerator
{
	public static Enemy	generate()
	{
		return new Ghost();
	}
}
