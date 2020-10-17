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
}