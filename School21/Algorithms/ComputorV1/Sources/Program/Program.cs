using System.Collections.Generic;
using System.Linq;
using Computor;

public static partial class	Program
{
	public static void		Main(string[] arguments)
	{
		// Tests :
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

		List<string>		argumentsList = arguments.ToList();	
		
		Options.Parse(argumentsList);

		// TODO Validate
		Workspace.Expression = argumentsList[0];

		Reporter.Report(Reporter.Event.Start);
		
		Parser.Parse();
		Reporter.Report(Reporter.Event.ParsedExpression);
		
		Parser.ProcessUnaryMinus();
		Reporter.Report(Reporter.Event.ProcessedUnaryMinus);
		
		Parser.ProcessImplicitMultiplication();
		Reporter.Report(Reporter.Event.ProcessedImplicitMultiplication);
		
		Analyzer.BuildTerms();
		Reporter.Report(Reporter.Event.BuiltTerms);
		
		Analyzer.SortTerms();
		Reporter.Report(Reporter.Event.SortedTerms);
		
		Solver.Solve();
		Reporter.Report(Reporter.Event.SolvedEquation);
		
		Reporter.Report(Reporter.Request.EquationInfo);
		
		Reporter.Report(Reporter.Event.End);
	}
}