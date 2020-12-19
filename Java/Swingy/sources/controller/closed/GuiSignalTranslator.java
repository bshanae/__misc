package controller.closed;

import controller.open.Commands;
import view.open.Signals;

public class					GuiSignalTranslator extends SignalTranslator
{
	@Override
	protected Commands.Abstract	translateImplementation(Signals.Abstract signal)
	{
		if (signal instanceof Signals.Gui.CreateHero)
			return new Commands.CreateHero();
		else if (signal instanceof Signals.Gui.SelectHero)
			return new Commands.SelectHero(((Signals.Gui.SelectHero)signal).hero.name);
		else if (signal instanceof Signals.Gui.DeleteHero)
			return new Commands.DeleteHero(((Signals.Gui.DeleteHero)signal).hero.name);

		// TODO Error
		return null;
	}
}
