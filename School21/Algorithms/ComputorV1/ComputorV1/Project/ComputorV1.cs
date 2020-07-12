using System;

public class			ComputorV1
{
	private static void	Work(string expression)
	{
		expression = expression.RemoveSpaces();
		Console.WriteLine("Removed whitespaces : " + expression + "\n");

		Token[]			tokens = expression.Tokenize();
		foreach (var token in tokens)
			Console.WriteLine(token);
		
		GroupTree		tree = new GroupTree(tokens);
		Console.WriteLine("\n" + tree);
	}

	public static void	Main(string[] args)
	{
		Work("1 * x^ 8 + x * 2 + 3 - 5 = 0");
	}
}
