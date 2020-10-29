using System.Linq;

namespace								Computor
{
	public static class					Solver
	{
		public static void				Solve()
		{
			float						a = GetFactorByPower(2);
			float						b = GetFactorByPower(1);
			float						c = GetFactorByPower(0);
		
			if (a != 0f && b != 0f)
				SolveCompleteQuadraticEquation(a, b, c);
			else if (a != 0f || b != 0f)
				SolveIncompleteQuadraticEquation(a, b ,c);
			else
				SolveSpecialCases(c);
			
			DeleteRedundantRoots();
		}
		
		private static void				SolveCompleteQuadraticEquation(float a, float b, float c)
		{
			float						discriminant = b * b - 4 * a * c;
	
			if (discriminant > 0)
			{
				Workspace.Solutions.Add(new Math.Fraction(-b - Math.SquareRoot(discriminant), 2 * a));
				Workspace.Solutions.Add(new Math.Fraction(-b + Math.SquareRoot(discriminant), 2 * a));
				
				Workspace.Solutions = Workspace.Solutions.OrderBy(fraction => fraction.Value).ToList();
				Workspace.SolutionKind = SolutionKinds.TwoSolutions;
			}
			else if (discriminant == 0)
			{
				Workspace.Solutions.Add(new Math.Fraction(-b, 2 * a));
				Workspace.SolutionKind = SolutionKinds.OneSolution;
			}
			else
				Workspace.SolutionKind = SolutionKinds.NoSolutions;

			Workspace.Discriminant = discriminant;
		}
		
		private static void				SolveIncompleteQuadraticEquation(float a, float b, float c)
		{
			if (a == 0)
			{
				Workspace.Solutions.Add(new Math.Fraction(c, -b));
				Workspace.SolutionKind = SolutionKinds.OneSolution;
			}
			else if (b == 0)
			{
				Workspace.Solutions.Add(new Math.Fraction(-Math.SquareRoot(c / -a)));
				Workspace.Solutions.Add(new Math.Fraction(+Math.SquareRoot(c / -a)));
				Workspace.SolutionKind = SolutionKinds.TwoSolutions;
			}
		}

		private static void				SolveSpecialCases(float c)
		{
			Workspace.SolutionKind = c == 0 ? SolutionKinds.InfiniteSolutions : SolutionKinds.NoSolutions;
		}
	
		private static float			GetFactorByPower(int power)
		{
			if (Workspace.SortedTerms.ContainsKey(power))
				return Workspace.SortedTerms[power].Factor;
			else
				return 0f;
		}

		private static void				DeleteRedundantRoots()
		{
			if
			(
				Workspace.Solutions.Count == 2
				&& Math.AlmostEqual(Workspace.Solutions[0].Value, Workspace.Solutions[1].Value)
			)
			{
				Workspace.Solutions.RemoveAt(1);
				Workspace.SolutionKind = SolutionKinds.OneSolution;
			}
		}
	}
}