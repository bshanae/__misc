using System;
using System.Collections.Generic;
using System.Linq;

public partial class		Expression
{
	private List<Element>	_Workspace = new List<Element>();
	private List<Group>		_Groups = new List<Group>();
	
	#region Public methods
	
	public					Expression(List<Token> tokens)
	{
		foreach (var token in tokens)
			_Workspace.Add(new ConstantOrVariable(token));
		
		Console.WriteLine("Pass No. 0 : " + this);
		ProcessBrackets();
		Console.WriteLine("Pass No. 1 : " + this);
		ProcessOperators(OperatorType.Power);
		Console.WriteLine("Pass No. 2 : " + this);
		ProcessOperators(OperatorType.Multiplication, OperatorType.Division);
		Console.WriteLine("Pass No. 3 : " + this);
		ProcessOperators(OperatorType.Addition, OperatorType.Subtraction);
		Console.WriteLine("Pass No. 4 : " + this);
		ProcessOperators(OperatorType.Equality);
		Console.WriteLine("Pass No. 5 : " + this);
		
		Error.Assert(_Workspace.Count == 1, "Can't parse expression");
	}
	
	public override string	ToString()
	{
		string				result = "";
		
		for (int i = 0; i < _Workspace.Count; i++)
			result += _Workspace[i] + (i < _Workspace.Count - 1 ? ", " : "");
		return result;
	}
	
	#endregion

	#region					Private methods
	
		private void		ProcessBrackets()
	{
		Bracket				bracket;
		Group				group;
		
		var					groupStack = new Stack<Group>();
		
		for (var i = 0; i < _Workspace.Count;)
		{
			bracket = (_Workspace[i] as ConstantOrVariable)?.Token as Bracket;
			if (bracket == null)
			{
				if (groupStack.Count > 0)
				{
					groupStack.Peek().Children.Add(_Workspace[i]);
					_Workspace.RemoveAt(i);
				}
				else
					i++;
			}
			else switch (bracket.Type)
			{
				case BracketType.Left:
					group = new Group();
					_Workspace.RemoveAt(i);
					
					if (groupStack.Count > 0)
						groupStack.Peek().Children.Add(group);
					else
					{
						_Workspace.Insert(i, group);
						i++;
					}

					groupStack.Push(group);
					_Groups.Add(group);
					break;
				
				case BracketType.Right:
					Error.Assert(groupStack.Count > 0, "Error while processing brackets");

					groupStack.Pop();
					_Workspace.RemoveAt(i);
					break;
				
				default:
					Error.Raise();
					break;
			}
		}

		Error.Assert(groupStack.Count == 0, "Invalid brackets pattern");
	}

	private static void		ProcessOperators(List<Element> elements, params OperatorType[] types)
	{
		Operator[]			@operator = {null, null};
		Operation			operation;
		
		for (var i = 0; i < elements.Count;)
		{
			@operator[0] = (elements[i] as ConstantOrVariable)?.Token as Operator;
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
				@operator[1] = (elements[i] as ConstantOrVariable)?.Token as Operator;
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
		ProcessOperators(_Workspace, types);
		
		foreach (var group in _Groups)
			ProcessOperators(group.Children, types);
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