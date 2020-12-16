package view.closed.builders;

import model.open.Requests;
import view.closed.screens.Screen;
import view.closed.screens.console.ConsoleScreen;
import view.open.Context;
import view.open.Signals;

public abstract class				SignalBuilder
{
	public static class				UnknownRequestException extends Exception { }

	public static Signals.Abstract	buildSignalUpon(Requests.Ui request, Screen screen)
									throws UnknownRequestException
	{
		if (screen instanceof ConsoleScreen)
			return new Signals.Console(((ConsoleScreen)screen).getInput(), Context.getContext(request));

		return null;
	}
}
