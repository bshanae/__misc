using System;

namespace							Computor
{
	public static class				Analyzer
	{
		#region						Nested types
		
		private class				Expectation
		{
			public enum				Option
			{
				Operand = 0x00001,
				ConstantForPower = 0x00010,
				InternalOperator = 0x01000,
				ExternalOperator = 0x00100,
				End = 0x10000
			}

			private readonly int	Options;

			public					Expectation(params Option[] options)
			{
				foreach (var option in options)
					Options |= (int)option;
			}
			
			public static bool		IsTokenExpected(Option option, Token token)
			{
				switch (option)
				{
					case Option.Operand :
						return token is Operand;
					
					case Option.ConstantForPower :
						return token is Constant;
					
					case Option.InternalOperator :
						if (token is Operator internalOperator)
							return internalOperator.IsAnyOf
								(
									Operator.Type.Multiplication,
									Operator.Type.Division,
									Operator.Type.Power
								);
						else
							return false;
						
					case Option.ExternalOperator :
						if (token is Operator externalOperator)
							return externalOperator.IsAnyOf
								(
									Operator.Type.Addition,
									Operator.Type.Subtraction,
									Operator.Type.Equality
								);
						else
							return false;

					case Option.End :
						return token == null;
				}
				
				throw new Exception("[Equation.Solver.Expectation, IsTokenExpected] Unexpected path");
			}

			public bool				IsTokenExpected(Token token)
			{
				bool				result = false;
				
				void				CheckSpecificOption(Option option)
				{
					if (IsOptionSet(option))
						result = result || IsTokenExpected(option, token);	
				}
				
				CheckSpecificOption(Option.Operand);
				CheckSpecificOption(Option.ConstantForPower);
				CheckSpecificOption(Option.InternalOperator);
				CheckSpecificOption(Option.ExternalOperator);
				CheckSpecificOption(Option.End);

				return result;
			}

			public bool				IsOptionSet(Option option)
			{
				return (Options & (int)option) == (int)option;
			}
		}
		
		#endregion
		
		#region						Fields

		private static Token		CurrentToken = null;
		private static Expectation	CurrentExpectation = null;
		private static Term			CurrentTerm = null;
		private static Operator		LastInternalOperator = null;
		private static Operator		LastExternalOperator = null;
		private static bool			IsRightSideOfEquation = false;
		
		#endregion
		
		#region						Main methods
		
		public static void			BuildTerms()
		{
			CurrentExpectation = new Expectation(Expectation.Option.Operand);

			foreach (var token in Workspace.Tokens)
				ProcessToken(token);
			
			ProcessToken(null);
		}

		public static void			SortTerms()
		{
			foreach (var term in Workspace.Terms)
				SortTerm(term);
		}
		
		#endregion
		
		#region						Term processing

		private static void			ProcessToken(Token currentToken)
		{
			bool					TryProcessOption(Expectation.Option option)
			{
				if (!CurrentExpectation.IsOptionSet(option))
					return false;
				if (!Expectation.IsTokenExpected(option, CurrentToken))
					return false;
				
				ProcessOption(option);
				return true;
			}
			
			CurrentToken = currentToken;
			
			if (TryProcessOption(Expectation.Option.Operand))
				;
			else if (TryProcessOption(Expectation.Option.ConstantForPower))
				;
			else if (TryProcessOption(Expectation.Option.InternalOperator))
				;
			else if (TryProcessOption(Expectation.Option.ExternalOperator))
				;
			else if (TryProcessOption(Expectation.Option.End))
				;
			else
				throw new Exception("[Equation.Solver, ProcessToken] Can't process token");
		}

		#endregion
		
		#region						Option processing
		
		private static void			ProcessOption(Expectation.Option option)
		{
			switch (option)
			{
				case Expectation.Option.Operand :
					ProcessOperand();
					break;

				case Expectation.Option.ConstantForPower :
					ProcessConstantForPower();
					break;

				case Expectation.Option.InternalOperator :
					ProcessInternalOperator();
					break;
				
				case Expectation.Option.ExternalOperator :
					ProcessExternalOperator();
					break;

				case Expectation.Option.End :
					ProcessEnd();
					break;
			}
		}
		
		private static void			ProcessOperand()
		{
			float					localFactor = 1f;

			if (LastExternalOperator?.ThisType == Operator.Type.Subtraction)
				localFactor *= -1f;
			if (IsRightSideOfEquation)
				localFactor *= -1f;
			
			if (CurrentToken is Constant constant)
			{
				CurrentTerm ??= new Term(constant.Factor * localFactor, 0f);

				if (LastInternalOperator == null || LastInternalOperator.ThisType == Operator.Type.Multiplication)
					CurrentTerm.Factor *= constant.Value;
				else if (LastInternalOperator.ThisType == Operator.Type.Division)
					CurrentTerm.Factor /= constant.Value;
				
				LastInternalOperator = null;
			}
			else if (CurrentToken is Variable variable)
			{
				CurrentTerm ??= new Term(variable.Factor * localFactor, 0f);
				
				if (LastInternalOperator == null || LastInternalOperator.ThisType == Operator.Type.Multiplication)
					CurrentTerm.Power++;
				else if (LastInternalOperator.ThisType == Operator.Type.Division)
					CurrentTerm.Power--;

				LastInternalOperator = null;
			}
			else
				throw new Exception("[Solver, ProcessOperand] Term building error");
			
			CurrentExpectation = new Expectation
				(
					Expectation.Option.InternalOperator,
					Expectation.Option.ExternalOperator,
					Expectation.Option.End
				);
		}
		
		private static void			ProcessConstantForPower()
		{
			if (CurrentToken is Constant constant)
			{
				if (LastInternalOperator.ThisType != Operator.Type.Power)
					throw new Exception("[Solver, ProcessPower] Term building error");

				CurrentTerm.Power += constant.Value - 1;
				LastInternalOperator = null;
			}
			else
				throw new Exception("[Solver, ProcessPower] Term building error");
			
			CurrentExpectation = new Expectation
				(
				Expectation.Option.InternalOperator,
					Expectation.Option.ExternalOperator,
					Expectation.Option.End
				);
		}
		
		private static void			ProcessInternalOperator()
		{
			if (CurrentToken is Operator @operator)
			{
				LastInternalOperator = @operator;
				
				if (@operator.ThisType == Operator.Type.Power)
					CurrentExpectation = new Expectation(Expectation.Option.ConstantForPower);
				else
					CurrentExpectation = new Expectation(Expectation.Option.Operand);
			}
			else
				throw new Exception("[Solver, ProcessInternalOperator] Term building error");
		}
		
		private static void			ProcessExternalOperator()
		{
			if (CurrentToken is Operator @operator)
			{
				Workspace.Terms.Add(CurrentTerm);
				CurrentTerm = null;
				
				LastExternalOperator = @operator;
				
				if (@operator.ThisType == Operator.Type.Equality)
					IsRightSideOfEquation = true;
			}
			else
				throw new Exception("[Solver, ProcessExternalOperator] Term building error");
			
			CurrentExpectation = new Expectation(Expectation.Option.Operand);
		}

		private static void			ProcessEnd()
		{
			if (CurrentTerm != null)
			{
				Workspace.Terms.Add(CurrentTerm);
				CurrentTerm = null;
			}

			CurrentExpectation = null;
		}

		#endregion
		
		#region						Term sorting

		private static void			SortTerm(Term term)
		{
			var						termPower = (int)term.Power;

			if (!Workspace.SortedTerms.ContainsKey(termPower))
				Workspace.SortedTerms[termPower] = term;
			else
				Workspace.SortedTerms[termPower] = Term.Sum(Workspace.SortedTerms[termPower], term);
		}
		
		#endregion
	}
}