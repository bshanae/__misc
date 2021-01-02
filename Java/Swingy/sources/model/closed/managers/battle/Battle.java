package model.closed.managers.battle;

import model.closed.objects.Attack;
import model.closed.managers.Session;
import model.closed.managers.generators.AttackGenerator;
import model.closed.objects.creatures.Creature;
import model.closed.objects.creatures.enemies.Enemy;
import model.closed.objects.creatures.hero.Hero;

public class					Battle
{
// ---------------------------> Attributes

	private final Hero			hero;
	private final Enemy			opponent;

	private BattleTurn			turn;
	private BattleLogger		logger;

// ---------------------------> Properties

	public Hero					getHero()
	{
		return hero;
	}

	public Enemy				getOpponent()
	{
		return opponent;
	}

	public BattleLogger			getLogger()
	{
		return logger;
	}

	public void 				setLogger(BattleLogger logger)
	{
		if (this.logger != null)
			throw new RuntimeException("Logger is already set");

		this.logger = logger;
		this.logger.logAwait();
	}

// ---------------------------> Constructor

	public						Battle(Enemy opponent)
	{
		this.hero = Session.getHero();
		this.opponent = opponent;

		hero.resetHealth();
		opponent.resetHealth();

		turn = BattleTurn.HERO;
	}

// ---------------------------> Public methods

	public void					executeTurn()
	{
		BattleTurnReport		report = null;

		if (isFinished())
			throw new RuntimeException();

		switch (turn)
		{
			case HERO:
				report = performAttack(hero, opponent);
				break;

			case OPPONENT:
				report = performAttack(opponent, hero);
				break;
		}

		if (logger != null)
			logger.logAttack(report);

		turn = turn.next();
	}

	public boolean				isFinished()
	{
		return hero.isDead() || opponent.isDead();
	}

// ---------------------------> Private methods

	private BattleTurnReport	performAttack(Creature attacker, Creature attackee)
	{
		Attack					attack;
		boolean					isCritical;
		int						damage;

		attack = AttackGenerator.generateAttack(attacker.getAttacks());
		isCritical = AttackGenerator.generateIsCritical(attack);
		damage = AttackGenerator.generateDamage(attack, isCritical);

		attackee.hit(damage);

		if (attackee.isDead())
			finish(attacker, attackee);

		return new BattleTurnReport(attacker, attackee, attack, isCritical, damage, isFinished());
	}

	private void				finish(Creature winner, Creature loser)
	{
		Hero					hero;
		Enemy					enemy;

		if (winner instanceof Hero)
		{
			hero = (Hero)winner;
			enemy = (Enemy)loser;

			hero.addExperience(enemy.getExperienceForDefeating());
		}

		Session.getMap().getCreatures().remove(loser);
	}
}
