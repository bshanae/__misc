package view.closed.builders;

import model.open.Requests;
import view.closed.mode.ModeDependantUnion;
import view.closed.screens.Screen;
import view.closed.screens.console.implementations.*;
import view.closed.screens.gui.implementations.GuiClassSelectorScreen;
import view.closed.screens.gui.implementations.GuiHeroSelectorScreen;
import view.closed.screens.gui.implementations.GuiMapScreen;
import view.closed.screens.gui.implementations.GuiNameEntryScreen;

import java.util.HashMap;

public abstract class			ScreenBuilder
{
	private static class		ModeDependantClass extends ModeDependantUnion<Class<? extends Screen>>
	{
		public					ModeDependantClass(Class<? extends Screen> consoleObject, Class<? extends Screen> guiObject)
		{
			super(consoleObject, guiObject);
		}
	}

	private static class		MapRequestToScreen extends HashMap<Class<? extends Requests.Abstract>, ModeDependantClass> {}

	private static final
	MapRequestToScreen			requestToScreen = new MapRequestToScreen()
	{{
		// Common
		put(Requests.Error.class, new ModeDependantClass(ConsoleErrorScreen.class, null));

		// Hero selection
		put(Requests.HeroSelector.class, new ModeDependantClass(ConsoleHeroSelectorScreen.class, GuiHeroSelectorScreen.class));

		put(Requests.HeroNameEntry.class, new ModeDependantClass(ConsoleNameEntryScreen.class, GuiNameEntryScreen.class));
		put(Requests.ClassSelector.class, new ModeDependantClass(ConsoleClassSelectorScreen.class, GuiClassSelectorScreen.class));

		// Game
		put(Requests.Map.class, new ModeDependantClass(ConsoleMapScreen.class, GuiMapScreen.class));
	}};

	public static Screen		getScreen(Requests.Ui request)
	{
		final Class<?>			requestClass = request.getClass();

		try
		{
			assert requestToScreen.containsKey(requestClass);
			return requestToScreen.get(requestClass).get().newInstance();
		}
		catch (Exception exception)
		{
			System.out.println(exception.toString());

			assert false;
			return null;
		}
	}
}
