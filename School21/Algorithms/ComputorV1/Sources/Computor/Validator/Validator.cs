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
			
			int				tokensBeforeEqualityCount = 0;
			int				tokensAfterEqualityCount = 0;
			int				equalitySignCount = 0;

			void			CheckMissingOperator(Token token)
			{
				if (token is Operand && previousToken is Operand)
					throw new Error.Exception(Error.Code.MissingOperator);
			}
			
			void			CheckMissingOperand(Token token)
			{
				if (token is Operator && previousToken is Operator)
					throw new Error.Exception(Error.Code.MissingOperand);
			}
			
			void			CollectEqualityInfo(Token token)
			{
				if (token is Operator maybeEquality && maybeEquality.ThisType == Operator.Type.Equality)
					equalitySignCount++;
				else
				{
					if (equalitySignCount == 0)
						tokensBeforeEqualityCount++;
					else
						tokensAfterEqualityCount++;
				}
			}

			void			CheckEquality()
			{
				if (equalitySignCount != 1)
					throw new Error.Exception(Error.Code.MoreThanOneEqualitySign);
				
				if (tokensBeforeEqualityCount == 0)
					throw new Error.Exception(Error.Code.MissingLeftPart);
				if (tokensAfterEqualityCount == 0)
					throw new Error.Exception(Error.Code.MissingRightPart);
			}

			void			CheckPower(Token token)
			{
				if (previousToken is Operator maybePower && maybePower.ThisType == Operator.Type.Power)
				{
					if (token is Constant constant)
					{
						if (!Math.IsWhole(constant.Value))
							throw new Error.Exception(Error.Code.PowerIsNotInteger);
					}
					else
						throw new Error.Exception(Error.Code.PowerIsNotConstant);
				}
			}

			foreach (var token in Workspace.Tokens)
			{
				CheckMissingOperator(token);
				CheckMissingOperand(token);
				
				CollectEqualityInfo(token);
				CheckPower(token);
				
				previousToken = token;
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