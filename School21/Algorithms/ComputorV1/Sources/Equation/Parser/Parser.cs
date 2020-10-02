using System;
using System.Linq;
using System.Collections.Generic;

namespace							Equation
{
	public static class				Parser
	{
		private const string		CharactersOfConstant = ".0123456789";
		private const string		CharactersOfVariable = "x";
		private const string		CharactersOfOperator = "+-*/^=";
		private const string		IgnoredCharacters = " ";

		public static List<Token>	Parse(string expression)
		{
			var						characters = new Queue<char>(expression);
			var						tokens = new List<Token>();
			
			Console.WriteLine($"Expression : {expression}");
			
			while (characters.Count > 0)
			{
				if (IsAssociated<Constant>(characters.Peek()))
					tokens.Add(ExtractToken<Constant>(characters));
				else if (IsAssociated<Variable>(characters.Peek()))
					tokens.Add(ExtractToken<Variable>(characters));
				else if (IsAssociated<Operator>(characters.Peek()))
					tokens.Add(ExtractToken<Operator>(characters));
				else if (IsIgnored(characters.Peek()))
					characters.Dequeue();
				else
					throw new Exception("[Equation.Parser, Parse] Bad token");
			}
			
			PrintTokenList(tokens, "Tokenized expression : ");
			
			ProcessUnaryMinus(tokens);			
			
			PrintTokenList(tokens, "Processed unary minuses : ");

			return tokens;
		}
		
		#region						Service methods
		
		private static bool			IsAssociated<T>(char character) where T : Token
		{
			return GetAssociatedCharacters<T>().Contains(character);
		}

		private static bool			IsIgnored(char character)
		{
			return IgnoredCharacters.Contains(character);
		}

		private static Token		ExtractToken<T>(Queue<char> expression) where T : Token
		{
			int						tokenLengthLimit = GetLenghtLimitOfToken<T>();			
			string					tokenString = "";

			while (expression.Count > 0 && tokenString.Length < tokenLengthLimit)
				if (IsAssociated<T>(expression.Peek()))
					tokenString += expression.Dequeue();
				else
					break;

			return (T)Activator.CreateInstance(typeof(T), tokenString);
		}

		private static void			ProcessUnaryMinus(List<Token> tokens)
		{
			bool					IsSubtractionOperator(int i) => tokens[i] is Operator @operator && @operator.Type == Operator.Types.Subtraction;

			for (var i = 0; i < tokens.Count - 1; i++)
				if (IsSubtractionOperator(i) && tokens[i + 1] is Operand operand)
				{
					operand.Factor *= -1f;
					tokens.RemoveAt(i--);
				}
		}

		private static void			ProcessHiddenMultiplication(List<Token> tokens)
		{
			// for (var i = 0; i < tokens.Count; i++)
				
		}

		private static void			PrintTokenList(List<Token> tokens, string message = null)
		{
			if (message != null)
				Console.Write($"{message} : ");

			for (var i = 0; i < tokens.Count; i++)
			{
				Console.Write(tokens[i]);
				if (i < tokens.Count - 1)
					Console.Write(" ");
			}
			
			Console.WriteLine();
		}
		
		#endregion
		
		#region						Helper methods

		private static string		GetAssociatedCharacters<T>() where T : Token
		{
			if (typeof(T) == typeof(Constant))
				return CharactersOfConstant;
			if (typeof(T) == typeof(Variable))
				return CharactersOfVariable;
			if (typeof(T) == typeof(Operator))
				return CharactersOfOperator;
			
			throw new Exception("[Equation.Parser, GetAssociatedCharacters] Unknown token type"); 
		}

		private static int			GetLenghtLimitOfToken<T>() where T : Token
		{
			if (typeof(T) == typeof(Constant))
				return int.MaxValue;
			if (typeof(T) == typeof(Variable))
				return 1;
			if (typeof(T) == typeof(Operator))
				return 1;
			
			throw new Exception("[Equation.Parser, GetLenghtLimitOfToken] Unknown token type"); 
		}

		#endregion
	}
}