package controller.closed;

import controller.open.Commands;
import view.open.Signals;

public class					GuiSignalTranslator extends SignalTranslator
{
	@Override
	protected Commands.Abstract	translateImplementation(Signals.Abstract signal)
	{
		Signals.Gui				guiSignal;

		guiSignal = (Signals.Gui)signal;
		switch (guiSignal.buttonId)
		{
			case HERO_SELECTOR_CREATE_0:
			case HERO_SELECTOR_CREATE_1:
			case HERO_SELECTOR_CREATE_2:
			case HERO_SELECTOR_CREATE_3:
				return new Commands.Create();

			case HERO_SELECTOR_SELECT_0:
				return new Commands.Select(0);
			case HERO_SELECTOR_SELECT_1:
				return new Commands.Select(1);
			case HERO_SELECTOR_SELECT_2:
				return new Commands.Select(2);
			case HERO_SELECTOR_SELECT_3:
				return new Commands.Select(3);

			case HERO_SELECTOR_DELETE_0:
				return new Commands.Delete(0);
			case HERO_SELECTOR_DELETE_1:
				return new Commands.Delete(1);
			case HERO_SELECTOR_DELETE_2:
				return new Commands.Delete(2);
			case HERO_SELECTOR_DELETE_3:
				return new Commands.Delete(3);

			case NAME_ENTRY_ENTER:
				String			name;

				name = (String)guiSignal.linkedData;
				return new Commands.Enter(name);

			default:
				// TODO Error
				return null;
		}
	}
}
