using System;
using System.Linq;

namespace						Computor
{
	public class				Operator : Token
	{
		public static string	AssociatedCharacters => "+-*/^=";
		public static int		LengthLimit => 1;
		
		public enum 			Types
		{
			Addition,
			Subtraction,
			Multiplication,
			Division,
			Power,
			Equality
		}

		public readonly Types	Type;
		
		public					Operator(string @string) : base(@string)
		{
			switch (@string[0])
			{
				case '+' :
					Type = Types.Addition;
					break ;
					
				case '-' :
					Type = Types.Subtraction;
					break ;
					
				case '*' :
					Type = Types.Multiplication;
					break ;
					
				case '/' :
					Type = Types.Division;
					break ;
					
				case '^' :
					Type = Types.Power;
					break ;
					
				case '=' :
					Type = Types.Equality;
					break ;
				
				default :
					throw new Exception("[Operator] Can't build instance");
			}
		}

		public bool				IsAnyOf(params Types[] types) => types.Contains(Type);
	}
	
	public static class			OperatorTypeExtensions
	{
		public static int		GetPriority(this Operator.Types types) =>
			types switch
			{
				Operator.Types.Power => 3,
				Operator.Types.Multiplication => 2,
				Operator.Types.Division => 2,
				Operator.Types.Addition => 1,
				Operator.Types.Subtraction => 1,
				Operator.Types.Equality => 0
			};
	}
}