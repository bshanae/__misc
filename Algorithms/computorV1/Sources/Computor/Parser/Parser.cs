using System;
using System.Linq;
using System.Collections.Generic;
using System.Reflection;

namespace							Computor
{
	public static class				Parser
	{
		public const string			IgnoredCharacters = " ";

		public static bool			UnaryMinusProcessingHadEffect
		{
			get ;
			private set ;
		}
		
		public static bool			ImplicitMultiplicationProcessingHadEffect
		{
			get ;
			private set ;
		}

		private static Queue<char>	_expressionQueue;

		public static void			Parse()
		{
			UnaryMinusProcessingHadEffect = false;
			ImplicitMultiplicationProcessingHadEffect = false;
			
			_expressionQueue = new Queue<char>(Workspace.Expression);

#pragma warning disable 642
			while (_expressionQueue.Count > 0)
				if (TryExtractToken(typeof(Constant))) ;
				else if (TryExtractToken(typeof(Variable))) ;
				else if (TryExtractToken(typeof(Operator))) ;
				else if (IgnoredCharacters.Contains(_expressionQueue.Peek()))
					_expressionQueue.Dequeue();
				else
					Error.RaiseInternalError();
		}
#pragma warning restore 642

		
		public static void			ProcessUnaryMinus()
		{
			static bool				IsUnaryMinus(int i)
			{
				return IsOperatorGood() && IsPreviousTokenGood() && IsNextTokenGood();

				bool				IsOperatorGood() => Workspace.Tokens[i] is Operator @operator && @operator.Type == Operator.Types.Subtraction;
				bool				IsPreviousTokenGood() => i == 0 || !(Workspace.Tokens[i - 1] is Operand);
				bool				IsNextTokenGood() => Workspace.Tokens[i + 1] is Operand;
			}

			for (var i = 0; i < Workspace.Tokens.Count - 1; i++)
				if (IsUnaryMinus(i))
				{
					var				operand = Workspace.Tokens[i + 1] as Operand;
					
					operand.Factor *= -1f;
					if (i > 0 && Workspace.Tokens[i - 1] is Operand)
					{
						Workspace.Tokens.RemoveAt(i);
						Workspace.Tokens.Insert(i, new Operator("+"));
					}
					else
						Workspace.Tokens.RemoveAt(i--);

					UnaryMinusProcessingHadEffect = true;
				}
		}

		public static void			ProcessImplicitMultiplication()
		{
			for (var i = 0; i < Workspace.Tokens.Count - 1; i++)
				if (Workspace.Tokens[i] is Constant && Workspace.Tokens[i + 1] is Variable)
				{
					Workspace.Tokens.Insert(i++ + 1, new Operator("*"));
					ImplicitMultiplicationProcessingHadEffect = true;
				}
		}
		
		#region						Service methods

		private static bool			TryExtractToken(Type classType)
		{
			if (GetAssociatedCharacters(classType).Contains(_expressionQueue.Peek()))
			{
				Workspace.Tokens.Add(ExtractToken(classType));
				return true;
			}

			return false;
		}

		private static Token		ExtractToken(Type classType)
		{
			string					associatedCharacters = GetAssociatedCharacters(classType);
			int						tokenLengthLimit = GetLengthLimit(classType);
			
			string					tokenString = "";

			while (_expressionQueue.Count > 0 && tokenString.Length < tokenLengthLimit)
				if (associatedCharacters.Contains(_expressionQueue.Peek()))
					tokenString += _expressionQueue.Dequeue();
				else
					break;
			
			if (classType == typeof(Constant))
				Validator.ValidateFloat(tokenString);

			return Activator.CreateInstance(classType, tokenString) as Token;
		}

		private static string		GetAssociatedCharacters(Type classType)
		{
			return Utilities.GetStaticProperty<string>(classType, "AssociatedCharacters");
		}
		
		private static int			GetLengthLimit(Type classType)
		{
			return Utilities.GetStaticProperty<int>(classType, "LengthLimit");
		}

		#endregion
	}
}