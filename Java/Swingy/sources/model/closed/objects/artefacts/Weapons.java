package model.closed.objects.artefacts;

import application.utils.Range;
import model.closed.objects.Attack;

import java.util.LinkedList;
import java.util.List;

public abstract class		Weapons
{
	public interface		Abstract extends Artefact
	{
		List<Attack>		getAttacks();
	}

	public static class		Sword implements Abstract
	{
		public List<Attack>	getAttacks()
		{
			List<Attack>	attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("regular", 100, new Range<>(1, 2), 0.1f));

			return attacks;
		}
	}
}
