using System;
using System.Linq;

namespace					Computor
{
	public static class		Reporter
	{
		public enum			Requests
		{
			EquationInfo
		}

		#region				Interfaces

		public static void	Report(Events @event)
		{
			switch (@event)
			{
				case Events.ReceivedExpression:
					OnParsedTokens();
					break;

				case Events.ProcessedUnaryMinus:
					OnProcessedUnaryMinus();
					break;

				case Events.ProcessedImplicitMultiplication:
					OnProcessedImplicitMultiplication();
					break;

				case Events.BuiltElements :
					OnBuiltElements();
					break;

				case Events.GroupedElements :
					OnGroupedElements();
					break;

				case Events.ReducedElements :
					OnReducedElements();
					break;
				
				case Events.ExtractedTerms:
					OnExtractedTerms();
					break;

				case Events.SortedTerms:
					OnSortedTerms();
					break;

				case Events.SolvedEquation:
					OnSolvedEquation();
					break;
				
				default :
					Error.RaiseInternalError();
					break;
			}
		}

		public static void	Report(Requests requests)
		{
			switch (requests)
			{
				case Requests.EquationInfo:
					ReportEquationInfo();
					break;
			}
		}

		#endregion

		#region				Implementations

		private static void OnParsedTokens()
		{
			if (Program.Options.Report == Program.Options.Modes.Internal)
				PrintTokensWithMessage("Parsed tokens");
		}

		private static void OnProcessedUnaryMinus()
		{
			if (!Parser.UnaryMinusProcessingHadEffect)
				return;

			if (Program.Options.Report == Program.Options.Modes.Internal)
				PrintTokensWithMessage("Processed unary minus");
		}

		private static void OnProcessedImplicitMultiplication()
		{
			if (!Parser.ImplicitMultiplicationProcessingHadEffect)
				return;

			if (Program.Options.Report == Program.Options.Modes.Internal)
				PrintTokensWithMessage("Processed implicit multiplication");
		}

		private static void OnBuiltElements()
		{
			PrintElementsWithMessage("Built elements : ");
		}
		
		private static void OnGroupedElements()
		{
			PrintElementsWithMessage("Grouped elements : ");
		}
		
		private static void OnReducedElements()
		{
			PrintElementsWithMessage("Reduced elements : ");
		}

		private static void OnExtractedTerms()
		{
			if (Program.Options.Report == Program.Options.Modes.Internal)
			{
				Console.WriteLine();
				Console.Write("Built terms : ");

				Console.Write(string.Join(", ", Workspace.Terms));

				Console.WriteLine();
			}
		}

		private static void OnSortedTerms()
		{
			bool			PrintIfPowerPresent(int power, bool printComma = false)
			{
				if (Workspace.SortedTerms.ContainsKey(power))
				{
					if (printComma)
						Console.Write(", ");
					
					Console.Write(Workspace.SortedTerms[power]);
					return true;
				}

				return false;
			}
			
			if (Program.Options.Report == Program.Options.Modes.Internal)
			{
				bool		didPrintPreviousPower;
				
				Console.Write("Sorted terms : ");

				didPrintPreviousPower = PrintIfPowerPresent(2);
				didPrintPreviousPower = PrintIfPowerPresent(1, didPrintPreviousPower);
				PrintIfPowerPresent(0, didPrintPreviousPower);

				Console.WriteLine();
			}
		}

		private static void OnSolvedEquation()
		{
			if (Program.Options.Report == Program.Options.Modes.Internal)
				PrintEquationRoots
				(
					"Solved equation, there are no roots",
					"Solved equation, root : ",
					"Solved equation, roots : ",
					"Solved equation, roots : Any number"
				);
			else if (Program.Options.Report == Program.Options.Modes.Test)
				PrintEquationRoots("", "", "", "Any");
		}

		private static void ReportEquationInfo()
		{
			if (Program.Options.Report == Program.Options.Modes.Standard)
			{
				PrintReducedEquation();
				PrintEquationDegree();
				PrintDiscriminantSign();

				PrintEquationRoots
				(
					"Equation has no roots",
					"Equation root",
					"Equations roots",
					"Any number if solution for equation"
				);
			}
		}

		#endregion

		#region				Helper methods

		private static void PrintTokensWithMessage(string message)
		{
			Console.Write(message + " : ");
			Workspace.Tokens.ForEach(token => Console.Write($"{token} "));
			Console.WriteLine();
		}

		private static void PrintElementsWithMessage(string message)
		{
			Console.Write(message + " : ");
			Workspace.FinalGroup.ForEach(holder => Console.Write($"{holder} "));
			Console.WriteLine();
		}
		
		private static void PrintReducedEquation()
		{
			static void		PrintTerm(Term term, bool printPlusSign = false)
			{
				bool		shouldShowFactor;
				bool		shouldShowVariable;
				bool		shouldShowPower;

				shouldShowVariable = term.Factor != 0f && term.Power != 0f;
				shouldShowPower = term.Power != 0f && term.Power != 1f;
				shouldShowFactor = term.Factor != 1f || !shouldShowVariable;

				string result = "";

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

				Console.Write(result);
			}

			bool			didPrintATerm = false;

			Console.Write("Reduced form : ");

			if (Workspace.SortedTerms.ContainsKey(2))
			{
				PrintTerm(Workspace.SortedTerms[2]);
				didPrintATerm = true;
			}

			if (Workspace.SortedTerms.ContainsKey(1))
			{
				if (didPrintATerm)
					Console.Write(" ");

				PrintTerm(Workspace.SortedTerms[1], didPrintATerm);
				didPrintATerm = true;
			}

			if (Workspace.SortedTerms.ContainsKey(0))
			{
				if (didPrintATerm)
					Console.Write(" ");

				PrintTerm(Workspace.SortedTerms[0], didPrintATerm);
				didPrintATerm = true;
			}

			if (!didPrintATerm)
				Console.Write("0");

			Console.WriteLine(" = 0");
		}

		private static void PrintEquationDegree()
		{
			int				maximumDegree = 0;

			if (Workspace.SortedTerms.Count > 0)
				maximumDegree = Workspace.SortedTerms.Select(powerAndTerm => powerAndTerm.Key).Max();
			
			Console.WriteLine($"Polynomial degree : {maximumDegree}");
		}

		private static void PrintDiscriminantSign()
		{
			if (Workspace.AreRootsInfinite)
				return;

			if (Workspace.Discriminant > 0f)
				Console.WriteLine("Discriminant is strictly positive, equation has two roots");
			if (Workspace.Discriminant == 0f)
				Console.WriteLine("Discriminant is zero, equation has one root");
			if (Workspace.Discriminant < 0f)
				Console.WriteLine("Discriminant is strictly negative, equation doesn't have roots");
		}

		private static void PrintEquationRoots
		(
			string messageForNoRoots,
			string messageForOneRoot,
			string messageForTwoRoots,
			string messageForInfiniteRoots
		)
		{
			if
			(
				Program.Options.Report == Program.Options.Modes.Standard ||
				Program.Options.Report == Program.Options.Modes.Internal
			)
			{
				if (Workspace.AreRootsInfinite)
					Console.Write(messageForInfiniteRoots);
				else if (Workspace.EquationRoots.Count == 2)
					Console.Write($"{messageForTwoRoots} : ");
				else if (Workspace.EquationRoots.Count == 1)
					Console.Write($"{messageForOneRoot} : ");
				else if (Workspace.EquationRoots.Count == 0)
					Console.Write(messageForNoRoots);
			}
			else if (Program.Options.Report == Program.Options.Modes.Test)
			{
				if (Workspace.AreRootsInfinite)
					Console.Write(messageForInfiniteRoots);
			}

			if (Workspace.AreRootsInfinite)
				;
			else if (Workspace.EquationRoots.Count == 2)
				Console.Write($"{Workspace.EquationRoots[0]}, {Workspace.EquationRoots[1]}");
			else if (Workspace.EquationRoots.Count == 1)
				Console.Write($"{Workspace.EquationRoots[0]}");
			else if (Workspace.EquationRoots.Count == 0)
				Console.Write("");

			if
			(
				Program.Options.Report == Program.Options.Modes.Standard ||
				Program.Options.Report == Program.Options.Modes.Internal
			)
				Console.WriteLine();
		}

		#endregion
	}
}