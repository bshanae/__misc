namespace						Equation
{
	public class				Variable : Operand
	{
		public					Variable(string @string) : base(@string)
		{ }
		
		public override string	LongDescription()
		{
			return $"[Variable : {String}]";
		}
	}
}