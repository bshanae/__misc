package view.closed.mode.modeController;

import application.common.SingletonMap;

public class							ConsoleModeController extends ModeController
{
	private String						text;

	public static ConsoleModeController	getInstance()
	{
		return SingletonMap.getInstanceOf(ConsoleModeController.class);
	}

// -----------------------------------> Overrides

	@Override
	public void							show()
	{
		writeToConsole(text);
	}

	@Override
	public void							clean()
	{
		cleanConsole();
	}

	@Override
	protected void						enable() {}

	@Override
	protected void						disable()
	{
		cleanConsole();
	}

// -----------------------------------> Own methods

	public void							setContent(String text)
	{
		this.text = text;
	}

	private void						writeToConsole(String string)
	{
		System.out.println(string);
		System.out.flush();
	}

	private void						cleanConsole()
	{
		System.out.print("\033\143");
		System.out.flush();
	}
}
