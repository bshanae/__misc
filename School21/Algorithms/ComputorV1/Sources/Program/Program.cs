using System;

public static class		Program
{
	public static void	Main(string[] arguments)
	{
		var tokens = Equation.Parser.Parse(" 1+2.1 + 3*x=-7.8x");
	}
}