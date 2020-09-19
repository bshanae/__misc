using System;
using System.Collections.Generic;

public partial class		Expression
{
	private List<Element>	_Elements = new List<Element>();

	public Element			Root => _Elements[0];
	
	#region Public methods
	
	public					Expression(List<global::Token> tokens)
	{
		foreach (var token in tokens)
			_Elements.Add(new Token(token));
		
		Console.WriteLine("Expression :");
		Console.WriteLine(this);
		Console.WriteLine();
		
		// ProcessUnaryMinus();
		// Console.WriteLine("Processed unary minuses :");
		// Console.WriteLine(this);
		// Console.WriteLine();
		
		ProcessOperators(OperatorType.Power);
		Console.WriteLine("Processed powers :");
		Console.WriteLine(this);
		Console.WriteLine();
		
		ProcessOperators(OperatorType.Multiplication, OperatorType.Division);
		Console.WriteLine("Processed multiplication and division :");
		Console.WriteLine(this);
		Console.WriteLine();
		
		ProcessOperators(OperatorType.Addition, OperatorType.Subtraction);
		Console.WriteLine("Processed addition and subtraction :");
		Console.WriteLine(this);
		Console.WriteLine();
		
		ProcessOperators(OperatorType.Equality);
		Console.WriteLine("Processed equality :");
		Console.WriteLine(this);
		Console.WriteLine();
		
		Error.Assert(_Elements.Count == 1, "Invalid expression");
	}
	
	public override string	ToString()
	{
		string				result = "";
		
		for (int i = 0; i < _Elements.Count; i++)
			result += _Elements[i] + (i < _Elements.Count - 1 ? ", " : "");
		return result;
	}
	
	#endregion

	#region					Private methods

	private void			ProcessUnaryMinus()
	{
		bool?				isPreviousConstantOrVariable = null;

		for (int i = 0; i < _Elements.Count; i++)
			if (_Elements[i] is Token token)
			{
				if
				(
					token.Value is Operator @operator
					&& @operator.Type == OperatorType.Subtraction
					&& !isPreviousConstantOrVariable.GetValueOrDefault(true)
				)
				{
					_Elements.Insert(i, new Token(new Constant("0")));
					isPreviousConstantOrVariable = true;
					i++;
				}
				else
					isPreviousConstantOrVariable = token.Value is Constant || token.Value is Operator;
			}
	}
	
	private void			ProcessOperators(params OperatorType[] types)
	{
		Operator			@operator;
		Operation			operation;
		
		for (var i = 0; i < _Elements.Count; i++)
		{
			@operator = (_Elements[i] as Token)?.Value as Operator;
			if (@operator == null || !@operator.IsAnyOf(types))
				continue ;
	
			Validate(i);
			
			operation = new Operation(@operator.Type, _Elements[i - 1], _Elements[i + 1]);
			_Elements.RemoveRange(i - 1, 3);
			_Elements.Insert(i - 1, operation);

			i--;
		}
	}

	private void			Validate(int index)
	{
		if (index - 1 < 0)
			Error.Raise("Parsing error");
		if (index + 1 >= _Elements.Count)
			Error.Raise("Parsing error");
	}
	
	#endregion
}