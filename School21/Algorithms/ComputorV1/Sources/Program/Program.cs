using System;
using System.Linq;
using Computor;

public static partial class		Program
{
	public static void			Main(string[] arguments)
	{
		try
		{
			ProcessArguments(arguments);

			ExecuteParser();
			ExecuteAnalyzer();
			ExecuteSolver();
		}
		catch (Exception exception)
		{
			exception.GetReaction().Invoke();
			
			if (exception is Error.UsageException && Options.Test)
				throw;
		}
	}

	private static void			ProcessArguments(string[] arguments)
	{
		Workspace.CommandLineArguments = arguments.ToList();
		Validator.Validate(Events.ReceivedArguments);

		Workspace.Expression = Workspace.CommandLineArguments.ExtractAt(0);
		Options.Parse();
		
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