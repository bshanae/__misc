using System;

public static class		Error
{
	public static void	Raise(string message = "Critical error")
	{
		if (Options.Test)
			NUnit.Framework.Assert.Fail(message);
		else		
			throw new Exception("ComputerV1 : " + message);
	}

	public static void	Assert(bool state, string message = "Assertion failed")
	{
		if (!state)
			Raise(message);
	}
}
