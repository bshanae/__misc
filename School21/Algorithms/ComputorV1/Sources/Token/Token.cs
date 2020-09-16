using System;
using System.Linq;

public abstract class		Token : Describable
{
	public string			String
	{ get ; }
	
	#region					Public method
	public static Token		Parse(string source)
	{
		if (IsOperator(source))
			return new Operator(source);
		if (IsConstant(source))
			return new Constant(source);
		if (IsVariable(source))
			return new Variable(source);
		if (IsBracket(source))
			return new Bracket(source);
		return new BadToken(source);		
	}
	
	public override string	ToString()
	{
		return LongDescription();
	}

	public virtual string	ShortDescription()
	{
		return "";
	}
	
	public virtual string	LongDescription()
	{
		return "";
	}
	
	#endregion
	
	#region					Protected method
	
	protected				Token(string source)
	{
		String = source;
	}
	
	#endregion
	
	#region					Private methods

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

	private static bool		IsBracket(string input) =>
		input[0] switch
		{
			'(' => true,
			')' => true,
			_ => false
		};

	#endregion
}
