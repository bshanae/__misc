package model.closed.gameManagers.delegates.heroSelection;

import controller.open.Commands;
import model.closed.gameObjects.creatures.hero.Hero;
import model.closed.gameManagers.heroStorage.HeroStorage;
import model.closed.gameManagers.delegates.Delegate;
import model.closed.gameManagers.delegates.common.ErrorDelegate;
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

		if (command instanceof Commands.CreateHero)
		{
			linkChild(new HeroCreationDelegate());
			isWaitingForNewHero = true;
		}
		else if (command instanceof Commands.Select)
			trySelectHero((Commands.Select)command);
		else if (command instanceof Commands.Delete)
			tryDeleteHero((Commands.Delete)command);
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

	private void			trySelectHero(Commands.Select command)
	{
		try
		{
			if (command.getValueAsInteger() != null)
				resolve(HeroStorage.getInstance().get(command.getValueAsInteger()));
			else if (command.getValueAsString() != null)
				resolve(HeroStorage.getInstance().find(command.getValueAsString()));
			else
				assert false;
		}
		catch (HeroStorage.HeroNotFoundException exception)
		{
			linkChild(new ErrorDelegate("Hero not found"));
		}
	}

	private void			tryDeleteHero(Commands.Delete command)
	{
		try
		{
			if (command.getValueAsInteger() != null)
				HeroStorage.getInstance().delete(command.getValueAsInteger());
			else if (command.getValueAsString() != null)
				HeroStorage.getInstance().delete(HeroStorage.getInstance().find(command.getValueAsString()));
			else
				assert false;

			showHeroSelectionScreen();
		}
		catch (HeroStorage.HeroNotFoundException exception)
		{
			linkChild(new ErrorDelegate("Hero not found"));
		}
	}
}
