package model.closed.managers.delegates.game;

import controller.open.Commands;
import model.closed.managers.delegates.Delegate;
import model.closed.objects.creatures.hero.Hero;

public class				LevelDelegate extends Delegate
{
	private enum			State
	{
		NULL,
		MAP,
		BATTLE
	}

	private State			state;
	private final Hero		hero;

	public 					LevelDelegate(Hero hero)
	{
		this.hero = hero;
		state = State.NULL;
	}

	@Override
	public void				whenActivated(boolean isFirstTimeActivated)
	{
		if (state == State.NULL)
		{
			state = State.MAP;
			linkChild(new MapDelegate(hero));
		}
	}

	@Override
	public void				whenResponded(Commands.Abstract command)
	{
		resolve();
	}
}
