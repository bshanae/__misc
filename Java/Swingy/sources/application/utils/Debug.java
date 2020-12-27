package application.utils;

import application.ApplicationOptions;

public abstract class		Debug
{
	public static void		log(String message)
	{
		if (ApplicationOptions.get(ApplicationOptions.Options.DEBUG))
			System.out.println(message);
	}

	public static void		logFormat(String format, Object... arguments)
	{
		log(String.format(format, arguments));
	}
}
