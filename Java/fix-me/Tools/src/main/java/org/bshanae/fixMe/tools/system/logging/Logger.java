package org.bshanae.fixMe.tools.system.logging;

import org.bshanae.fixMe.tools.system.Console;

public class				Logger
{
	final private String	prefix;

	public 					Logger(Class<?> class_)
	{
		prefix = "[" + class_.getName() + "]";
	}

	public void				logInfo(String format, Object... inserts)
	{
		if (LoggingSettings.LOG_INGO)
			System.out.println(prefix + " " + formatMessage(format, inserts));
	}

	public void				logError(String format, Object... inserts)
	{
		if (LoggingSettings.LOG_ERROR)
			System.err.println(prefix + " " + formatMessage(format, inserts));
	}

	public void				logException(String message, Exception exception)
	{
		if (!LoggingSettings.LOG_EXCEPTION)
			return;

		System.err.println(prefix + " " + message);
		System.err.println();

		System.err.println("Exception message : ");
		System.err.println(exception.getMessage());
		System.err.println();

		System.err.println("Exception stack trace : ");
		exception.printStackTrace();
		System.err.println();
	}

	private static String	formatMessage(String format, Object... inserts)
	{
		final StringBuilder	stringBuilder = new StringBuilder(format);

		int					insertIndex;
		String				insertString;

		for (Object insert : inserts)
		{
			insertString = insert instanceof String ? (String)insert : insert.toString();

			if ((insertIndex = stringBuilder.indexOf("{}")) != -1)
				stringBuilder.replace(insertIndex, insertIndex + 2, insertString);
			else
				throw new RuntimeException("Can't format string '" + format + "'");
		}

		return stringBuilder.toString();
	}
}
