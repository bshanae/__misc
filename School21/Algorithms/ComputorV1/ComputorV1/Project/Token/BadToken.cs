class						BadToken : Token
{
	public					BadToken(string source) : base(source)
	{}

	public override string	ShortDescription()
	{
		return $"?";
	}
	
	public override string	LongDescription()
	{
		return $"Bad token : {{string = {String}}}";
	}
}