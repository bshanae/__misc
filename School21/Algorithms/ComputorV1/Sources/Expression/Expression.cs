using System;
using System.Collections.Generic;
using System.Linq;

public partial class		Expression
{
	private List<IMember>	_Workspace = new List<IMember>();
	
	#region Public methods
	
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
		Operator[]			@operator = {null, null};
		BinaryMember		newGroup;
		
		for (var i = 0; i < _Workspace.Count;)
		{
			@operator[0] = (_Workspace[i] as UnaryMember)?.Token as Operator;
			if (@operator[0] == null || !@operator[0].IsAnyOf(types))
			{
				i++;
				continue ;
			}
	
			ValidateLeft(i);
			
			newGroup = new BinaryMember(@operator[0].Type);
			newGroup.Children.Add(_Workspace[i - 1]);
			
			_Workspace.RemoveAt(i - 1);
			i--;
			
			while (i + 1 <= _Workspace.Count)
			{
				@operator[1] = (_Workspace[i] as UnaryMember)?.Token as Operator;
				if (@operator[1] == null || @operator[1].Type != @operator[0].Type)
					break ;
				
				ValidateRight(i);
				
				newGroup.Children.Add(_Workspace[i + 1]);
				_Workspace.RemoveRange(i, 2);
			}
			
			_Workspace.Insert(i, newGroup);
		}
	}
	
	#endregion
	
	#region Private methods
	
	private void			ValidateLeft(int index)
	{
		if (index - 1 < 0)
			Error.Raise("Parsing error");
	}
	
	private void			ValidateRight(int index)
	{
		if (index + 1 >= _Workspace.Count)
			Error.Raise("Parsing error");
	}
	
	#endregion
}