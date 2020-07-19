public abstract class		Token : IDescribable
{
	public string			String
	{
		get ;
		private set ;
	}

	public					Token(string source)
	{
		String = source;
	}

	public override string	ToString()
	{
		return LongDescription();
	}

	public virtual string	ShortDescription()
	{
		return "";
	}
	
	public virtual string	LongDescription()
	{
		return "";
	}
}
