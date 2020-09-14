using System;
using System.Collections.Generic;
using System.Linq;

public partial class		Expression
{
	private List<IMember>	_Workspace = new List<IMember>();
	
	#region Main
	
	public					Expression()
	{}
	
	public					Expression(List<Token> tokens)
	{
		foreach (var token in tokens)
			_Workspace.Add(new UnaryMember(token));
		
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
		BinaryMember		newGroup;
		
		for (int i = 0; i < _Workspace.Count; i++)
		{
			@operator = (_Workspace[i] as UnaryMember)?.Token as Operator;
			if (@operator == null)
				continue;
			if (!@operator.IsAnyOf(types))
				continue;
	
			Validate(i);
			
			newGroup = new BinaryMember(@operator.Type);
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