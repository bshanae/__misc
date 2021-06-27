package org.bshanae.fixMe.market;

import org.bshanae.fixMe.tools.system.Console;

public class								Daemon
{
	public static void						main(String[] args)
	{
		new Daemon().launch();
	}

	private final Market					market;
	private final UserActionInterpreter		userActionInterpreter;

	private									Daemon()
	{
		market = new Market();
		userActionInterpreter = new UserActionInterpreter(market);
	}

	private void							launch()
	{
		String								input;

		market.launchInBackground();
		while (market.isRunning())
		{
			try
			{
				input = Console.read();
				userActionInterpreter.interpret(input);
			}
			catch (Exception exception)
			{
				Console.write("Can't perform action");
			}
		}

		market.terminate();
	}
}
