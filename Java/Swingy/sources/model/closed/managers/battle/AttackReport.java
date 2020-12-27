package model.closed.managers.battle;

import model.closed.objects.Attack;
import model.closed.objects.creatures.Creature;

public class			AttackReport
{
	final Creature		attacker;
	final Creature		attackee;
	final Attack		attack;
	final boolean		isCritical;
	final int			damage;

	public				AttackReport
						(
							Creature attacker,
							Creature attackee,
							Attack attack,
							boolean isCritical,
							int damage
						)
	{
		this.attacker = attacker;
		this.attackee = attackee;
		this.attack = attack;
		this.isCritical = isCritical;
		this.damage = damage;
	}
}
