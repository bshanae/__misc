using System;

public class			ComputorV1
{
	private static void	Work(string expression)
	{
		Token[]			tokens;
		GroupTree		tree;
		Equation		equation;
		
		expression = expression.RemoveSpaces();
		Console.WriteLine("Removed whitespaces : " + expression + "\n");

		tokens = expression.Tokenize();
		foreach (var token in tokens)
			Console.WriteLine(token);
		
		tree = new GroupTree(tokens);
		Console.WriteLine("\n" + tree);
		
		equation = new Equation(tree);
		Console.WriteLine("\n" + equation);
	}

	public static void	Main(string[] args)
	{
		Work("1 * x^ 2 + x * 2 + 3 - 5 = 0");
	}
}
