using System;
using NUnit.Framework;

public static class		Printer
{
	public static void	Print(object @object = null)
	{
		string			message = @object?.ToString();
		
		Console.Write(message);
	}
	
	public static void	PrintLine(object @object = null)
	{
		string			message = @object?.ToString();
		
		Console.WriteLine(message);
	}
}