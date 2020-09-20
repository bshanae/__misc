using System;

public static class		Error
{
	public static void	Raise(string message = "Critical error")
	{
		throw new Exception("ComputerV1 : " + message);
	}

	public static void	Assert(bool state, string message = "Assertion failed")
	{
		if (!state)
			Raise(message);
	}
}
