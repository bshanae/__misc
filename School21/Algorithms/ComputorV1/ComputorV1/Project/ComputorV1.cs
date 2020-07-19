using System;
using System.Collections.Generic;

public class			ComputorV1
{
	private static void	Work(string expression)
	{
		List<Token>		tokens;
		GroupTree		tree;
		Equation		equation;
		
		expression = expression.RemoveSpaces();
		Console.WriteLine("Removed whitespaces : " + expression + "\n");

		tokens = expression.Tokenize();
		foreach (var token in tokens)
			Console.WriteLine(token);
		
		tree = new GroupTree(tokens);
		// Console.WriteLine("\n" + tree);
		//
		// equation = new Equation(tree);
		// Console.WriteLine("\n" + equation);
		
		// Console.WriteLine("\n");
	}

	public static void	Main(string[] args)
	{
		// Work("1 = 2");
		Work("1 * x^ 2 + x * 2 * 2 + 3 - 5 = 0");
	}
}
