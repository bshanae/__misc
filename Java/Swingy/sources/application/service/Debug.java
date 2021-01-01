package application.service;

import application.ApplicationOptions;

public abstract class		Debug
{
	public static void		throwException(String message)
	{
		if (ApplicationOptions.get(ApplicationOptions.Options.DEBUG))
			throw new RuntimeException(message);
	}

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
