package view.closed.mode.modeController;

import application.common.SingletonMap;
import view.open.Context;
import view.open.Signals;
import view.open.View;

import java.util.Scanner;

public class							ConsoleModeController extends ModeController
{
	private String						output;
	private Context						context;

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
		View.getInstance().sendSignal(new Signals.Console(input, context));
	}

	@Override
	protected void						enableUi() { }

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

	public void 						setContext(Context context)
	{
		this.context = context;
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
