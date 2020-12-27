package model.closed.managers.battle;

import model.closed.objects.creatures.Creature;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class					BattleLogger
{
	private final List<String>	lines;

	public List<String>			getLines()
	{
		return Collections.unmodifiableList(lines);
	}

	public						BattleLogger()
	{
		lines = new LinkedList<>();
	}

	public void					logAwait()
	{
		lines.add("Battle will start soon...");
	}

	public void					logAttack(BattleTurnReport report)
	{
		logFormat
		(
			"'%s' hit '%s' with %s '%s' and dealt %d damage. Now '%s' has %d hp.",
			report.attacker.getName(),
			report.attackee.getName(),
			report.isCritical ? "critical" : "",
			report.attack.name,
			report.damage,
			report.attackee.getName(),
			report.attackee.getHealth()
		);

		if (report.isBattleFinished)
			logEndOfBattle(report);
	}

	private void				logEndOfBattle(BattleTurnReport report)
	{
		final Creature			winner = report.attacker;
		final Creature			loser = report.attackee;

		logFormat("'%s' killed '%s' and won the battle.", winner.getName(), loser.getName());
	}

	private void				logFormat(String format, Object... arguments)
	{
		lines.add(String.format(format, arguments));
	}
}
