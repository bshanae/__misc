using System;
using System.Collections.Generic;

public class				GroupTree
{
	public List<Group>		LeftList
	{
		get;
		private set; 
	}
	
	public List<Group>		RightList
	{
		get;
		private set; 
	}

	private List<Group>		currentList;

	private Token[]			tokens;
	private int				tokenIndex;

	private Constant		lastConstant;
	private Variable		lastVariable;

	private float?			factorForGroup = null;
	private float?			powerForGroup = null;

	private Group			newGroup;

	private Token			PreviousToken => tokenIndex - 1 >= 0 ? tokens[tokenIndex - 1] : null;
	private Token			CurrentToken => tokens[tokenIndex];
	private Token			NextToken => tokenIndex + 1 < tokens.Length ? tokens[tokenIndex + 1] : null;
	
	public					GroupTree(Token[] tokens)
	{
		LeftList = new List<Group>();
		RightList = new List<Group>();
		
		this.tokens = tokens;
		currentList = LeftList;

		for (tokenIndex = 0; tokenIndex < tokens.Length; tokenIndex++)
		{
			if (CurrentToken is Operator)
				ProcessOperator();
			else if (CurrentToken is Constant)
				ProcessConstant();
			else if (CurrentToken is Variable)
				ProcessVariable();
			else
				Error.Raise("Unexpected token");
		}
		
		BuildGroup();
	}

	public override string	ToString()
	{
		string				result = "GroupTree : \n";

		foreach (var group in LeftList)
			result += group + "\n";
		result += "\n";
		foreach (var group in RightList)
			result += group + "\n";

		return result;
	}

	private void			ProcessOperator()
	{
		switch ((tokens[tokenIndex] as Operator).Type)
		{
			case OperatorType.Addition :
			case OperatorType.Subtraction :
				BuildGroup();
				break;

			case OperatorType.Multiplication :
			case OperatorType.Division :
				
				float		modifier = 1f;

				if ((tokens[tokenIndex] as Operator).Type == OperatorType.Division)
					modifier = 0.1f;
				
				if (PreviousToken is Constant)
				{
					if (NextToken is Variable)
						factorForGroup = ((PreviousToken as Constant).Value ?? 1f) * modifier;
					else
						Error.Raise("Bad multiplication/division pattern");
				}
				else if (PreviousToken is Variable)
				{
					if (NextToken is Constant)
						factorForGroup = ((NextToken as Constant).Value ?? 1f) * modifier;
					else
						Error.Raise("Bad multiplication/division pattern");
				}
				else
					Error.Raise("Bad multiplication/division pattern");
				break;

			case OperatorType.Power :
				if (!(PreviousToken is Variable))
					Error.Raise("Bad power pattern");
				else if (!(NextToken is Constant))
					Error.Raise("Bad power pattern");
				else
				{
					powerForGroup = (NextToken as Constant).Value ?? 1f;
					
				}
				break;

			case OperatorType.Equality :
				currentList = RightList;
				break;
			
			default :
				Error.Raise("Unexpected operator type");
				break;
		}
	}

	private void			ProcessConstant()
	{
		lastConstant = CurrentToken as Constant;
	}
	
	private void			ProcessVariable()
	{
		if (lastVariable != null)
			Error.Raise("Unexpected variable");
		lastVariable = CurrentToken as Variable;
	}

	private void			BuildGroup()
	{
		float				factor = factorForGroup ?? 0f;
		float				power = powerForGroup ?? 0f;
		
		if (lastConstant != null)
			factor = lastConstant.Value ?? 1f;
		if (lastVariable != null && factorForGroup == null)
			factor = 1f;
		if (lastVariable == null && powerForGroup == null)
			power = 1f; 
		
		newGroup = new Group(factor, power);
		currentList.Add(newGroup);
		
		lastConstant = null;
		lastVariable = null;
		
		factorForGroup = null;
		powerForGroup = null;
	}
}