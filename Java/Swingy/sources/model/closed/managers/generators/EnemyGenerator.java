package model.closed.managers.generators;

import application.service.Debug;
import model.closed.managers.Session;
import model.closed.managers.metas.enemyMeta.EnemyMeta;
import model.closed.managers.metas.enemyMeta.HollowMeta;
import model.closed.managers.metas.enemyMeta.HollowSoldierMeta;
import model.closed.managers.metas.enemyMeta.OgreMeta;
import model.closed.objects.creatures.enemies.Enemy;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public abstract class				EnemyGenerator
{
// -------------------------------> Constants

	private static final int		NUMBER_OF_ATTEMPTS_TO_SELECT_ENEMY = 100;

// -------------------------------> Attributes

	private static final
	List<EnemyMeta>					allEnemyMetas = new ArrayList<EnemyMeta>()
	{{
		add(new HollowMeta());
		add(new HollowSoldierMeta());
		add(new OgreMeta());

	}};

// -------------------------------> Public methods

	public static Enemy				generate()
	{
		List<EnemyMeta>				possibleEnemies;
		EnemyMeta					selectedEnemy;

		possibleEnemies = generateEnemiesForCurrentLevel();
		selectedEnemy = selectRandomEnemy(possibleEnemies);

		Debug.logFormat("[Model/EnemyGenerator] Spawning enemy using meta '%s'", selectedEnemy.getClass());

		return selectedEnemy.getInstance();
	}

// -------------------------------> Private methods

	private static List<EnemyMeta>	generateEnemiesForCurrentLevel()
	{
		List<EnemyMeta>				list;

		list = new LinkedList<>();
		for (EnemyMeta enemyMeta : allEnemyMetas)
		{
			if (enemyMeta.getAppearanceLevel() <= Session.getInstance().getLevel())
				list.add(enemyMeta);
		}

		return list;
	}

	private static EnemyMeta		selectRandomEnemy(List<EnemyMeta> list)
	{
		int							selectedIndex;
		EnemyMeta					selectedMeta;

		float						appearanceProbability;

		for (int i = 0; i < NUMBER_OF_ATTEMPTS_TO_SELECT_ENEMY; i++)
		{
			selectedIndex = RandomGenerator.randomBetween(0, list.size() - 1);
			selectedMeta = list.get(selectedIndex);

			appearanceProbability = getTransformedAppearanceProbability(selectedMeta);

			if (RandomGenerator.randomWithProbability(appearanceProbability))
				return selectedMeta;
		}

		Debug.throwException("Can't select enemy");
		return list.get(0);
	}

	private static float			getTransformedAppearanceProbability(EnemyMeta meta)
	{
		int							currentLevel;
		int							appearanceLevel;

		float						appearProbabilityMultiplier;

		currentLevel = Session.getInstance().getLevel();
		appearanceLevel = meta.getAppearanceLevel();

		appearProbabilityMultiplier = 1.f;

		if (currentLevel > appearanceLevel)
		{
			appearProbabilityMultiplier = 1.f - 0.05f * (currentLevel - appearanceLevel);
			appearProbabilityMultiplier = Math.max(0.f, appearProbabilityMultiplier);
		}

		return meta.getAppearanceProbability() * appearProbabilityMultiplier;
	}
}
