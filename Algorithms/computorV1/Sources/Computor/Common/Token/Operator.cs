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
			Undefined,
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
		public static Operator.Priorities	GetPriority(this Operator.Types type)
		{
			switch (type)
			{
				case Operator.Types.Addition:
				case Operator.Types.Subtraction:
					return Operator.Priorities.AdditionAndSubtraction;
				
				case Operator.Types.Multiplication:
				case Operator.Types.Division:
					return Operator.Priorities.MultiplicationAndDivision;
				
				case Operator.Types.Power:
					return Operator.Priorities.Power;
				
				case Operator.Types.Equality:
					return Operator.Priorities.Equality;
				
				default :
					Error.RaiseInternalError();
					return Operator.Priorities.Undefined;
			}
		}
	}
}