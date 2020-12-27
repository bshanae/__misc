package model.closed.managers.delegates.game;

import controller.open.Commands;
import model.closed.managers.delegates.Delegate;
import model.closed.objects.creatures.hero.Hero;

public class				GameDelegate extends Delegate
{
	@Override
	public void				whenActivated(boolean isFirstTime)
	{
		if (isFirstTime)
		{
			linkChild(new MapDelegate());
		}
	}

	@Override
	public void				whenResponded(Commands.Abstract command)
	{
		resolve();
	}
}
