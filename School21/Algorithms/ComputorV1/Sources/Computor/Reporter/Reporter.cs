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

				case Events.GroupedPower :
					OnGroupedPower();
					break;
					
				case Events.GroupedMultiplicationAndDivision :
					OnGroupedMultiplicationAndDivision();
					break;
					
				case Events.GroupedAdditionAndSubtraction :
					OnGroupedAdditionAndSubtraction();
					break;
					
				case Events.ReducedPower :
					OnReducedPower();
					break;
					
				case Events.ReducedMultiplicationAndDivision :
					OnReducedMultiplicationAndDivision();
					break;
					
				case Events.ReducedEquality :
					OnReducedEquality();
					break;
					
				case Events.ReducedAdditionAndSubtraction :
					OnReducedAdditionAndSubtraction();
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

		public static void	Info(Requests requests)
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
			if (Program.Options.Report)
				PrintTokensWithMessage("Parsed tokens");
		}

		private static void OnProcessedUnaryMinus()
		{
			if (!Parser.UnaryMinusProcessingHadEffect)
				return;

			if (Program.Options.Report)
				PrintTokensWithMessage("Processed unary minus");
		}

		private static void OnProcessedImplicitMultiplication()
		{
			if (!Parser.ImplicitMultiplicationProcessingHadEffect)
				return;

			if (Program.Options.Report)
				PrintTokensWithMessage("Processed implicit multiplication");
		}

		private static void OnBuiltElements()
		{
			if (Program.Options.Report)
				PrintElementsWithMessage("Built elements");
		}
		
		private static void OnGroupedPower()
		{
			if (Program.Options.Report)
				PrintElementsWithMessage("Grouped power operations");
		}
		
		private static void OnGroupedMultiplicationAndDivision()
		{
			if (Program.Options.Report)
				PrintElementsWithMessage("Grouped multiplication and division operations");
		}
		
		private static void OnGroupedAdditionAndSubtraction()
		{
			if (Program.Options.Report)
				PrintElementsWithMessage("Grouped addition and subtraction operations");
		}
		
		private static void OnReducedPower()
		{
			if (Program.Options.Report)
				PrintElementsWithMessage("Reduced power operations");
		}
		
		private static void OnReducedMultiplicationAndDivision()
		{
			if (Program.Options.Report)
				PrintElementsWithMessage("Reduced multiplication and division operations");
		}
		
		private static void OnReducedEquality()
		{
			if (Program.Options.Report)
				PrintElementsWithMessage("Reduced equality operations");
		}
		
		private static void OnReducedAdditionAndSubtraction()
		{
			if (Program.Options.Report)
				PrintElementsWithMessage("Reduced addition and subtraction operations");
		}
		
		private static void OnExtractedTerms()
		{
			if (Program.Options.Report)
			{
				Console.Write("Extracted terms : ");

				Console.Write(string.Join(", ", Workspace.Terms));

				Console.WriteLine();
			}
		}

		private static void OnSortedTerms()
		{
			if (Program.Options.Report)
			{
				bool		didPrintPreviousPower = false;
				
				Console.Write("Sorted terms : ");

				PrintIfPowerPresent(2, ref didPrintPreviousPower);
				PrintIfPowerPresent(1, ref didPrintPreviousPower);
				PrintIfPowerPresent(0, ref didPrintPreviousPower);

				Console.WriteLine();
			}
			
			void			PrintIfPowerPresent(int power, ref bool didPrint)
			{
				if (Workspace.SortedTerms.ContainsKey(power))
				{
					if (didPrint)
						Console.Write(", ");
					
					Console.Write(Workspace.SortedTerms[power]);
					didPrint = true;
				}
			}
		}

		private static void OnSolvedEquation()
		{
			if (Program.Options.Report)
			{
				Console.WriteLine();
				PrintEquationSolutions
				(
					"Solved equation, there are no roots",
					"Solved equation, root : ",
					"Solved equation, imaginary root : ",
					"Solved equation, roots : ",
					"Solved equation, imaginary roots : ",
					"Solved equation, any number is a root"
				);
			}
		}

		private static void ReportEquationInfo()
		{
			if (!Program.Options.Report)
			{
				PrintReducedEquation();
				PrintEquationDegree();
				PrintDiscriminantSign();

				PrintEquationSolutions
				(
					"Equation has no roots",
					"Equation root : ",
					"Equation imaginary root : ",
					"Equations roots : ",
					"Equation imaginary roots : ",
					"Any number is solution of equation"
				);
			}
		}

		#endregion

		#region				Helper methods

		private static void PrintTokensWithMessage(string message)
		{
			Console.WriteLine(message + " : ");
			Workspace.Tokens.ForEach(token => Console.Write($"{token} "));
			Console.WriteLine();
			Console.WriteLine();
		}

		private static void PrintElementsWithMessage(string message)
		{
			Console.WriteLine(message + " : ");
			Console.WriteLine(Workspace.FinalGroup);
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
			if (Workspace.EquationKind == EquationKinds.Complete || Workspace.EquationKind == EquationKinds.Incomplete)
			{
				int			maximumDegree = 0;

				if (Workspace.SortedTerms.Count > 0)
					maximumDegree = Workspace.SortedTerms.Select(powerAndTerm => powerAndTerm.Key).Max();

				Console.WriteLine($"Polynomial degree : {maximumDegree}");
			}
		}

		private static void PrintDiscriminantSign()
		{
			if (Workspace.EquationKind == EquationKinds.Complete)
			{
				if (Workspace.Discriminant > 0f)
					Console.WriteLine("Discriminant is strictly positive, equation has two roots");
				if (Workspace.Discriminant == 0f)
					Console.WriteLine("Discriminant is zero, equation has one root");
				if (Workspace.Discriminant < 0f)
					Console.WriteLine("Discriminant is strictly negative, equation doesn't have real roots");
			}
		}

		private static void PrintEquationSolutions
		(
			string messageForNoSolutions,
			string messageForOneSolution,
			string messageForOneImaginarySolution,
			string messageForTwoSolutions,
			string messageForTwoImaginarySolutions,
			string messageForInfiniteSolutions
		)
		{
			switch (Workspace.SolutionKind)
			{
				case SolutionKinds.NoSolutions :
					Console.Write(messageForNoSolutions);
					break;

				case SolutionKinds.OneSolution :
					Console.Write(messageForOneSolution);
					break;

				case SolutionKinds.OneImaginarySolution :
					Console.Write(messageForOneImaginarySolution);
					break;

				case SolutionKinds.TwoSolutions :
					Console.Write(messageForTwoSolutions);
					break;

				case SolutionKinds.TwoImaginarySolutions :
					Console.Write(messageForTwoImaginarySolutions);
					break;

				case SolutionKinds.InfiniteSolutions :
					Console.Write(messageForInfiniteSolutions);
					break;
			}
			
			switch (Workspace.SolutionKind)
			{
				case SolutionKinds.OneSolution :
					Console.Write($"{Workspace.Solutions[0]}");
					break;
				
				case SolutionKinds.OneImaginarySolution :
					Console.Write($"{Workspace.ImaginarySolutions[0]}");
					break;
				
				case SolutionKinds.TwoSolutions :
					Console.Write($"{Workspace.Solutions[0]}, {Workspace.Solutions[1]}");
					break;

				case SolutionKinds.TwoImaginarySolutions :
					Console.Write($"{Workspace.ImaginarySolutions[0]}, {Workspace.ImaginarySolutions[1]}");
					break;
			}

			Console.WriteLine();
		}

		#endregion
	}
}