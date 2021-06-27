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

		Analyzer.GroupElements(Operator.Priorities.Power);
		Reporter.Report(Events.GroupedPower);

		Analyzer.GroupElements(Operator.Priorities.MultiplicationAndDivision);
		Reporter.Report(Events.GroupedMultiplicationAndDivision);

		Analyzer.GroupElements(Operator.Priorities.AdditionAndSubtraction);
		Reporter.Report(Events.GroupedAdditionAndSubtraction);

		Analyzer.ReduceElements(Operator.Priorities.Power);
		Reporter.Report(Events.ReducedPower);

		Analyzer.ReduceElements(Operator.Priorities.MultiplicationAndDivision);
		Reporter.Report(Events.ReducedMultiplicationAndDivision);

		Analyzer.ReduceElements(Operator.Priorities.Equality);
		Reporter.Report(Events.ReducedEquality);

		Analyzer.ReduceElements(Operator.Priorities.AdditionAndSubtraction);
		Reporter.Report(Events.ReducedAdditionAndSubtraction);

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
		
		Reporter.Info(Reporter.Requests.EquationInfo);
	}
}