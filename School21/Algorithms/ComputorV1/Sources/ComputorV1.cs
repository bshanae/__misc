﻿using System;
using System.Collections.Generic;

public class			ComputorV1
{
	private static void	Solve(string expression)
	{
		List<Token>		tokens;
		Expression		tree;
		Equation		equation;
		
		Console.WriteLine(">>> Parsing string <<<\n");
		
		expression = expression.RemoveSpaces();
		Console.WriteLine("Removed whitespaces : " + expression + "\n");
		tokens = expression.Tokenize();
		
		foreach (var token in tokens)
			Console.WriteLine(token);
		Console.WriteLine();
		
		Console.WriteLine(">>> Parsing expression <<<\n");
		tree = new Expression(tokens);
		
		Console.WriteLine(">>> Solving equation <<<\n");
		
		equation = new Equation(tree);
	}

	public static void	Main(string[] args)
	{
		// Solve("1 * x ^ 1 * x + 2 * x * 2 + 3 - 5 = 0");
		// Solve("1 * x * 2 + 2 - 3 = x ^ 2 + 2 * x - x * 3");
		Solve("x - x = 0");
		
		// Errors
		// Solve("=");
		// Solve("1 =");
		// Solve("1 = = 1");
		// Solve("1 = 1 = 1");
	}
}

/*
	Bonuses :
		1. Free form expressions
*/