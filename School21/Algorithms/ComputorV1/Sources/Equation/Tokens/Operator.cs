using System;

namespace						Equation
{
	public class				Operator : Token
	{
		enum 					Types
		{
			Addition,
			Subtraction,
			Multiplication,
			Division,
			Power,
			Equality
		}

		private Types			Type;
		
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
					throw new Exception("[Operator, Operator] Can't build instance");
			}
		}

		public override string	ShortDescription()
		{
			return String;
		}

		public override string	LongDescription()
		{
			return $"[Operator : {Type}]";
		}
	}
}