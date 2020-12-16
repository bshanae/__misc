package controller.closed;

import controller.open.Commands;
import view.open.Signals;

public abstract class					SignalTranslator
{
	public static Commands.Abstract		translate(Signals.Abstract signal)
	{
		if (signal instanceof Signals.Console)
			return ConsoleSignalTranslator.translate((Signals.Console)signal);
		else
		{
			// TODO Error
			System.err.println("ERROR");
			return null;
		}
	}
}
