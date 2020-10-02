namespace						Equation
{
	public class				Variable : Operand
	{
		public					Variable(string @string) : base(@string)
		{ }
		
		public override string	ShortDescription()
		{
			return String;
		}

		public override string	LongDescription()
		{
			return $"[Variable : {String}]";
		}
	}
}