using System;
using System.Collections.Generic;
using System.Linq;
using Computor;

public static partial class		Program
{
	private static List<string> arguments;
	
	public static void			Main(string[] arguments)
	{
		try
		{
			WorkWithArguments(arguments);
			WorkWithExpression();

			ExecuteParser();
			ExecuteAnalyzer();
			ExecuteSolver();
		}
		catch (Error.Exception exception)
		{
			Console.WriteLine("Computor error : " + exception.Message);

			if (Options.Report == Options.Modes.Test)
				throw;
		}
		catch (Exception exception)
		{
			Console.WriteLine("Computor internal error : " + exception.Message);
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
		Reporter.Report(Reporter.Events.ParsedExpression);
		
		Parser.ProcessUnaryMinus();
		Reporter.Report(Reporter.Events.ProcessedUnaryMinus);
		
		Parser.ProcessImplicitMultiplication();
		Reporter.Report(Reporter.Events.ProcessedImplicitMultiplication);
		
		Validator.ValidateTokens();
	}

	private static void			ExecuteAnalyzer()
	{
		Analyzer.BuildTerms();
		Reporter.Report(Reporter.Events.BuiltTerms);
		Validator.ValidateTerms();
		
		Analyzer.SortTerms();
		Reporter.Report(Reporter.Events.SortedTerms);
		Validator.ValidateSortedTerms();
	}

	private static void			ExecuteSolver()
	{
		Solver.Solve();
		Reporter.Report(Reporter.Events.SolvedEquation);
		
		Reporter.Report(Reporter.Requests.EquationInfo);
	}
}