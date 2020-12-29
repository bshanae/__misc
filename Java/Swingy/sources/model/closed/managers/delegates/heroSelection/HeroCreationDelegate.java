package model.closed.managers.delegates.heroSelection;

import controller.open.Commands;
import model.closed.objects.creatures.hero.Hero;
import model.closed.objects.creatures.hero.HeroClass;
import model.closed.managers.heroStorage.HeroStorage;
import model.closed.managers.delegates.Delegate;
import model.closed.managers.delegates.common.ErrorDelegate;
import model.open.Requests;

public class			HeroCreationDelegate extends Delegate
{
	private enum		State
	{
		PENDING,
		WAITING_FOR_NAME,
		RECEIVED_NAME,
		WAITING_FOR_CLASS,
		RECEIVED_CLASS,
		CREATED_HERO
	}

	private State		state;

	private String		heroName;
	private HeroClass	heroClass;
	private Hero		hero;

// ------------------->	Open methods

	public				HeroCreationDelegate()
	{
		state = State.PENDING;
	}

	@Override
	public void			whenActivated(boolean isFirstTimeActivated)
	{
		requestName();
	}

	@Override
	public void			whenUpdated()
	{
		switch (state)
		{
			case RECEIVED_NAME:
				requestClass();
				break;

			case CREATED_HERO:
				requestResolution(hero);
				break;
		}
	}

	@Override
	public void			whenResponded(Commands.Abstract command)
	{
		if (tryRespondToCommonCommands(command))
			return ;

		switch (state)
		{
			case WAITING_FOR_NAME :
				extractName(command);
				requestClass();
				break;

			case WAITING_FOR_CLASS:
				try
				{
					extractClass(command);
					createHero();
				}
				catch (HeroClass.ClassNotFoundException exception)
				{
					linkChild(new ErrorDelegate("Unknown class"));
					requestClass();
				}
				break;
		}
	}
// ------------------->	Closed methods

	private void		requestName()
	{
		state = State.WAITING_FOR_NAME;
		sendRequest(new Requests.NameEntry());
	}

	private void 		extractName(Commands.Abstract command)
	{
		if (validateCommand(command, Commands.Enter.class))
		{
			heroName = ((Commands.Enter)command).getValueAsString();
			state = State.RECEIVED_NAME;
		}
	}

	private void		requestClass()
	{
		state = State.WAITING_FOR_CLASS;
		sendRequest(new Requests.ClassSelector());
	}

	private void 		extractClass(Commands.Abstract command) throws HeroClass.ClassNotFoundException
	{
		String			classString;

		if (validateCommand(command, Commands.Select.class))
		{
			classString = ((Commands.Select)command).getValueAsString();

			heroClass = HeroClass.fromString(classString);
			state = State.RECEIVED_CLASS;
		}
	}

	private void 		createHero()
	{
		hero = new Hero(heroName, heroClass);
		HeroStorage.getInstance().add(hero);

		state = State.CREATED_HERO;
	}
}
