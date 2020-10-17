using System;

namespace						Computor
{
	public class				Constant : Operand
	{
		public static string	AssociatedCharacters => ".0123456789";
		public static int		LengthLimit => int.MaxValue;

		public readonly float	Value;

		public					Constant(string @string) : base(@string)
		{
			try
			{
				Value = float.Parse(@string);
			}
			catch (Exception exception)
			{
				throw new Exception($"[Constant] Can't build instance + {exception}");
			}
		}

		public override string	ToString()
		{
			string 				factorString = Factor == 1f ? "" : (Factor + " * ");
			
			return $"[{factorString}{Value}]";
		}
	}
}