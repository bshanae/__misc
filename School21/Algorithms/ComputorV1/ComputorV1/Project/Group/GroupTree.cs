using System;
using System.Collections.Generic;
using System.Linq;

public class				GroupTree
{
	private List<IGroup>	_Workspace = new List<IGroup>();

	public BinaryGroup		Root;

	#region Main

	public					GroupTree()
	{}

	public					GroupTree(List<Token> tokens)
	{
		foreach (var token in tokens)
			_Workspace.Add(new UnaryGroup(token));
		
		Console.WriteLine("Zero pass : " + ToString());
		PerformPass(ValidatePower, OperatorType.Power);
		Console.WriteLine("First pass : " + ToString());
		PerformPass(DefaultValidate, OperatorType.Multiplication, OperatorType.Division);
		Console.WriteLine("Second pass : " + ToString());
		PerformPass(DefaultValidate, OperatorType.Addition, OperatorType.Subtraction);
		Console.WriteLine("Third pass : " + ToString());
		PerformPass(DefaultValidate, OperatorType.Equality);
		Console.WriteLine("Fourth pass : " + ToString());
	}
	
	public override string	ToString()
	{
		if (_Workspace.Count != 0)
		{
			string			result = "";

			for (int i = 0; i < _Workspace.Count; i++)
				result += _Workspace[i] + (i < _Workspace.Count - 1 ? ", " : "");
			return result;
		}
		
		return Root.ToString();
	}
	
	#endregion

	#region Parsing
	
	private void			PerformPass(Action<int> validate, params OperatorType[] types)
	{
		Operator			@operator;
		BinaryGroup			newGroup;
		
		for (int i = 0; i < _Workspace.Count; i++)
		{
			@operator = (_Workspace[i] as UnaryGroup)?.Token as Operator;
			if (@operator == null)
				continue;
			if (!@operator.IsAnyOf(types))
				continue;

			validate?.Invoke(i);
			
			newGroup = new BinaryGroup(@operator.Type);
			newGroup.LeftChild = _Workspace[i - 1];
			newGroup.RightChild = _Workspace[i + 1];
			
			_Workspace.RemoveRange(i - 1, 3);
			_Workspace.Insert(i - 1, newGroup);
						
			i = i - 1;
		}
	}
	
	#endregion

	#region Validation

	private void			DefaultValidate(int index)
	{
		if (index - 1 < 0)
			Error.Raise("Parsing error");
		if (index + 1 >= _Workspace.Count)
			Error.Raise("Parsing error");
	}
	
	private void			ValidatePower(int index)
	{
		DefaultValidate(index);

		UnaryGroup			left = _Workspace[index - 1] as UnaryGroup;
		UnaryGroup			right = _Workspace[index + 1] as UnaryGroup;
		
		if (left == null || right == null)
			Error.Raise("Parsing error");
		
		if (!(left.Token is Variable))
			Error.Raise("Parsing error");
		if (!(right.Token is Constant))
			Error.Raise("Parsing error");
	}

	#endregion
}