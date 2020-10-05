using System;

namespace						Computor
{
	public class				Constant : Operand
	{
		public readonly float	Value;

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
		
		public override string	ToString()
		{
			string 				factorString = Factor == 1f ? "" : (Factor + " * ");
			
			return $"[{factorString}{Value}]";
		}
	}
}