using System;
using System.Collections.Generic;
using System.Linq;
using Computor;

public static partial class		Program
{
	public static List<string>	Arguments;
		
	public static void			Main(string[] arguments)
	{
		try
		{
			ProcessArguments(arguments);
			ProcessExpression();

			ExecuteParser();
			ExecuteAnalyzer();
			ExecuteSolver();
		}
		catch (Error.UsageException exception)
		{
			Console.WriteLine("Computor usage error : " + exception.Message);

			if (Options.Report == Options.Modes.Test)
				throw;
		}
		catch (Error.InternalException)
		{
			Console.WriteLine("Computor internal error");
		}
		catch (Error.InternalAssertionException)
		{
			Console.WriteLine("Computor internal assertion error");
		}
		catch (Exception exception)
		{
			Console.WriteLine("Computor unknown error : " + exception.Message);
		}
	}

	private static void			ProcessArguments(string[] arguments)
	{
		Arguments = arguments.ToList();

		Options.Parse();
		Validator.Validate(Events.ParsedCommandLineArguments);
	}

	private static void			ProcessExpression()
	{
		Workspace.Expression = Arguments[0];
		Validator.Validate(Events.ReceivedExpression);
	}

	private static void			ExecuteParser()
	{
		Parser.Parse();
		Reporter.Report(Events.ReceivedExpression);
		
		Parser.ProcessUnaryMinus();
		Reporter.Report(Events.ProcessedUnaryMinus);
		
		Parser.ProcessImplicitMultiplication();
		Reporter.Report(Events.ProcessedImplicitMultiplication);
		
		Validator.Validate(Events.ParsedTokens);
	}

	private static void			ExecuteAnalyzer()
	{
		Analyzer.BuildElements();
		Reporter.Report(Events.BuiltElements);

		Analyzer.GroupElements();
		Reporter.Report(Events.GroupedElements);
		
		Analyzer.ReduceElements();
		Reporter.Report(Events.ReducedElements);
		
		Analyzer.ExtractTerms();
		Reporter.Report(Events.ExtractedTerms);
		
		Analyzer.SortTerms();
		Reporter.Report(Events.SortedTerms);
		Validator.Validate(Events.SortedTerms);
	}

	private static void			ExecuteSolver()
	{
		Solver.Solve();
		Reporter.Report(Events.SolvedEquation);
		
		Reporter.Report(Reporter.Requests.EquationInfo);
	}
}