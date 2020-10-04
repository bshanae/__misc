using System;
using System.Linq;
using System.Collections.Generic;

namespace							Computor
{
	public static class				Parser
	{
		private const string		CharactersOfConstant = ".0123456789";
		private const string		CharactersOfVariable = "x";
		private const string		CharactersOfOperator = "+-*/^=";
		private const string		IgnoredCharacters = " ";

		public static void			Parse()
		{
			var						characters = new Queue<char>(Workspace.Expression);

			while (characters.Count > 0)
			{
				if (IsAssociated<Constant>(characters.Peek()))
					Workspace.Tokens.Add(ExtractToken<Constant>(characters));
				else if (IsAssociated<Variable>(characters.Peek()))
					Workspace.Tokens.Add(ExtractToken<Variable>(characters));
				else if (IsAssociated<Operator>(characters.Peek()))
					Workspace.Tokens.Add(ExtractToken<Operator>(characters));
				else if (IsIgnored(characters.Peek()))
					characters.Dequeue();
				else
					throw new Exception("[Equation.Parser, Parse] Bad token");
			}
		}
		
		public static void			ProcessUnaryMinus()
		{
			bool					IsSubtractionOperator(int i)
			{
				return Workspace.Tokens[i] is Operator @operator && @operator.ThisType == Operator.Type.Subtraction;
			}

			for (var i = 0; i < Workspace.Tokens.Count - 1; i++)
				if (IsSubtractionOperator(i) && Workspace.Tokens[i + 1] is Operand operand)
				{
					operand.Factor *= -1f;

					if (i > 0 && Workspace.Tokens[i - 1] is Operand)
					{
						Workspace.Tokens.RemoveAt(i);
						Workspace.Tokens.Insert(i, new Operator("+"));
					}
					else
						Workspace.Tokens.RemoveAt(i--);
				}
		}

		public static void			ProcessImplicitMultiplication()
		{
			for (var i = 0; i < Workspace.Tokens.Count - 1; i++)
				if (Workspace.Tokens[i] is Constant && Workspace.Tokens[i + 1] is Variable)
					Workspace.Tokens.Insert(i++ + 1, new Operator("*"));
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