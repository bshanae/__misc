package view.closed.mode;

import view.closed.mode.modeController.ModeController;

public class		ModeDependantUnion<T>
{
	private final T	consoleObject;
	private final T	guiObject;

	public			ModeDependantUnion(T consoleObject, T guiObject)
	{
		this.consoleObject = consoleObject;
		this.guiObject = guiObject;
	}

	public T		get()
	{
		switch (ModeController.getCurrentMode())
		{
			case CONSOLE:
				return consoleObject;

			case GUI:
				return guiObject;
		}

		return null;
	}
}
