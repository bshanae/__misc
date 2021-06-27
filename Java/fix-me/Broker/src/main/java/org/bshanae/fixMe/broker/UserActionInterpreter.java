package org.bshanae.fixMe.broker;

import org.bshanae.fixMe.tools.system.Console;
import org.bshanae.fixMe.tools.ui.Function;

class													UserActionInterpreter
{
	private final
	org.bshanae.fixMe.tools.ui.UserActionInterpreter	base;

	private final Broker								broker;

														UserActionInterpreter(Broker broker)
	{
		this.broker = broker;

		this.base = new org.bshanae.fixMe.tools.ui.UserActionInterpreter();
		this.base.registerFunction(new Function(this::invokeHelp, "help"));
		this.base.registerFunction(new Function(this::invokeExit, "exit"));
		this.base.registerFunction(new Function(this::invokeInfo, "instruments", "info"));
		this.base.registerFunction(new Function(this::invokeBuy, "instruments", "buy"));
		this.base.registerFunction(new Function(this::invokeSell, "instruments", "sell"));
		this.base.registerFunction(new Function(this::invokeAll, "instruments", "all"));
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
			"$ help                                                        - show this text\n" +
			"$ exit                                                        - close broker\n" +
			"$ instruments info [m. id] [i. name]                          - show info about concrete instrument\n" +
			"$ instruments buy [m. id] [i. name] [i. quantity] [i. price]  - buy the instrument\n" +
			"$ instruments sell [m. id] [i. name] [i. quantity] [i. price] - show all owned instruments\n" +
			"$ * m. - market, i. - instrument"
		);
	}

	private void										invokeExit(Function.Argument[] arguments)
	{
		broker.terminate();
	}

	private void										invokeInfo(Function.Argument[] arguments)
	{
		broker.info(arguments[0].asInt(), arguments[1].asString());
	}

	private void										invokeBuy(Function.Argument[] arguments)
	{
		broker.buy
		(
			arguments[0].asInt(),
			arguments[1].asString(),
			arguments[2].asInt(),
			arguments[3].asInt()
		);
	}

	private void										invokeSell(Function.Argument[] arguments)
	{
		broker.sell
		(
			arguments[0].asInt(),
			arguments[1].asString(),
			arguments[2].asInt(),
			arguments[3].asInt()
		);
	}

	private void										invokeAll(Function.Argument[] arguments)
	{
		broker.all();
	}
}
