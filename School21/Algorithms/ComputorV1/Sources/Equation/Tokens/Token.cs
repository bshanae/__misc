namespace						Equation
{
	public abstract class		Token
	{
		readonly string			String;

		protected				Token(string @string)
		{
			String = @string;
		}

		public override string	ToString()
		{
			return String;
		}
	}
}