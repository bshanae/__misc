using System;
using NUnit.Framework;

public static class		Printer
{
	public static void	Print(object @object = null)
	{
		string			message = @object?.ToString();
		
		if (Program.Options.Test)
			TestContext.Write(message);
		else
			Console.Write(message);
	}
	
	public static void	PrintLine(object @object = null)
	{
		string			message = @object?.ToString();
		
		if (Program.Options.Test)
			TestContext.WriteLine(message);
		else
			Console.WriteLine(message);
	}
	
	public static void	PrintIfVerbose(object @object = null)
	{
		if (Program.Options.Verbose)
			Print(@object);
	}
	
	public static void	PrintLineIfVerbose(object @object = null)
	{
		if (Program.Options.Verbose)
			PrintLine(@object);
	}
}