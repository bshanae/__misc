package controller.closed;

import application.common.SingletonMap;
import controller.open.Commands;
import view.open.Signals;

public abstract class						SignalTranslator
{
	public static Commands.Abstract			translate(Signals.Abstract signal)
	{
		SignalTranslator					instance;

		if (signal instanceof Signals.Console)
		{
			instance = SingletonMap.getInstanceOf(ConsoleSignalTranslator.class);
			return instance.translateImplementation(signal);
		}
		else if (signal instanceof Signals.Gui.Abstract)
		{
			instance = SingletonMap.getInstanceOf(GuiSignalTranslator.class);
			return instance.translateImplementation(signal);
		}

		// TODO error
		return null;
	}

	protected abstract Commands.Abstract	translateImplementation(Signals.Abstract signal);
}
