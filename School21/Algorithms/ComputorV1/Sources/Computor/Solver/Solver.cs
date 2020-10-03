using System;

namespace								Computor
{
	public class						Solver
	{
		private static Math.Fraction?[]	Roots = new Math.Fraction?[2];
		public static void				Solve()
		{
			float						a = GetFactorByPower(2);
			float						b = GetFactorByPower(1);
			float						c = GetFactorByPower(0);
		
			if (a != 0f && b != 0f)
				SolveCompleteQuadraticEquation(a, b ,c);
			else
				SolveIncompleteQuadraticEquation(a, b ,c);
			
			if (Roots[0] != null && Roots[1] != null)
				Console.WriteLine($"Equation roots : {Roots[0]}, {Roots[1]}");
			else if (Roots[0] != null && Roots[1] == null)
				Console.WriteLine($"Equation root : {Roots[0]}");
			else if (Roots[0] == null && Roots[1] == null)
				Console.WriteLine("Equation has no roots");
		}
		
		private static void				SolveCompleteQuadraticEquation(float a, float b, float c)
		{
			float						discriminant = b * b - 4 * a * c;
	
			if (discriminant > 0)
			{
				Roots[0] = new Math.Fraction(-b + Math.SquareRoot(discriminant), 2 * a);
				Roots[1] = new Math.Fraction(-b - Math.SquareRoot(discriminant), 2 * a);
			}
			else if (discriminant == 0)
				Roots[0] = new Math.Fraction(-b, 2 * a);
		}
		
		private static void				SolveIncompleteQuadraticEquation(float a, float b, float c)
		{
			if (a == 0)
				Roots[0] = new Math.Fraction(c, -b);
			else if (b == 0)
			{
				Roots[0] = new Math.Fraction(-Math.SquareRoot(c / -a));
				Roots[1] = new Math.Fraction(+Math.SquareRoot(c / -a));
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