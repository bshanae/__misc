using System;
using System.Collections.Generic;
using System.Linq;

namespace					Computor
{
	public static class		Validator
	{
		public static void	ValidateArguments(List<string> arguments)
		{
			if (arguments.Count < 1)
				ExitWithCode(Error.Code.ExpressionIsNotGiven);
		}
		
		public static void	ValidateExpression()
		{
			// static bool		IsCharacterValid(char character)
			// {
			// 	if (Parser.CharactersOfConstant.Contains(character))
			// 		return true;
			// 	if (Parser.CharactersOfVariable.Contains(character))
			// 		return true;
			// 	if (Parser.CharactersOfOperator.Contains(character))
			// 		return true;
			// 	if (Parser.IgnoredCharacters.Contains(character))
			// 		return true;
			//
			// 	return false;
			// }
			//
			// foreach (var character in Workspace.Expression)
			// 	if (!IsCharacterValid(character))
			// 		ExitWithCode(Error.Code.InvalidCharacter);
		}

		public static void	ValidateToken()
		{
			
		}

		public static void	ValidateTokens()
		{

		}

		public static void	ValidateTerms()
		{

		}

		public static void	ValidateSortedTerms()
		{

		}

		private static void	ExitWithCode(Error.Code code)
		{
			Console.WriteLine("Computor error : " + Error.GetMessage(code));
			Environment.Exit(1);
		}
	}
}