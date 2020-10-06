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

			while (_expressionQueue.Count > 0)
				if (TryExtractToken(typeof(Constant))) ;
				else if (TryExtractToken(typeof(Variable))) ;
				else if (TryExtractToken(typeof(Operator))) ;
				else if (IgnoredCharacters.Contains(_expressionQueue.Peek()))
					_expressionQueue.Dequeue();
				else
					throw new Exception("[Parser] Unexpected character");
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

			return Activator.CreateInstance(classType, tokenString) as Token;
		}

		private static string		GetAssociatedCharacters(Type classType)
		{
			return GetStaticProperty<string>(classType, "AssociatedCharacters");
		}
		
		private static int			GetLengthLimit(Type classType)
		{
			return GetStaticProperty<int>(classType, "LengthLimit");
		}

		private static T			GetStaticProperty<T>(Type classType, string propertyName)
		{
			PropertyInfo			propertyInfo;
			object					propertyObject;

			if ((propertyInfo = classType.GetProperty(propertyName)) == null)
				throw new Exception($"[Parser] Can't get property of class {classType}");
			
			if ((propertyObject = propertyInfo.GetValue(null, null)) == null)
				throw new Exception($"[Parser] Can't get value of property for class {classType}");
			
			if (!(propertyObject is T))
				throw new Exception($"[Parser] Can't cast property to target type");

			return (T)propertyObject;
		}

		#endregion
	}
}