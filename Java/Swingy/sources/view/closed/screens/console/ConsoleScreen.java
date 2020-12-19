package view.closed.screens.console;

import model.open.Requests;
import view.closed.mode.modeController.ConsoleModeController;
import view.closed.screens.Screen;
import view.open.Context;

import java.util.Scanner;

public abstract class			ConsoleScreen implements Screen
{
	public final void			buildUi(Requests.Ui request)
	{
		ConsoleModeController.getInstance().setContent(getContent(request));
	}

	protected abstract String	getContent(Requests.Ui request);
}
