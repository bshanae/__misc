namespace						Computor
{
	public class				Variable : Operand
	{
		public static string	AssociatedCharacters => "xX";
		public static int		LengthLimit => 1;
		
		public					Variable(string @string) : base(@string)
		{ }
		
		public override string	ToString()
		{
			string 				factorString = Factor == 1f ? "" : (Factor + " * ");
			
			return $"[{factorString}{String}]";;
		}
	}
}