public enum 				BracketType
{
	Left,
	Right
}

public static class			BracketTypeExtensions
{
	public static string	AsString(this BracketType type) =>
		type switch
		{
			BracketType.Left => "(",
			BracketType.Right => ")",
			_ => "?"
		};
}

public class				Bracket : Token
{
	public BracketType		Type
	{
		get;
	}
	
	public					Bracket(string source) : base(source)
	{
		Type = source switch
		{
			"(" => BracketType.Left,
			_ => BracketType.Right
		};
	}
	
	public override string	ShortDescription()
	{
		return $"{Type.AsString()}";
	}
	
	public override string	LongDescription()
	{
		return $"Constant : {{string = {String}, type = {Type.AsString()}}}";
	}
}