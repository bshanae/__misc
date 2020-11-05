namespace						Computor
{
	public abstract class		Token
	{
		public readonly string	String;

		protected				Token(string @string)
		{
			String = @string;
		}

		public override string	ToString() => String;
	}
}