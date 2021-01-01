package model.closed.managers.metas.enemyMeta;

import model.closed.objects.creatures.enemies.Enemy;

public abstract class		EnemyMeta
{
	public abstract int		getAppearanceLevel();

	public abstract float	getAppearanceProbability();

	public abstract Enemy	getInstance();
}
