package org.bshanae.fixMe.router.main;

import org.bshanae.fixMe.tools.system.Console;
import org.bshanae.fixMe.tools.ui.Function;

class													UserActionInterpreter
{
	private final
	org.bshanae.fixMe.tools.ui.UserActionInterpreter	base;

	private final Router								router;

														UserActionInterpreter(Router router)
	{
		this.router = router;

		this.base = new org.bshanae.fixMe.tools.ui.UserActionInterpreter();
		this.base.registerFunction(new Function(this::invokeHelp, "help"));
		this.base.registerFunction(new Function(this::invokeExit, "exit"));
	}

	public void											interpret(String line)
	{
		if (!line.isEmpty())
			base.interpret(line);
	}

	private void										invokeHelp(Function.Argument[] arguments)
	{
		Console.writeWithoutPrefix
		(
			"$ help - show this text\n" +
			"$ exit - close router"
		);
	}

	private void										invokeExit(Function.Argument[] arguments)
	{
		router.terminate();
	}
}
