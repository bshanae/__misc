using System.Linq;
using Computor;

public static class		Reporter
{
	public enum			Event
	{
		ParsedExpression,
		ProcessedUnaryMinus,
		ProcessedImplicitMultiplication,
		BuiltTerms,
		SortedTerms,
		SolvedEquation
	}
	
	public enum			Request
	{
		EquationInfo
	}
	
	#region				Report interface
	
	public static void	Report(Event @event)
	{
		switch (@event)
		{
			case Event.ParsedExpression :
				ReportWhenParsedTokens();
				break ;
			
			case Event.ProcessedUnaryMinus :
				ReportWhenProcessedUnaryMinus();
				break ;
			
			case Event.ProcessedImplicitMultiplication :
				ReportWhenProcessedImplicitMultiplication();
				break ;
			
			case Event.BuiltTerms :
				ReportWhenBuiltTerms();
				break ;
				
			case Event.SortedTerms :
				ReportWhenSortedTerms();
				break ;
			
			case Event.SolvedEquation :
				ReportWhenSolvedEquation();
				break ;
		}
	}

	public static void	Report(Request request)
	{
		switch (request)
		{
			case Request.EquationInfo:
				ReportEquationInfo();
				break;
		}
	}
	
	#endregion
	
	#region				Report implementations

	private static void	ReportWhenParsedTokens()
	{
		if (Program.Options.Report == Program.Options.ReportFormat.Internal)
			PrintTokensWithMessage("Parsed tokens");
	}
	
	private static void	ReportWhenProcessedUnaryMinus()
	{
		if (Program.Options.Report == Program.Options.ReportFormat.Internal)
			PrintTokensWithMessage("Processed unary minus");
	}
	
	private static void	ReportWhenProcessedImplicitMultiplication()
	{
		if (Program.Options.Report == Program.Options.ReportFormat.Internal)
			PrintTokensWithMessage("Processed implicit multiplication");
	}
	
	private static void	ReportWhenBuiltTerms()
	{
		if (Program.Options.Report == Program.Options.ReportFormat.Internal)
		{
			Printer.PrintLine();
			Printer.Print("Build terms : ");

			for (int i = 0; i < Workspace.Terms.Count; i++)
			{
				Printer.Print(Workspace.Terms[i]);
					
				if (i < Workspace.Terms.Count - 1)
					Printer.Print(", ");		
			}
			
			Printer.PrintLine();
		}
	}
	
	private static void	ReportWhenSortedTerms()
	{
		if (Program.Options.Report == Program.Options.ReportFormat.Internal)
		{
			Printer.Print("Sorted terms : ");

			for (int i = 0; i < Workspace.SortedTerms.Count; i++)
			{
				Printer.Print(Workspace.SortedTerms[i]);
					
				if (i < Workspace.SortedTerms.Count - 1)
					Printer.Print(", ");		
			}
			
			Printer.PrintLine();
		}
	}

	private static void	ReportWhenSolvedEquation()
	{
		if (Program.Options.Report == Program.Options.ReportFormat.Internal)
		{
			Printer.Print("Solved equation, equation roots : ");
			PrintEquationRoots();
		}
	}

	private static void	ReportEquationInfo()
	{
		if (Program.Options.Report == Program.Options.ReportFormat.Standard)
		{
			PrintReducedEquation();
			PrintEquationDegree();
			PrintDiscriminantSign();
			
			Printer.Print("Equation roots : ");
			PrintEquationRoots();
		}
	}
	
	#endregion

	#region				Helper methods
	
	private static void	PrintTokensWithMessage(string message)
	{
		Printer.Print(message + " : ");
		Workspace.Tokens.ForEach(token => Printer.Print($"{token} "));
		Printer.PrintLine();
	}

	private static void PrintReducedEquation()
	{
		static void		PrintTerm(Term term, bool printPlusSign)
		{
			bool		shouldShowFactor;
			bool		shouldShowVariable;
			bool		shouldShowPower;

			shouldShowVariable = term.Factor != 0f && term.Power != 0f;
			shouldShowPower = term.Power != 0f && term.Power != 1f;
			shouldShowFactor = term.Factor != 1f || !shouldShowVariable;

			string				result = "";

			if (term.Factor < 0f)
				result += "- ";
			else if (printPlusSign)
				result += "+ ";
			
			if (shouldShowFactor)
				result += $"{Math.Absolute(term.Factor)}";
			if (shouldShowFactor && shouldShowVariable)
				result += " * ";
			if (shouldShowVariable)
				result += "x";
			if (shouldShowPower)
				result += $" ^ {term.Power}";

			Printer.Print(result);
		}
			
		bool			didPrintATerm = false;  

		Printer.Print("Reduced form : ");
		
		if (Workspace.SortedTerms.ContainsKey(2))
		{
			PrintTerm(Workspace.SortedTerms[2], false);
			didPrintATerm = true;
		}
		
		if (Workspace.SortedTerms.ContainsKey(1))
		{
			if (didPrintATerm)
				Printer.Print(" ");
			
			PrintTerm(Workspace.SortedTerms[1], true);
			didPrintATerm = true;
		}
		
		if (Workspace.SortedTerms.ContainsKey(0))
		{
			if (didPrintATerm)
				Printer.Print(" ");
			
			PrintTerm(Workspace.SortedTerms[0], true);
			didPrintATerm = true;
		}
		
		if (!didPrintATerm)
			Printer.Print("0");
		
		Printer.PrintLine(" = 0");
	}

	private static void PrintEquationDegree()
	{
		int				maximumDegree;
			
		maximumDegree = Workspace.SortedTerms.Select(powerAndTerm => powerAndTerm.Key).Max();
		Printer.PrintLine($"Polynomial degree : {maximumDegree}");
	}

	private static void PrintDiscriminantSign()
	{
		if (Workspace.Discriminant > 0f)
			Printer.PrintLine("Discriminant is strictly positive, equation has two roots");
		if (Workspace.Discriminant == 0f)
			Printer.PrintLine("Discriminant is zero, equation has one root");
		if (Workspace.Discriminant < 0f)
			Printer.PrintLine("Discriminant is strictly negative, equation doesn't have roots");
	}

	private static void PrintEquationRoots()
	{
		int				rootsCount = 0;

		rootsCount += Workspace.EquationRoots[0] != null ? 1 : 0;
		rootsCount += Workspace.EquationRoots[1] != null ? 1 : 0;
		
		if (Program.Options.Report == Program.Options.ReportFormat.Internal)
			Printer.Print("Equation roots : ");
		
		if (rootsCount == 2)
			Printer.PrintLine($"{Workspace.EquationRoots[0]}, {Workspace.EquationRoots[1]}");
		else if (rootsCount == 1)
			Printer.PrintLine($"{Workspace.EquationRoots[0]}");
		else if (rootsCount == 0)
			Printer.PrintLine("None");
	}

	#endregion
}


