namespace						Equation
{
	public abstract class		Token : Describable
	{
		public readonly string	String;

		protected				Token(string @string)
		{
			String = @string;
		}

		public override string	ToString()
		{
			return ShortDescription();
		}

		public abstract string	ShortDescription();
		public abstract string	LongDescription();
	}
}