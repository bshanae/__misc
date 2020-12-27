package model.closed.objects.creatures.enemies;

import application.utils.Range;
import model.closed.objects.Attack;

import java.util.LinkedList;
import java.util.List;

public class			Hollow extends Enemy
{
	@Override
	public int			getBaseHealth()
	{
		return 100;
	}

	public				Hollow()
	{
		super("Hollow");
	}

	@Override
	public List<Attack>	getAttacks()
	{
		List<Attack>	attacks;

		attacks = new LinkedList<>();
		attacks.add(new Attack("Punch", 60, new Range<>(20, 30), 0.01f));
		attacks.add(new Attack("Byte", 40, new Range<>(30, 40), 0.05f));

		return attacks;
	}
}
