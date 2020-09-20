using System.Collections.Generic;
using System.Linq;

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

	public static void	Main(string[] arguments)
	{
		var				argumentList = arguments.ToList();
		
		Options.Parse(argumentList);
		
		Error.Assert(argumentList.Count > 0, "Invalid number of arguments");
		Solve(argumentList[0]);
	}
}

/*
	Bonuses :
		1. Free form expressions
*/