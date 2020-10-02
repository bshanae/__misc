namespace						Equation
{
	public class				Variable : Operand
	{
		public					Variable(string @string) : base(@string)
		{ }
		
		public override string	ShortDescription()
		{
			string 				factorString = Factor == 1f ? "" : (Factor + " * ");
			
			return $"[{factorString}{String}]";;
		}
		
		public override string	LongDescription()
		{
			return $"[Variable : {String}]";
		}
	}
}