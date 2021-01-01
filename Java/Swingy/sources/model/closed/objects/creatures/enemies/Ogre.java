package model.closed.objects.creatures.enemies;

import application.utils.Range;
import model.closed.objects.Attack;

import java.util.LinkedList;
import java.util.List;

public class				Ogre extends Enemy
{
// -----------------------> Constructor

	public					Ogre()
	{
		super("Ogre", 1);
	}

// -----------------------> Properties

	@Override
	public int				getBaseHealth()
	{
		return 1000;
	}

	@Override
	public int				getDefense()
	{
		return 0;
	}

	@Override
	public List<Attack>		getAttacks()
	{
		List<Attack>		attacks;

		attacks = new LinkedList<>();
		attacks.add(new Attack("Punch", 90, new Range<>(30, 30), 0.01f));
		attacks.add(new Attack("Fall", 10, new Range<>(150, 250), 0.01f));

		return attacks;
	}
}
