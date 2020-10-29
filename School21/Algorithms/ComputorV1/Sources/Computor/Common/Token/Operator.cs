using System;
using System.Linq;

namespace									Computor
{
	public class							Operator : Token
	{
		public static string				AssociatedCharacters => "+-*/^=";
		public static int					LengthLimit => 1;
		
		public enum 						Types
		{
			Undefined,
			Addition,
			Subtraction,
			Multiplication,
			Division,
			Power,
			Equality
		}
		
		public enum							Priorities
		{
			Power,
			MultiplicationAndDivision,
			AdditionAndSubtraction,
			Equality,
			Final
		}

		public readonly Types				Type;
		
		public Priorities					TypePriority => Type.GetPriority();

		public								Operator(string @string) : base(@string)
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
					Error.RaiseInternalError();
					break;
			}
		}

		public bool							IsAnyOf(params Types[] types) => types.Contains(Type);
	}

	public static class						OperatorExtensions
	{
		public static Operator.Priorities	GetPriority(this Operator.Types type) =>
			type switch
			{
				Operator.Types.Addition => Operator.Priorities.AdditionAndSubtraction,
				Operator.Types.Subtraction => Operator.Priorities.AdditionAndSubtraction,
				Operator.Types.Multiplication => Operator.Priorities.MultiplicationAndDivision,
				Operator.Types.Division => Operator.Priorities.MultiplicationAndDivision,
				Operator.Types.Power => Operator.Priorities.Power,
				Operator.Types.Equality => Operator.Priorities.Equality
			};
	}
}