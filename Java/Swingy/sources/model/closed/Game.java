package model.closed;

import application.common.SingletonMap;
import controller.open.Commands;
import model.closed.gameConcepts.heroStorage.HeroStorage;
import model.closed.gameConcepts.delegates.core.CoreDelegate;

public class						Game
{
	private enum					State
	{
		WAITING,
		RUNNING,
		TERMINATED
	}

	private State					state;
	private final CoreDelegate		coreDelegate;

	public static Game				getInstance()
	{
		return SingletonMap.getInstanceOf(Game.class);
	}

	public boolean					isTerminated()
	{
		return state == State.TERMINATED;
	}

// -------------------------------> Constructor

	public							Game()
	{
		coreDelegate = new CoreDelegate();
		state = State.WAITING;
	}

// -------------------------------> Control methods

	public void						run()
	{
		state = State.RUNNING;

		HeroStorage.getInstance().download();
		coreDelegate.run();
	}

	public void						terminate()
	{
		state = State.TERMINATED;

		HeroStorage.getInstance().upload();
		coreDelegate.terminate();
	}

	public void						update()
	{
		coreDelegate.update();
	}

	public void						respondToCommand(Commands.Abstract command)
	{
		coreDelegate.respond(command);
	}
}
