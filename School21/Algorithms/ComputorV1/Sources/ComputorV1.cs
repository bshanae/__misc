﻿using System;
using System.Collections.Generic;

public class			ComputorV1
{
	private static void	Work(string expression)
	{
		List<Token>		tokens;
		Expression		tree;
		Equation		equation;
		
		expression = expression.RemoveSpaces();
		Console.WriteLine("Removed whitespaces : " + expression + "\n");

		tokens = expression.Tokenize();
		foreach (var token in tokens)
			Console.WriteLine(token);
		Console.WriteLine();
		
		tree = new Expression(tokens);
		Console.WriteLine(tree);
		
		// equation = new Equation(tree);
		// Console.WriteLine("\n" + equation);
	}

	public static void	Main(string[] args)
	{
		// Work("1 * x ^ 1 * x + 2 * x * 2 + 3 - 5 = 0");
		Work("x + 1 = 0");
	}
}

/*
	Bonuses :
	1. Complex expressions (1 * 2 * 3..., x * x * 2...)
	2. Ignoring operator * (2x)
*/