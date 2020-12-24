package model.closed.managers.delegates.game;

import application.utils.Point;
import controller.open.Commands;
import model.closed.managers.Map;
import model.closed.managers.delegates.Delegate;
import model.closed.managers.generators.MapGenerator;
import model.closed.objects.creatures.hero.Hero;
import model.open.Requests;

public class				MapDelegate extends Delegate
{
	private final Hero		hero;
	private final Map		map;

	public					MapDelegate(Hero hero)
	{
		this.hero = hero;
		this.map = MapGenerator.getInstance().generate();
	}

	@Override
	protected void			whenActivated(boolean isFirstTime)
	{
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
		else
			; // TODO error

		sendRequest(new Requests.Map(map, hero.getPosition()));
	}
}
