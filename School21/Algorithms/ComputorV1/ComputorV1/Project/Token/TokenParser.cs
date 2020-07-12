using System;
using System.Linq;

public static class			TokenParser
{
	public static Token		Parse(string source)
	{
		if (IsOperator(source))
			return new Operator(source);
		else if (IsConstant(source))
			return new Constant(source);
		else if (IsVariable(source))
			return new Variable(source);
		else
			return new BadToken(source);		
	}

	private static bool		IsOperator(string input)
	{
		if (input.Length != 1)
			return false;

		switch (input[0])
		{
			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '^' :
			case '=' :
				return true;

			default :
				return false;	
		}
	}

	private static bool		IsConstant(string input)
	{
		foreach (var symbol in input)
			if (!Char.IsDigit(symbol))
				return false;

		return true;		
	}

	private static bool		IsVariable(string input)
	{
		if (input.Length != 1)
			return false;

		return Variable.AvaliableNames.Contains(input[0]);
	}
}