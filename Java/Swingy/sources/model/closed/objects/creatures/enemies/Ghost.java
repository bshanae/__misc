package model.closed.objects.creatures.enemies;

import model.closed.objects.Attack;

import java.util.LinkedList;
import java.util.List;

public class			Ghost extends Enemy
{
	public				Ghost()
	{
		super("Ghost");
	}

	@Override
	public List<Attack>	getAttacks()
	{
		return new LinkedList<>();
	}
}
