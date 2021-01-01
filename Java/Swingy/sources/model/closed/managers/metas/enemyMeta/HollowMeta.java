package model.closed.managers.metas.enemyMeta;

import model.closed.objects.creatures.enemies.Enemy;
import model.closed.objects.creatures.enemies.Hollow;

public class		HollowMeta extends EnemyMeta
{
	@Override
	public int		getAppearanceLevel()
	{
		return 0;
	}

	@Override
	public float	getAppearanceProbability()
	{
		return 1.f;
	}

	@Override
	public Enemy	getInstance()
	{
		return new Hollow();
	}
}
