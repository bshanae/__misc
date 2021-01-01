package model.closed.managers.metas.enemyMeta;

import model.closed.objects.creatures.enemies.Enemy;
import model.closed.objects.creatures.enemies.Hollow;
import model.closed.objects.creatures.enemies.Ogre;

public class		OgreMeta extends EnemyMeta
{
	@Override
	public int		getAppearanceLevel()
	{
		return 1;
	}

	@Override
	public float	getAppearanceProbability()
	{
		return 0.5f;
	}

	@Override
	public Enemy	getInstance()
	{
		return new Ogre();
	}
}
