package model.closed.gameConcepts.delegates.core;

import model.closed.gameObjects.creatures.hero.Hero;
import model.closed.gameConcepts.heroStorage.HeroStorage;
import model.closed.gameConcepts.delegates.Delegate;
import model.closed.gameConcepts.delegates.game.LevelDelegate;
import model.closed.gameConcepts.delegates.heroSelection.HeroSelectionDelegate;
import model.open.Requests;

public class					CoreDelegate extends Delegate
{
	private enum				State
	{
		WAITING,
		SELECTING_HERO,
		SELECTED_HERO,
		PLAYING_GAME,
		PLAYED_GAME,
	}

	private State				state;
	private Hero				hero;

	public void					run()
	{
		this.activate();

		sendRequest(new Requests.SwitchToGui());
	}

	public void					terminate()
	{
		this.deactivate();
	}

	public						CoreDelegate()
	{
		state = State.WAITING;
	}

	@Override
	protected void				whenActivated(boolean isFirstTime)
	{
		if (isFirstTime)
			HeroStorage.getInstance().download();
	}

	@Override
	protected void				whenDeactivated(boolean isFirstTime)
	{
		if (isFirstTime)
			HeroStorage.getInstance().upload();
	}

	@Override
	protected void				whenUpdated()
	{
		switch (state)
		{
			case WAITING:
				state = State.SELECTING_HERO;
				linkChild(new HeroSelectionDelegate());
				break;

			case SELECTED_HERO:
				state = State.PLAYING_GAME;
				linkChild(new LevelDelegate(hero));
				break;

			case PLAYED_GAME:
				resolve();
				break;

			default:
				assert false;
		}
	}

	@Override
	protected void				whenChildResolved(Object message)
	{
		switch (state)
		{
			case SELECTING_HERO:
				assert message instanceof Hero;
				this.hero = (Hero)message;

				state = State.SELECTED_HERO;
				break;

			case PLAYING_GAME:
				state = State.PLAYED_GAME;
				break;

			default:
				assert false;
		}
	}
}
