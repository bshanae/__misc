package view.closed.screens.console;

import view.closed.mode.modeController.ConsoleModeController;
import view.closed.screens.Screen;

import java.util.Scanner;

public abstract class		ConsoleScreen implements Screen
{
	private String			input;

	public String			getInput()
	{
		return input;
	}

	protected static void	setContent(String text)
	{
		ConsoleModeController.getInstance().setContent(text);
	}

	public void				waitForInput()
	{
		input = new Scanner(System.in).nextLine();
	}
}
