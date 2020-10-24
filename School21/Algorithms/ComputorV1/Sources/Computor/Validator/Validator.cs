using System.Linq;

namespace						Computor
{
	public static class			Validator
	{
		#region					Interface
		
		public static void		Validate(Events @event)
		{
			switch (@event)
			{
				case Events.ParsedCommandLineArguments :
					OnParsedCommandLineArguments();
					break;
				
				case Events.ReceivedExpression :
					OnParsedExpression();
					break;
					
				case Events.ParsedTokens :
					OnParsedTokens();
					break;

				case Events.SortedTerms :
					OnSortedTerms();
					break;

				default :
					Error.RaiseInternalError();
					break;
			}
		}
		
		#endregion

		#region					Implementations
		
		private static void		OnParsedCommandLineArguments()
		{
			if (Program.Arguments.Count != 1)
				Error.RaiseUsageError(Error.UsageErrors.ExpressionIsNotGiven);
		}
		
		private static void		OnParsedExpression()
		{
			static bool			IsCharacterValid(char character)
			{
				if (Constant.AssociatedCharacters.Contains(character))
					return true;
				if (Variable.AssociatedCharacters.Contains(character))
					return true;
				if (Operator.AssociatedCharacters.Contains(character))
					return true;
				if (Parser.IgnoredCharacters.Contains(character))
					return true;
			
				return false;
			}

			foreach (var character in Workspace.Expression)
				if (!IsCharacterValid(character))
					Error.RaiseUsageError(Error.UsageErrors.InvalidCharacter);
		}

		private static void		OnParsedTokens()
		{
			Token				previousToken = null;
			Token				currentToken = null;
			Token				nextToken = null;
			
			int					equalitySignCount = 0;

			for (int i = 0; i < Workspace.Tokens.Count; i++)
			{
				previousToken = GetTokenOrNull(i - 1);
				currentToken = GetTokenOrNull(i);
				nextToken = GetTokenOrNull(i + 1);
				
				CheckMissingOperator();
				CheckMissingOperand();
				
				CollectEqualityInfo();
				CheckPower();
			}
			
			CheckEquality();
			
			Token				GetTokenOrNull(int index)
			{
				if (index < 0)
					return null;
				if (index >= Workspace.Tokens.Count)
					return null;

				return Workspace.Tokens[index];
			}

			void				CheckMissingOperator()
			{
				if (currentToken is Operand && previousToken is Operand)
					Error.RaiseUsageError(Error.UsageErrors.MissingOperator);
			}
			
			void				CheckMissingOperand()
			{
				if (currentToken is Operator && previousToken is Operator)
					Error.RaiseUsageError(Error.UsageErrors.MissingOperand);
				
				if (currentToken is Operator && previousToken == null)
					Error.RaiseUsageError(Error.UsageErrors.MissingOperand);
				if (currentToken is Operator && nextToken == null)
					Error.RaiseUsageError(Error.UsageErrors.MissingOperand);
			}
			
			void				CollectEqualityInfo()
			{
				if (currentToken is Operator maybeEquality && maybeEquality.Type == Operator.Types.Equality)
					equalitySignCount++;
			}

			void				CheckEquality()
			{
				if (equalitySignCount != 1)
					Error.RaiseUsageError(Error.UsageErrors.MoreThanOneEqualitySign);
			}

			void				CheckPower()
			{
				if (previousToken is Operator maybePower && maybePower.Type == Operator.Types.Power)
				{
					if (currentToken is Constant constant)
					{
						if (!Math.IsWhole(constant.Value))
							Error.RaiseUsageError(Error.UsageErrors.PowerIsNotInteger);
					}
					else
						Error.RaiseUsageError(Error.UsageErrors.PowerIsNotConstant);
				}
			}
		}
		
		private static void		OnSortedTerms()
		{
			foreach (var kvp in Workspace.SortedTerms)
				if (kvp.Key < 0 || kvp.Key > 2)
					Error.RaiseUsageError(Error.UsageErrors.InvalidPower);
		}
		
		#endregion

		#region 				Additional methods

		public static void		ValidateFloat(string @string)
		{
			if (!float.TryParse(@string, out _))
				Error.RaiseUsageError(Error.UsageErrors.BadFloat);
		}

		#endregion
	}
}