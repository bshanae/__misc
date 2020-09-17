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

	public bool				IsAnyOf(params OperatorType[] types) => Type.IsAnyOf(types);

	public override string	ShortDescription()
	{
		return Type.AsString();
	}
	
	public override string	LongDescription()
	{
		return $"Operator : {{string = {String}, type = {Type}}}";
	}
}