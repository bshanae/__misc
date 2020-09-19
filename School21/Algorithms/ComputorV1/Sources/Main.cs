﻿using System;
using System.Collections.Generic;

public static class		ComputorV1
{
	private static void	Solve(string rawExpression)
	{
		List<Token>		tokens;
		
		Printer.PrintLineIfVerbose(">>> Parsing string <<<\n");
		
		rawExpression = rawExpression.RemoveSpaces();
		Printer.PrintLineIfVerbose("Removed whitespaces : " + rawExpression + "\n");
		tokens = rawExpression.Tokenize();
		
		foreach (var token in tokens)
			Printer.PrintLineIfVerbose(token);
		Printer.PrintLineIfVerbose();
		
		Printer.PrintLineIfVerbose(">>> Parsing expression <<<\n");
		Expression.Build(tokens);
		
		Printer.PrintLineIfVerbose(">>> Solving equation <<<\n");
		Equation.Build();
	}

	public static void	Main(string[] args)
	{
		Options.Parse(args);
		
		// Solve("1 * x ^ 1 * x + 2 * x * 2 + 3 - 5 = 0");
		// Solve("1 * x * 2 + 2 - 3 = x ^ 2 + 2 * x - x * 3");
		
		// Errors
		// Solve("=");
		// Solve("1 =");
		// Solve("1 = = 1");
		// Solve("1 = 1 = 1");
		
		// Incomplete quadratic form
		// Solve("x ^ 2 = 4");
		// Solve("x = 4");
		Solve("x * x = 5");
		// Solve("2 * x = 4");
		
		// Special cases
		// Solve("4 = 4");
		// Solve("0 = 4");
		// Solve("x = 4");
		
		// Random
		// Solve("2 * 3 ^ -1 * x = 8");
		// Solve("2 * 3 ^ -1 * x = 8");
		
		// Correct
		// Solve("x - x = 0");
	}
}

/*
	Bonuses :
		1. Free form expressions
*/