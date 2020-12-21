package application;

import java.util.HashMap;
import java.util.Map;

public abstract class							ApplicationOptions
{
	public enum									Options
	{
		LAUNCH_CONSOLE("console"),
		LAUNCH_GUI("gui"),
		DEBUG("debug");

		public final String						stringRepresentation;

		private Options(String stringRepresentation)
		{
			this.stringRepresentation = stringRepresentation;
		}
	}

	private static final Map<Options, Boolean>	map;

	static
	{
		map = new HashMap<>();

		for (Options option : Options.values())
			map.put(option, false);
	}

	public static void 							parse(String[] arguments)
	{
		for (String argument : arguments)
			parse(argument);
	}

	public static boolean						get(Options option)
	{
		return map.get(option);
	}

	private static void							parse(String argument)
	{
		for (Map.Entry<Options, Boolean> entry : map.entrySet())
			if (entry.getKey().stringRepresentation.equalsIgnoreCase(argument))
				entry.setValue(true);
	}
}
