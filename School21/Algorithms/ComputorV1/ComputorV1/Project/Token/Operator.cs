public enum					OperatorType
{
	Addition,
	Subtraction,
	Multiplication,
	Division,
	Power,
	Equality
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
				break ;
			//error	
		}
	}

	public override string	ToString()
	{
		return $"Operator : {{string = {String}, type = {Type}}}";
	}
}