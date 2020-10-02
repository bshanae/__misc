using System;

namespace						Equation
{
	public class				Constant : Operand
	{
		readonly float			Value;

		public					Constant(string @string) : base(@string)
		{
			try
			{
				Value = float.Parse(@string);
			}
			catch (Exception exception)
			{
				throw new Exception($"[Constant, Constant] Can't build instance + {exception}");
			}
		}
		
		public override string	ShortDescription()
		{
			string 				factorString = Factor == 1f ? "" : (Factor + " * ");
			
			return $"[{factorString}{String}]";;
		}

		public override string	LongDescription()
		{
			return $"[Constant : {Value}]";
		}
	}
}