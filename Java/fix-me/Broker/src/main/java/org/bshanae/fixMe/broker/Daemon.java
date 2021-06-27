package org.bshanae.fixMe.broker;

import org.bshanae.fixMe.tools.system.Console;

public class								Daemon
{
	public static void						main(String[] args)
	{
		new Daemon().launch();
	}

	private final Broker					broker;
	private final UserActionInterpreter		userActionInterpreter;

	private									Daemon()
	{
		broker = new Broker();
		userActionInterpreter = new UserActionInterpreter(broker);
	}

	private void							launch()
	{
		String								input;

		broker.launchInBackground();

		while (broker.isRunning())
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

		broker.terminate();
	}
}