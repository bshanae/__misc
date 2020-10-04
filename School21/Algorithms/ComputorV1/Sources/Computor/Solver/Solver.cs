using System;

namespace								Computor
{
	public class						Solver
	{
		public static void				Solve()
		{
			float						a = GetFactorByPower(2);
			float						b = GetFactorByPower(1);
			float						c = GetFactorByPower(0);
		
			if (a != 0f && b != 0f)
				SolveCompleteQuadraticEquation(a, b ,c);
			else
				SolveIncompleteQuadraticEquation(a, b ,c);
		}
		
		private static void				SolveCompleteQuadraticEquation(float a, float b, float c)
		{
			float						discriminant = b * b - 4 * a * c;
	
			if (discriminant > 0)
			{
				Workspace.EquationRoots[0] = new Math.Fraction(-b + Math.SquareRoot(discriminant), 2 * a);
				Workspace.EquationRoots[1] = new Math.Fraction(-b - Math.SquareRoot(discriminant), 2 * a);
			}
			else if (discriminant == 0)
				Workspace.EquationRoots[0] = new Math.Fraction(-b, 2 * a);

			Workspace.Discriminant = discriminant;
		}
		
		private static void				SolveIncompleteQuadraticEquation(float a, float b, float c)
		{
			if (a == 0)
				Workspace.EquationRoots[0] = new Math.Fraction(c, -b);
			else if (b == 0)
			{
				Workspace.EquationRoots[0] = new Math.Fraction(-Math.SquareRoot(c / -a));
				Workspace.EquationRoots[1] = new Math.Fraction(+Math.SquareRoot(c / -a));
			}
		}
	
		private static float			GetFactorByPower(int power)
		{
			if (Workspace.SortedTerms.ContainsKey(power))
				return Workspace.SortedTerms[power].Factor;
			else
				return 0f;
		}
	}
}