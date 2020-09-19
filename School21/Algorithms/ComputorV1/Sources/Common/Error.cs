using System;

public static class		Error
{
	public static void	Raise(string message = "Critical error")
	{
		Printer.Print("ComputerV1 : " + message);
		Environment.Exit(1);
	}

	public static void	Assert(bool state, string message = "Assertion failed")
	{
		if (!state)
			Raise(message);
	}
}