using System;
using System.Collections.Generic;
using System.Linq;

public partial class		Expression
{
	private List<Element>	_Elements = new List<Element>();

	public Element			Root => _Elements[0];
	
	#region Public methods
	
	public					Expression(List<global::Token> tokens)
	{
		foreach (var token in tokens)
			_Elements.Add(new Token(token));
		
		Console.WriteLine("Pass No. 0 : " + this);
		ProcessUnaryMinus();
		Console.WriteLine("Pass No. 1 : " + this);
		ProcessOperators(OperatorType.Power);
		Console.WriteLine("Pass No. 2 : " + this);
		ProcessOperators(OperatorType.Multiplication, OperatorType.Division);
		Console.WriteLine("Pass No. 3 : " + this);
		ProcessOperators(OperatorType.Addition, OperatorType.Subtraction);
		Console.WriteLine("Pass No. 4 : " + this);
		ProcessOperators(OperatorType.Equality);
		Console.WriteLine("Pass No. 5 : " + this);
		
		Error.Assert(_Elements.Count == 1, "Can't parse expression");
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
	
	private static void		ProcessOperators(List<Element> elements, params OperatorType[] types)
	{
		Operator[]			@operator = {null, null};
		Operation			operation;
		
		for (var i = 0; i < elements.Count;)
		{
			@operator[0] = (elements[i] as Token)?.Value as Operator;
			if (@operator[0] == null || !@operator[0].IsAnyOf(types))
			{
				i++;
				continue ;
			}
	
			ValidateLeft(i);
			
			operation = new Operation(@operator[0].Type);
			operation.Children.Add(elements[i - 1]);
			
			elements.RemoveAt(i - 1);
			i--;
			
			while (i + 1 <= elements.Count)
			{
				@operator[1] = (elements[i] as Token)?.Value as Operator;
				if (@operator[1] == null || @operator[1].Type != @operator[0].Type)
					break ;
				
				ValidateRight(elements, i);
				
				operation.Children.Add(elements[i + 1]);
				elements.RemoveRange(i, 2);
			}
			
			elements.Insert(i, operation);
		}	
	}
		
	private void			ProcessOperators(params OperatorType[] types)
	{
		ProcessOperators(_Elements, types);
	}
	
	private static void		ValidateLeft(int index)
	{
		if (index - 1 < 0)
			Error.Raise("Parsing error");
	}
	
	private static void		ValidateRight(List<Element> list, int index)
	{
		if (index + 1 >= list.Count)
			Error.Raise("Parsing error");
	}

	#endregion
}