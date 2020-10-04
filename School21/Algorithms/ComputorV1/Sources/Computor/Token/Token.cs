namespace						Computor
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

		public virtual string	ShortDescription()
		{
			return $"[{String}]";
		}
		
		public abstract string	LongDescription();
	}
}