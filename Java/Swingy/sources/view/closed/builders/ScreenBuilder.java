package view.closed.builders;

import model.open.Requests;
import view.closed.screens.Screen;
import view.closed.screens.console.implementations.*;
import view.closed.screens.gui.implementations.GuiClassSelectorScreen;
import view.closed.screens.gui.implementations.GuiMapScreen;
import view.closed.screens.gui.implementations.GuiNameEntryScreen;

import java.util.HashMap;

public abstract class			ScreenBuilder
{
	private static class		MapRequestToScreen extends HashMap<Class<? extends Requests.Abstract>, Class<? extends Screen>> {}

	private static final
	MapRequestToScreen			requestToScreen = new MapRequestToScreen()
	{{
		// Common
		put(Requests.Error.class, ConsoleErrorScreen.class);

		// Hero selection
//		put(Requests.HeroSelector.class, HeroSelectorScreen.class);
		put(Requests.HeroSelector.class, GuiMapScreen.class);

		put(Requests.HeroNameEntry.class, ConsoleNameEntryScreen.class);
		put(Requests.ClassSelector.class, ConsoleClassSelectorScreen.class);

		// Game
		put(Requests.Map.class, ConsoleMapScreen.class);
	}};

	public static Screen		buildScreenUpon(Requests.Ui request)
	{
		final Class<?>			requestClass = request.getClass();

		try
		{
			assert requestToScreen.containsKey(requestClass);
			return requestToScreen.get(requestClass).newInstance();
		}
		catch (Exception exception)
		{
			System.out.println(exception.toString());

			assert false;
			return null;
		}
	}
}
