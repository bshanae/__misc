using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;

namespace					Computor
{
	public static class		Validator
	{
		public static void	ValidateArguments(List<string> arguments)
		{
			if (arguments.Count < 1)
				throw new Error.Exception(Error.Code.ExpressionIsNotGiven);
		}
		
		public static void	ValidateExpression()
		{
			static bool		IsCharacterValid(char character)
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
					throw new Error.Exception(Error.Code.InvalidCharacter);
		}

		public static void	ValidateFloat(string @string)
		{
			if (!float.TryParse(@string, out _))
				throw new Error.Exception(Error.Code.BadFloat);
		}

		public static void	ValidateTokens()
		{
			Token			previousToken = null;
			Token			currentToken = null;
			Token			nextToken = null;
			
			int				equalitySignCount = 0;

			Token			GetTokenOrNull(int index)
			{
				if (index < 0)
					return null;
				if (index >= Workspace.Tokens.Count)
					return null;

				return Workspace.Tokens[index];
			}

			void			CheckMissingOperator()
			{
				if (currentToken is Operand && previousToken is Operand)
					throw new Error.Exception(Error.Code.MissingOperator);
			}
			
			void			CheckMissingOperand()
			{
				if (currentToken is Operator && previousToken is Operator)
					throw new Error.Exception(Error.Code.MissingOperand);
				
				if (currentToken is Operator && previousToken == null)
					throw new Error.Exception(Error.Code.MissingOperand);
				if (currentToken is Operator && nextToken == null)
					throw new Error.Exception(Error.Code.MissingOperand);
			}
			
			void			CollectEqualityInfo()
			{
				if (currentToken is Operator maybeEquality && maybeEquality.ThisType == Operator.Type.Equality)
					equalitySignCount++;
			}

			void			CheckEquality()
			{
				if (equalitySignCount != 1)
					throw new Error.Exception(Error.Code.MoreThanOneEqualitySign);
			}

			void			CheckPower()
			{
				if (previousToken is Operator maybePower && maybePower.ThisType == Operator.Type.Power)
				{
					if (currentToken is Constant constant)
					{
						if (!Math.IsWhole(constant.Value))
							throw new Error.Exception(Error.Code.PowerIsNotInteger);
					}
					else
						throw new Error.Exception(Error.Code.PowerIsNotConstant);
				}
			}

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
		}

		public static void	ValidateTerms()
		{}

		public static void	ValidateSortedTerms()
		{
			foreach (var kvp in Workspace.SortedTerms)
				if (kvp.Key < 0 || kvp.Key > 2)
					throw new Error.Exception(Error.Code.InvalidPower);
		}
	}
}