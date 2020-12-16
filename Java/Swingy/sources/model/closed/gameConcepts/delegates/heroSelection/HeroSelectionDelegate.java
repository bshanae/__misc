package model.closed.gameConcepts.delegates.heroSelection;

import controller.open.Commands;
import model.closed.gameObjects.creatures.hero.Hero;
import model.closed.gameConcepts.heroStorage.HeroStorage;
import model.closed.gameConcepts.delegates.Delegate;
import model.closed.gameConcepts.delegates.common.ErrorDelegate;
import model.open.Pockets;
import model.open.Requests;

import java.util.LinkedList;
import java.util.List;

public class				HeroSelectionDelegate extends Delegate
{
// ----------------------->	Fields

	private boolean			isWaitingForNewHero;

// ----------------------->	Open methods

	@Override
	public void				whenActivated(boolean isFirstTimeActivated)
	{
		if (!isWaitingForNewHero)
			showHeroSelectionScreen();
	}

	@Override
	public void				whenResponded(Commands.Abstract command)
	{
		if (tryRespondToCommonCommands(command))
			return ;

		if (command instanceof Commands.Create)
		{
			linkChild(new HeroCreationDelegate());
			isWaitingForNewHero = true;
		}
		else if (command instanceof Commands.Select)
		{
			try
			{
				selectHero((Commands.Select)command);
			}
			catch (InvalidCommandException exception)
			{
				linkChild(new ErrorDelegate("Hero not found"));
			}
		}
		else if (command instanceof Commands.Delete)
		{

		}
	}

	@Override
	protected void			whenChildResolved(Object message)
	{
		if (isWaitingForNewHero)
		{
			assert message instanceof Hero;
			resolve(message);

			isWaitingForNewHero = false;
		}
	}

// ----------------------->	Closed methods

	private void			showHeroSelectionScreen()
	{
		List<Pockets.Hero>	heroes;

		heroes = new LinkedList<>();

		for (Hero hero : HeroStorage.getInstance().getCopy())
			heroes.add((Pockets.Hero)Pockets.build(hero));

		sendRequest(new Requests.HeroSelector(heroes));
	}

	private void			selectHero(Commands.Select command) throws InvalidCommandException
	{
		try
		{
			resolve(HeroStorage.getInstance().find(command.getValue()));
		}
		catch (HeroStorage.HeroNotFoundException exception)
		{
			throw new InvalidCommandException();
		}
	}
}
