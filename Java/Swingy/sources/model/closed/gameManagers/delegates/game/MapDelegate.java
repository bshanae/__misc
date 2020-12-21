package model.closed.gameManagers.delegates.game;

import application.utils.Point;
import controller.open.Commands;
import model.closed.gameManagers.delegates.Delegate;
import model.closed.gameObjects.Map;
import model.closed.gameObjects.creatures.hero.Hero;
import model.open.Requests;

public class				MapDelegate extends Delegate
{
	private final Hero		hero;
	private final Map		map;

	public					MapDelegate(Hero hero)
	{
		this.hero = hero;
		map = new Map(hero);
	}

	@Override
	protected void			whenActivated(boolean isFirstTime)
	{
		hero.setPosition(map.getSize().subtract(new Point(1)).divide(2));
		sendRequest(new Requests.Map(map, hero.getPosition()));
	}

	@Override
	protected void			whenUpdated()
	{
	}

	@Override
	public void				whenResponded(Commands.Abstract command)
	{
		if (command instanceof Commands.GoNorth)
			hero.setPosition(hero.getPosition().add(new Point(0, 1)));
		else if (command instanceof Commands.GoEast)
			hero.setPosition(hero.getPosition().add(new Point(1, 0)));
		else if (command instanceof Commands.GoSouth)
			hero.setPosition(hero.getPosition().add(new Point(0, -1)));
		else if (command instanceof Commands.GoWest)
			hero.setPosition(hero.getPosition().add(new Point(-1, 0)));
	}
}
