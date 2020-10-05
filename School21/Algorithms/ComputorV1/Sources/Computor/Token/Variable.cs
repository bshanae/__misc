namespace						Computor
{
	public class				Variable : Operand
	{
		public					Variable(string @string) : base(@string)
		{ }
		
		public override string	ToString()
		{
			string 				factorString = Factor == 1f ? "" : (Factor + " * ");
			
			return $"[{factorString}{String}]";;
		}
	}
}