using System;
using System.Collections.Generic;

public static partial class			Expression
{
	private static List<Element>	_Elements = new List<Element>();

	public static Element			Root => _Elements[0];
	
	#region Public methods
	
	public static void				Build(List<global::Token> tokens)
	{
		foreach (var token in tokens)
			_Elements.Add(new Token(token));
		
		Printer.PrintLineIfVerbose("Expression :");
		Print();
		Printer.PrintLineIfVerbose();
		
		ProcessUnaryMinus();
		Printer.PrintLineIfVerbose("Processed unary minuses :");
		Print();
		Printer.PrintLineIfVerbose();
		
		ProcessOperators(OperatorType.Power);
		Printer.PrintLineIfVerbose("Processed powers :");
		Print();
		Printer.PrintLineIfVerbose();
		
		ProcessOperators(OperatorType.Multiplication, OperatorType.Division);
		Printer.PrintLineIfVerbose("Processed multiplication and division :");
		Print();
		Printer.PrintLineIfVerbose();
		
		ProcessOperators(OperatorType.Addition, OperatorType.Subtraction);
		Printer.PrintLineIfVerbose("Processed addition and subtraction :");
		Print();
		Printer.PrintLineIfVerbose();
		
		ProcessOperators(OperatorType.Equality);
		Printer.PrintLineIfVerbose("Processed equality :");
		Print();
		Printer.PrintLineIfVerbose();
		
		Error.Assert(_Elements.Count == 1, "Invalid expression");
	}
	
	public static void					Print()
	{
		string							result = "";
		
		for (int i = 0; i < _Elements.Count; i++)
			result += _Elements[i] + (i < _Elements.Count - 1 ? ", " : "");
		
		Printer.PrintLineIfVerbose(result);
	}
	
	#endregion

	#region								Private methods

	private static void					ProcessUnaryMinus()
	{
		bool?							isPreviousConstantOrVariable = null;

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
					isPreviousConstantOrVariable = token.Value is Constant || token.Value is Variable;
			}
	}
	
	private static void					ProcessOperators(params OperatorType[] types)
	{
		Operator						@operator;
		Operation						operation;
		
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

	private static void					Validate(int index)
	{
		if (index - 1 < 0)
			Error.Raise("Parsing error");
		if (index + 1 >= _Elements.Count)
			Error.Raise("Parsing error");
	}
	
	#endregion
}