using System;
using System.Collections.Generic;
using System.Linq;

public class				GroupTree
{
	private List<IGroup>	_Workspace = new List<IGroup>();
	
	#region Main

	public					GroupTree()
	{}

	public					GroupTree(List<Token> tokens)
	{
		foreach (var token in tokens)
			_Workspace.Add(new UnaryGroup(token));
		
		Console.WriteLine("Pass No. 0 : " + this);
		PerformPass(OperatorType.Power);
		Console.WriteLine("Pass No. 1 : " + this);
		PerformPass(OperatorType.Multiplication, OperatorType.Division);
		Console.WriteLine("Pass No. 2 : " + this);
		PerformPass(OperatorType.Addition, OperatorType.Subtraction);
		Console.WriteLine("Pass No. 3 : " + this);
		PerformPass(OperatorType.Equality);
		Console.WriteLine("Pass No. 4 : " + this);
	}
	
	public override string	ToString()
	{
		string				result = "";
		
		for (int i = 0; i < _Workspace.Count; i++)
			result += _Workspace[i] + (i < _Workspace.Count - 1 ? ", " : "");
		return result;
	}
	
	#endregion

	#region Parsing
	
	private void			PerformPass(params OperatorType[] types)
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

			Validate(i);
			
			newGroup = new BinaryGroup(@operator.Type);
			newGroup.LeftChild = _Workspace[i - 1];
			newGroup.RightChild = _Workspace[i + 1];
			
			_Workspace.RemoveRange(i - 1, 3);
			_Workspace.Insert(i - 1, newGroup);
						
			i -= 1;
		}
	}
	
	#endregion

	#region Validation

	private void			Validate(int index)
	{
		if (index - 1 < 0)
			Error.Raise("Parsing error");
		if (index + 1 >= _Workspace.Count)
			Error.Raise("Parsing error");
	}

	#endregion
}