public class				Variable : Token
{
	public static string	AvaliableNames = "x";

	public float?			Value;

	public					Variable(string source) : base(source)
	{}

	public override string	ToString()
	{
		return $"Variable : {{string = {String}, value = {Value}}}";
	}
}