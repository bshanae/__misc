public enum					OperatorType
{
	Addition,
	Subtraction,
	Multiplication,
	Division,
	Power,
	Equality
}

public static class			OperatorTypeExtensions
{
	public static string	AsString(this OperatorType type) =>
		type switch
		{
			OperatorType.Addition => "+",
			OperatorType.Subtraction => "-",
			OperatorType.Multiplication => "*",
			OperatorType.Division => "/",
			OperatorType.Power => "^",
			OperatorType.Equality => "=",
			_ => "?"
		};

	public static bool		CanMerge(this OperatorType left, OperatorType right) =>
		left switch
		{
			OperatorType.Multiplication => right == OperatorType.Addition || right == OperatorType.Subtraction,
			OperatorType.Division => right == OperatorType.Addition || right == OperatorType.Subtraction,
			_ => false
		};
}

public class				Operator : Token
{
	public OperatorType		Type
	{
		get ;
		private set ;
	}
	
	public					Operator(string source) : base(source)
	{
		switch (source[0])
		{
			case '+' :
				Type = OperatorType.Addition;
				break ;

			case '-' :
				Type = OperatorType.Subtraction;
				break ;

			case '*' :
				Type = OperatorType.Multiplication;
				break ;

			case '/' :
				Type = OperatorType.Division;
				break ;

			case '^' :
				Type = OperatorType.Power;
				break ;

			case '=' :
				Type = OperatorType.Equality;
				break ;

			default :	
				Error.Raise("Unexpected operator");
				break;
		}
	}

	public bool				IsAnyOf(params OperatorType[] types)
	{
		foreach (var type in types)
			if (Type == type)
				return true;

		return false;
	}

	public override string	ShortDescription()
	{
		return Type.AsString();
	}
	
	public override string	LongDescription()
	{
		return $"Operator : {{string = {String}, type = {Type}}}";
	}
}