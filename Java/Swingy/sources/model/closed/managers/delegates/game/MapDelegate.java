package model.closed.managers.delegates.game;

import application.utils.Point;
import controller.open.Commands;
import model.closed.managers.Map;
import model.closed.managers.Session;
import model.closed.managers.delegates.Delegate;
import model.closed.managers.generators.MapGenerator;
import model.closed.objects.creatures.Creature;
import model.closed.objects.creatures.enemies.Enemy;
import model.closed.objects.creatures.hero.Hero;
import model.open.Requests;

import java.util.List;

public class				MapDelegate extends Delegate
{
	private final Hero		hero;
	private final Map		map;

	public					MapDelegate()
	{
		hero = Session.getInstance().getHero();
		map = MapGenerator.getInstance().generate();

		Session.getInstance().setMap(map);
	}

	@Override
	protected void			whenActivated(boolean isFirstTime)
	{
		drawMap();
	}

	@Override
	public void				whenResponded(Commands.Abstract command)
	{
		tryMoveHero(command);
		tryResolve();
		tryStartBattle();
	}

	private void			drawMap()
	{
		sendRequest(new Requests.Map(map, hero.getPosition()));
	}

	private void			tryMoveHero(Commands.Abstract command)
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

		drawMap();
	}

	private void			tryResolve()
	{
		if (map.getCreatures().size() == 1)
		{
			Session.getInstance().setMap(null);
			resolve();
		}
	}

	private void			tryStartBattle()
	{
		Enemy				enemy;

		enemy = checkCollision();
		if (enemy != null)
			linkChild(new BattleDelegate(enemy));
	}

	private Enemy			checkCollision()
	{
		List<Creature>		creatures;

		creatures = map.getCreaturesAt(hero.getPosition());

		for (Creature creature : creatures)
		{
			if (creature instanceof Enemy)
				return (Enemy)creature;
		}

		return null;
	}
}
