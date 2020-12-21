package view.closed.mode.modeController;

import application.utils.SingletonMap;
import view.open.Signals;
import view.open.View;

import java.util.Scanner;

public class							ConsoleModeController extends ModeController
{
	private String						output;

	public static ConsoleModeController	getInstance()
	{
		return SingletonMap.getInstanceOf(ConsoleModeController.class);
	}

// -----------------------------------> Overrides

	@Override
	public void							updateUi()
	{
		//cleanConsole();
		writeToConsole(output);
	}

	@Override
	public void							requestInput()
	{
		String							input;

		input = new Scanner(System.in).nextLine();
		View.getInstance().sendSignal(new Signals.Console(input));
	}

	@Override
	protected void						enableUi() {}

	@Override
	protected void						disableUi()
	{
		cleanConsole();
	}

// -----------------------------------> Own methods

	public void							setContent(String content)
	{
		output = content;
	}

	private void						writeToConsole(String string)
	{
		System.out.print(string);
		System.out.flush();
	}

	private void						cleanConsole()
	{
		System.out.print("\033\143");
		System.out.flush();
	}
}
