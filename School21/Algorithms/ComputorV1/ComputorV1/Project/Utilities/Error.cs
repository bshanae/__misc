using System;

public static class		Error
{
	public static void	Raise(string message)
	{
		Console.WriteLine("ComputerV1 : " + message);
		Environment.Exit(1);
	}
}
