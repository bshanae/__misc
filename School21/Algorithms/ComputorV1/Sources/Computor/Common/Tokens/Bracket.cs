using System;

namespace						Computor
{
	public class				Bracket : Token
	{
		public static string	AssociatedCharacters => "()";
		public static int		LengthLimit => 1;

		public enum				Types
		{
			Left,
			Right
		}

		private Types			Type;

		public					Bracket(string @string) : base(@string)
		{
			switch (@string)
			{
				case "(" :
					Type = Types.Left;
					break ;
				
				case ")" :
					Type = Types.Right;
					break ;
				
				default :
					throw new Exception("[Bracket] Unexpected string");
			}
		}
	}
}