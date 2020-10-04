using System;
using NUnit.Framework;

public static class		Printer
{
	public static void	Print(object @object = null)
	{
		string			message = @object?.ToString();
		
		if (Program.Options.Report == Program.Options.ReportFormat.Test)
			TestContext.Write(message);
		
		Console.Write(message);
	}
	
	public static void	PrintLine(object @object = null)
	{
		string			message = @object?.ToString();
		
		if (Program.Options.Report == Program.Options.ReportFormat.Test)
			TestContext.WriteLine(message);
		else
			Console.WriteLine(message);
	}
}