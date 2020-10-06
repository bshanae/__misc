using System;
using System.Linq;

namespace						Computor
{
	public class				Operator : Token
	{
		public static string	AssociatedCharacters => "+-*/^=";
		public static int		LengthLimit => 1;
		
		public enum 			Type
		{
			Addition,
			Subtraction,
			Multiplication,
			Division,
			Power,
			Equality
		}

		public readonly Type	ThisType;
		
		public					Operator(string @string) : base(@string)
		{
			switch (@string[0])
			{
				case '+' :
					ThisType = Type.Addition;
					break ;
					
				case '-' :
					ThisType = Type.Subtraction;
					break ;
					
				case '*' :
					ThisType = Type.Multiplication;
					break ;
					
				case '/' :
					ThisType = Type.Division;
					break ;
					
				case '^' :
					ThisType = Type.Power;
					break ;
					
				case '=' :
					ThisType = Type.Equality;
					break ;
				
				default :
					throw new Exception("[Operator] Can't build instance");
			}
		}

		public bool				IsAnyOf(params Type[] types) => types.Contains(ThisType);
	}
}