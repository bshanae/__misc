package org.bshanae.fixMe.market;

import org.bshanae.fixMe.tools.system.Console;
import org.bshanae.fixMe.tools.ui.Function;

class													UserActionInterpreter
{
	private final
	org.bshanae.fixMe.tools.ui.UserActionInterpreter	base;

	private final Market								market;

														UserActionInterpreter(Market market)
	{
		this.market = market;

		this.base = new org.bshanae.fixMe.tools.ui.UserActionInterpreter();
		this.base.registerFunction(new Function(this::invokeHelp, "help"));
		this.base.registerFunction(new Function(this::invokeExit, "exit"));
		this.base.registerFunction(new Function(this::invokeGet, "instruments", "get"));
		this.base.registerFunction(new Function(this::invokeSet, "instruments", "set"));
		this.base.registerFunction(new Function(this::invokeAll, "instruments", "all"));
		this.base.registerFunction(new Function(this::invokeTransactionsClear, "transactions", "clear"));
		this.base.registerFunction(new Function(this::invokeTransactionsAll, "transactions", "all"));
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
			"$ help                                      - show this text\n" +
			"$ exit                                      - close market\n" +
			"$ instruments get [name]                    - show info about concrete instrument\n" +
			"$ instruments set [name] [quantity] [price] - add instrument or modify its properties\n" +
			"$ instruments all                           - show all instruments\n" +
			"$ transactions clear                        - clear transactions\n" +
			"$ transactions all                          - show all transactions"
		);
	}

	private void										invokeExit(Function.Argument[] arguments)
	{
		market.terminate();
	}

	private void										invokeGet(Function.Argument[] arguments)
	{
		final String									name = arguments[0].asString();
		final String									result = market.getInstrument(name);

		Console.write(result);
	}

	private void										invokeSet(Function.Argument[] arguments)
	{
		final String									name = arguments[0].asString();
		final int										quantity = arguments[1].asInt();
		final int										price = arguments[2].asInt();

		market.setInstrument(name, quantity, price);
	}

	private void										invokeAll(Function.Argument[] arguments)
	{
		market.all();
	}

	private void										invokeTransactionsClear(Function.Argument[] arguments)
	{
		market.transactionsClear();
	}

	private void										invokeTransactionsAll(Function.Argument[] arguments)
	{
		market.transactionsAll();
	}
}
