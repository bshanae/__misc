package model.closed.managers.battle;

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

	public void					logAttack(AttackReport report)
	{
		lines.add
		(
			String.format
			(
				"[%s] hit [%s] with '%s %s' and dealt %d damage",
				report.attacker.getName(),
				report.attackee.getName(),
				report.isCritical ? "critical" : "",
				report.attack.name,
				report.damage
			)
		);
	}
}
