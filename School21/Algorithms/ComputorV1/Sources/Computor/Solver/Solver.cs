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
				Workspace.EquationRoots.Add(new Math.Fraction(-b - Math.SquareRoot(discriminant), 2 * a));
				Workspace.EquationRoots.Add(new Math.Fraction(-b + Math.SquareRoot(discriminant), 2 * a));
				
				Workspace.EquationRoots = Workspace.EquationRoots.OrderBy(fraction => fraction.Value).ToList();
			}
			else if (discriminant == 0)
				Workspace.EquationRoots.Add(new Math.Fraction(-b, 2 * a));

			Workspace.Discriminant = discriminant;
		}
		
		private static void				SolveIncompleteQuadraticEquation(float a, float b, float c)
		{
			if (a == 0)
				Workspace.EquationRoots.Add(new Math.Fraction(c, -b));
			else if (b == 0)
			{
				Workspace.EquationRoots.Add(new Math.Fraction(-Math.SquareRoot(c / -a)));
				Workspace.EquationRoots.Add(new Math.Fraction(+Math.SquareRoot(c / -a)));
			}
		}

		private static void				SolveSpecialCases(float c)
		{
			if (c == 0)
				Workspace.AreRootsInfinite = true;
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
				Workspace.EquationRoots.Count == 2
				&& Math.AlmostEqual(Workspace.EquationRoots[0].Value, Workspace.EquationRoots[1].Value)
			)
				Workspace.EquationRoots.RemoveAt(1);
		}
	}
}