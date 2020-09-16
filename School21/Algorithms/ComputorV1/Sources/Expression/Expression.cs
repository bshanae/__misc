using System;
using System.Collections.Generic;
using System.Linq;

public partial class		Expression
{
	private List<IElement>	_Elements = new List<IElement>();
	private List<Group>		_Groups = new List<Group>();

	public IElement			Root => _Elements[0];
	
	#region Public methods
	
	public					Expression(List<global::Token> tokens)
	{
		foreach (var token in tokens)
			_Elements.Add(new Token(token));
		
		Console.WriteLine("Pass No. 0 : " + this);
		ProcessUnaryMinus();
		Console.WriteLine("Pass No. 1 : " + this);
		ProcessBrackets();
		Console.WriteLine("Pass No. 2 : " + this);
		ProcessOperators(OperatorType.Power);
		Console.WriteLine("Pass No. 3 : " + this);
		ProcessOperators(OperatorType.Multiplication, OperatorType.Division);
		Console.WriteLine("Pass No. 4 : " + this);
		ProcessOperators(OperatorType.Addition, OperatorType.Subtraction);
		Console.WriteLine("Pass No. 5 : " + this);
		ProcessOperators(OperatorType.Equality);
		Console.WriteLine("Pass No. 6 : " + this);
		Reduce();
		Console.WriteLine("Pass No. 7 : " + this);
		
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
		bool?				previousIsContantOrVariable = null;

		for (int i = 0; i < _Elements.Count; i++)
			if (_Elements[i] is Token token)
			{
				if
				(
					token.Value is Operator @operator
					&& @operator.Type == OperatorType.Subtraction
					&& !previousIsContantOrVariable.GetValueOrDefault(true)
				)
				{
					_Elements.Insert(i, new Token(new Constant("0")));
					previousIsContantOrVariable = true;
					i++;
				}
				else
					previousIsContantOrVariable = token.Value is Constant || token.Value is Operator;
			}
	}
	
	private void			ProcessBrackets()
	{
		Bracket				bracket;
		Group				group;
		
		var					groupStack = new Stack<Group>();
		
		for (var i = 0; i < _Elements.Count;)
		{
			bracket = (_Elements[i] as Token)?.Value as Bracket;
			if (bracket == null)
			{
				if (groupStack.Count > 0)
				{
					groupStack.Peek().Children.Add(_Elements[i]);
					_Elements.RemoveAt(i);
				}
				else
					i++;
			}
			else switch (bracket.Type)
			{
				case BracketType.Left:
					group = new Group();
					_Elements.RemoveAt(i);
					
					if (groupStack.Count > 0)
						groupStack.Peek().Children.Add(group);
					else
					{
						_Elements.Insert(i, group);
						i++;
					}

					groupStack.Push(group);
					_Groups.Add(group);
					break;
				
				case BracketType.Right:
					Error.Assert(groupStack.Count > 0, "Error while processing brackets");

					groupStack.Pop();
					_Elements.RemoveAt(i);
					break;
				
				default:
					Error.Raise();
					break;
			}
		}

		Error.Assert(groupStack.Count == 0, "Invalid brackets pattern");
	}

	private static void		ProcessOperators(List<IElement> elements, params OperatorType[] types)
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
		
		foreach (var group in _Groups)
			ProcessOperators(group.Children, types);
	}
	
	private static void		ValidateLeft(int index)
	{
		if (index - 1 < 0)
			Error.Raise("Parsing error");
	}
	
	private static void		ValidateRight(List<IElement> list, int index)
	{
		if (index + 1 >= list.Count)
			Error.Raise("Parsing error");
	}

	private void			Reduce()
	{
		for (int i = 0; i < _Elements.Count; i++)
			_Elements[i] = Reduce(_Elements[i]);
	}

	private static IElement	Reduce(IElement element)
	{
		if (!(element is IComplexElement))
			return element;
		
		var					complexElement = element as IComplexElement;
		
		for (int i = 0; i < complexElement.Children.Count; i++)
			if (complexElement.Children[i] is IComplexElement)
				complexElement.Children[i] = Reduce(complexElement.Children[i]);

		if (complexElement is Operation operation && operation.OperatorType.CanCalculate())
		{
			Token		target = null;
			
			for (int i = 0; i < operation.Children.Count; i++)
				if(operation.Children[i] is Token token && token.Value is Constant constant)
				{
					if (target == null)
						target = token;
					else
					{
						target.Value = operation.OperatorType.Calculate(target.Value as Constant, constant);
						operation.Children.RemoveAt(i--);
					}
				}
		}

		return complexElement.Children.Count == 1 ? complexElement.Children[0] : element;
	}

	#endregion
}