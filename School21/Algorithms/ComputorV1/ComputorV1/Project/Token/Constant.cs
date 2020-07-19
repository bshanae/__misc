public class				Constant : Token
{
	public float?			Value
	{
		get ;
		private set ;
	}

	public					Constant(string source) : base(source)
	{
		bool				success;
		int					result;

		success = int.TryParse(String, out result);
		if (success)
			Value = result;
		else
			Error.Raise("Can't parse constant");
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