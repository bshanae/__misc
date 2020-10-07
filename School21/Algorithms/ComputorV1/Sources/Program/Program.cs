using System;
using System.Collections.Generic;
using System.Linq;
using Computor;

public static partial class		Program
{
	private static List<string> arguments;
	
	public static void			Main(string[] arguments)
	{
		// Tests :
		//   abdisd
		//   y = 0
		// 	 xx = 0
		// 	 xxxxx = 0
		// 	 x3 = 0
		// 	 x++ = 0
		// 	 1-+2 = 0
		// 	 1---2 = 0
		// 	 +2 = 0
		// 	 *1 = 0
		// 	 ^8 = 0
		// 	 =
		// 	 0 =
		//   x + x ^ 2 + x * x ^ 2 = 0
		//   x ^ 2 * x  = 0
		//   x ^ 2 / 2 / 2 = 0
		//   2x^2 + 4x - 2 = 0
		//   x * x = 0

		try
		{
			WorkWithArguments(arguments);
			WorkWithExpression();

			ExecuteParser();
			ExecuteAnalyzer();
			ExecuteSolver();
		}
		catch (Exception exception)
		{
			Console.WriteLine("Computor error : " + exception.Message);
		}
	}

	private static void			WorkWithArguments(string[] arguments)
	{
		Program.arguments = arguments.ToList();
		
		Options.Parse();
		Validator.ValidateArguments(Program.arguments);
	}

	private static void			WorkWithExpression()
	{
		Workspace.Expression = arguments[0];
		Validator.ValidateExpression();
	}

	private static void			ExecuteParser()
	{
		Parser.Parse();
		Reporter.Report(Reporter.Event.ParsedExpression);
		
		Parser.ProcessUnaryMinus();
		Reporter.Report(Reporter.Event.ProcessedUnaryMinus);
		
		Parser.ProcessImplicitMultiplication();
		Reporter.Report(Reporter.Event.ProcessedImplicitMultiplication);
	}

	private static void			ExecuteAnalyzer()
	{
		Analyzer.BuildTerms();
		Reporter.Report(Reporter.Event.BuiltTerms);
		
		Analyzer.SortTerms();
		Reporter.Report(Reporter.Event.SortedTerms);
	}

	private static void			ExecuteSolver()
	{
		Solver.Solve();
		Reporter.Report(Reporter.Event.SolvedEquation);
		
		Reporter.Report(Reporter.Request.EquationInfo);
	}
}