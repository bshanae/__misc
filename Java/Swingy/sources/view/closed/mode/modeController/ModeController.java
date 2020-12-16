package view.closed.mode.modeController;

import view.closed.mode.Mode;

public abstract class				ModeController
{
	private static ModeController	currentController;

	public static ModeController	getCurrentController()
	{
		return currentController;
	}

	public static void				switchMode(Mode mode)
	{
		ModeController				newModeController;

		newModeController = getControllerForMode(mode);

		if (currentController == newModeController)
			return ;

		if (currentController != null)
			currentController.disable();

		newModeController.enable();
		currentController = newModeController;
	}

	public abstract void			show();
	public abstract void			clean();

	protected abstract void			enable();
	protected abstract void			disable();

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
