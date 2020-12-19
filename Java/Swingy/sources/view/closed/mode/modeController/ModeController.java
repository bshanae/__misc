package view.closed.mode.modeController;

import view.closed.mode.Mode;

public abstract class				ModeController
{
	private static Mode				currentMode;
	private static ModeController	currentController;

	public static Mode				getCurrentMode()
	{
		return currentMode;
	}

	public static ModeController	getCurrentController()
	{
		return currentController;
	}

	public static void				switchMode(Mode mode)
	{
		ModeController				newModeController;

		if (mode == currentMode)
			return ;

		currentMode = mode;

		if (currentController != null)
			currentController.disableUi();

		newModeController = getControllerForMode(mode);

		newModeController.enableUi();
		currentController = newModeController;
	}

	public abstract void			updateUi();
	public abstract void			requestInput();

	protected abstract void			enableUi();
	protected abstract void			disableUi();

	private static ModeController	getControllerForMode(Mode mode)
	{
		switch (mode)
		{
			case CONSOLE:
				return ConsoleModeController.getInstance();

			case GUI:
				return GuiModeController.getInstance();
		}

		// TODO
		return null;
	}
}
