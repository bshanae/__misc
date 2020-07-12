class						BadToken : Token
{
	public					BadToken(string source) : base(source)
	{

	}

	public override string	ToString()
	{
		return $"Bad token : {{string = {String}}}";
	}
}