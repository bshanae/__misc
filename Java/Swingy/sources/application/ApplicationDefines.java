package application;

import java.util.HashMap;
import java.util.Map;

public abstract class						ApplicationDefines
{
	public enum								Define
	{
		LAUNCH_CONSOLE("console"),
		LAUNCH_GUI("gui"),
		DEBUG("debug");

		public final String					stringRepresentation;

		private								Define(String stringRepresentation)
		{
			this.stringRepresentation = stringRepresentation;
		}
	}

	private static final Map<Define, Boolean>	defineMap;

	static
	{
		defineMap = new HashMap<>();

		for (Define define : Define.values())
			defineMap.put(define, false);
	}

	public static void 							parse(String[] arguments)
	{
		for (String argument : arguments)
			parse(argument);
	}

	public static boolean						get(Define define)
	{
		return defineMap.get(define);
	}

	private static void						parse(String argument)
	{
		for (Map.Entry<Define, Boolean> entry : defineMap.entrySet())
			if (entry.getKey().stringRepresentation.equalsIgnoreCase(argument))
				entry.setValue(true);
	}
}
