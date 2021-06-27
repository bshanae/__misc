package org.bshanae.fixMe.tools.ui;

import org.bshanae.fixMe.tools.system.logging.Logger;

import java.util.*;

public class								UserActionInterpreter
{
	public static final class				CanInterpretUserActionException extends RuntimeException
	{
		public 								CanInterpretUserActionException(String reason)
		{
			super(reason);
		}
	}

	private static final class				FunctionCall
	{
		private final Function				function;
		private final Function.Argument[]	arguments;

		public								FunctionCall(Function function, Function.Argument[] arguments)
		{
			this.function = function;
			this.arguments = arguments;
		}

		public void							invoke()
		{
			function.invoke(arguments);
		}
	}

	private final Logger					logger;
	private final List<Function>			functions;

	public									UserActionInterpreter()
	{
		logger = new Logger(this.getClass());
		functions = new LinkedList<>();
	}

	public void								registerFunction(Function function)
	{
		functions.add(function);
	}

	public void								interpret(String line)
	{
		FunctionCall						functionCall;

		functionCall = parseAsFunctionCall(line);

		try
		{
			functionCall.invoke();
		}
		catch (Exception exception)
		{
			logger.logException("Function invocation exception", exception);
		}
	}

	private FunctionCall					parseAsFunctionCall(String line)
	{
		String[]							tokens;
		List<Function.Argument>				arguments;
		Function							function = null;

		tokens = line.split(" ");
		for (Function testFunction : functions)
		{
			if (testFunctionPrefix(testFunction, tokens))
			{
				function = testFunction;
				break;
			}
		}

		if (function == null)
			throw new CanInterpretUserActionException("Can't find function for call '" + line + "'");

		arguments = new LinkedList<>();
		for (int i = function.getPrefix().length; i < tokens.length; i++)
			arguments.add(new Function.Argument(tokens[i]));

		return new FunctionCall(function, arguments.toArray(new Function.Argument[0]));
	}

	private static boolean					testFunctionPrefix(Function function, String[] tokens)
	{
		if (function.getPrefix().length > tokens.length)
			return false;

		for (int i = 0; i < function.getPrefix().length; i++)
		{
			if (!function.getPrefix()[i].equals(tokens[i]))
				return false;
		}

		return true;
	}
}
