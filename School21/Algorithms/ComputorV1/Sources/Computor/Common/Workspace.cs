using System.Collections.Generic;

namespace									Computor
{
	public static class						Workspace
	{
		public static string				Expression;
		public static List<Token>			Tokens = new List<Token>();

		public static Holder				FinalHolder = new Holder(); 
		public static Group					FinalGroup;
		
		public static List<Term>			Terms = new List<Term>();
		public static Dictionary<int, Term>	SortedTerms = new Dictionary<int, Term>();

		public static float					Discriminant;
		public static List<Math.Fraction>	EquationRoots = new List<Math.Fraction>();
		public static bool					AreRootsInfinite = false;

		static								Workspace()
		{
			FinalGroup = new Group(Operator.Priorities.Final);
			FinalGroup.Place(FinalHolder);
		}
	}
}