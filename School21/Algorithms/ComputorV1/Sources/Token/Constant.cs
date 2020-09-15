public class				Constant : Token
{
	public float			Value
	{
		get ;
		private set ;
	}

	public					Constant(string source) : base(source)
	{
		int					result;

		if (int.TryParse(String, out result))
			Value = result;
		else
			Error.Raise("Can't parse constant");
	}
	
	public					Constant(float value) : base(value.ToString())
	{
		Value = value;
	}

	public override string	ShortDescription()
	{
		return $"{Value}";
	}
	
	public override string	LongDescription()
	{
		return $"Constant : {{string = {String}, value = {Value}}}";
	}
}