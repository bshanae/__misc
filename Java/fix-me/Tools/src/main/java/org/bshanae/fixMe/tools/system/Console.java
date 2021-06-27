package org.bshanae.fixMe.tools.system;

public class						Console
{
	public static String			read()
	{
		return System.console().readLine();
	}

	public static void				write(String format, Object... values)
	{
		System.out.println("$ " + String.format(format, values));
	}

	public static void				write(Object object)
	{
		System.out.println("$ " + object.toString());
	}

	public static void				writeWithoutPrefix(Object object)
	{
		System.out.println(object.toString());
	}
}