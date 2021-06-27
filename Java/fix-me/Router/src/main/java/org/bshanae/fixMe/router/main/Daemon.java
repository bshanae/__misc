package org.bshanae.fixMe.router.main;

import org.bshanae.fixMe.tools.system.Console;

public class							Daemon
{
	public static void					main(String[] args)
	{
		new Daemon().launch();
	}

	private final Router				router;
	private final UserActionInterpreter	userActionInterpreter;

	private								Daemon()
	{
		router = new Router();
		userActionInterpreter = new UserActionInterpreter(router);
	}

	private void						launch()
	{
		String							input;

		router.launchInBackground();

		while (router.isRunning())
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

		router.terminate();
	}
}
