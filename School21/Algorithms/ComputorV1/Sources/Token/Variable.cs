public class				Variable : Token
{
	public static string	AvaliableNames = "x";
	
	public string			Name
	{
		get;
		private set;
	}

	public					Variable(string source) : base(source)
	{
		Name = source.Substring(0, 1);
		if (!AvaliableNames.Contains(Name))
			Error.Raise("Bad name of variable");
	}

	public override string	ShortDescription()
	{
		return String.Substring(0, 1);
	}
	
	public override string	LongDescription()
	{
		return $"Variable : {{string = {String}, name = {Name}}}";
	}
}