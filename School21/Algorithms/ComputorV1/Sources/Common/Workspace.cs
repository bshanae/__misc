using System.Collections.Generic;
using Computor;

public static class						Workspace
{
	public static List<string>			CommandLineArguments;
	
	public static string				Expression;
	public static List<Token>			Tokens = new List<Token>();

	public static Holder				FinalHolder = new Holder();

	public static Group					FinalGroup
	{
		get
		{
			Error.Assert(FinalHolder.Element is Group);
			return FinalHolder.Element as Group;
		}
	}

	public static List<Term>			Terms = new List<Term>();
	public static Dictionary<int, Term>	SortedTerms = new Dictionary<int, Term>();

	public static float					Discriminant;
	
	public static SolutionKinds			SolutionKind = SolutionKinds.Undefined;
	public static List<Math.Fraction>	Solutions = new List<Math.Fraction>();

	static								Workspace()
	{
		FinalHolder.ConnectElement(new Group(Operator.Priorities.Final));
	}
}