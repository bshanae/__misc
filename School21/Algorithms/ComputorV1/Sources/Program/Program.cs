using Computor;

public static class		Program
{
	public static void	Main(string[] arguments)
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

		Workspace.Expression = "x^2 = 4";

		Parser.Parse();
		Parser.ProcessUnaryMinus();
		Parser.ProcessImplicitMultiplication();
		
		Analyzer.BuildTerms();
		Analyzer.SortTerms();
		
		Solver.Solve();
	}
}