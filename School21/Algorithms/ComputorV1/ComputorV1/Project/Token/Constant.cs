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
		{
//			error
		}
	}

	public override string	ToString()
	{
		return $"Constant : {{string = {String}, value = {Value}}}";
	}
}