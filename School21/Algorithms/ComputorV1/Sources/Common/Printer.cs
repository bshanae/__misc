using System;

public static class		Printer
{
	public static void	Print(object @object = null)
	{
		Console.Write(@object ?? "");
	}
	
	public static void	PrintIfVerbose(object @object = null)
	{
		if (Options.Verbose)
			Print(@object);
	}
	
	public static void	PrintLine(object @object = null)
	{
		Console.WriteLine(@object ?? "");
	}
	
	public static void	PrintLineIfVerbose(object @object = null)
	{
		if (Options.Verbose)
			PrintLine(@object);
	}
}