using System.Collections.Generic;

namespace									Computor
{
	public static class						Workspace
	{
		public static string				Expression;
		public static List<Token>			Tokens = new List<Token>();
		public static List<Term>			Terms = new List<Term>();
		public static Dictionary<int, Term>	SortedTerms = new Dictionary<int, Term>();

		public static float					Discriminant;
		public static Math.Fraction?[]		EquationRoots = new Math.Fraction?[2];
	}
}