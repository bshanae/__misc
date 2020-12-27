package model.closed.managers.battle;

import model.closed.objects.Attack;
import model.closed.managers.Session;
import model.closed.managers.generators.AttackGenerator;
import model.closed.objects.creatures.Creature;
import model.closed.objects.creatures.enemies.Enemy;
import model.closed.objects.creatures.hero.Hero;

public class				Battle
{
	private enum			Turn
	{
		HERO,
		OPPONENT;

		public Turn			next()
		{
			switch (this)
			{
				case HERO:
					return OPPONENT;

				case OPPONENT:
					return HERO;
			}

			return null;
		}
	}

	private final Hero		hero;
	private final Enemy		opponent;

	private Turn			turn;
	private BattleLogger	logger;

	public					Battle(Enemy opponent)
	{
		hero = Session.getInstance().getHero();
		this.opponent = opponent;

		turn = Turn.HERO;
	}

	public void 			attachLogger(BattleLogger logger)
	{
		this.logger = logger;
	}

	public AttackReport		executeTurn()
	{
		AttackReport		report = null;

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
		return report;
	}

	public boolean			isFinished()
	{
		return hero.isDead() || opponent.isDead();
	}

	private AttackReport	performAttack(Creature attacker, Creature attackee)
	{
		Attack				attack;
		boolean				isCritical;
		int					damage;

		attack = AttackGenerator.generateAttack(attacker.getAttacks());
		isCritical = AttackGenerator.generateIsCritical(attack);
		damage = AttackGenerator.generateDamage(attack, isCritical);

		attackee.setHealth(attackee.getHealth() - damage);

		return new AttackReport(attacker, attackee, attack, isCritical, damage);
	}
}
