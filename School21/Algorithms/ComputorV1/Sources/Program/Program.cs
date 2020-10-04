using System.Collections.Generic;
using Computor;

public static class			Program
{
	public static class		Options
	{
		public static bool	Verbose = false;
		public static bool	Test = false;
	
		public static void	Parse(List<string> flags)
		{
			for (int i = 0; i < flags.Count; i++)
				switch (flags[i])
				{
					case "Verbose" :
					case "verbose" :
						Verbose = true;
						flags.RemoveAt(i--);
						break;
					
					case "Test" :
					case "test" :
						Test = true;
						flags.RemoveAt(i--);
						break;
				}
		}
	}
	
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
		
		Workspace.Expression = "7x^2 - 3x - 22 = 0";

		Parser.Parse();
		Parser.ProcessUnaryMinus();
		Parser.ProcessImplicitMultiplication();
		
		Analyzer.BuildTerms();
		Analyzer.SortTerms();
		
		Solver.Solve();
	}
}