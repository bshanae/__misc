using System.Collections.Generic;

public class				GroupList
{
	protected List<Group>	content = new List<Group>();

	public					GroupList(Token[] tokens)
	{
		Operator			lastOperator = null;
		Constant			lastConstant = null;
		Variable			lastVariable = null;

		Operator			currentOperator = null;
	
		for (int i = 0; i < tokens.Length; i++)
		{
			if (tokens[i] is Operator)
			{
				switch ((tokens[i] as Operator).Type)
				{
					case OperatorType.Addition :
					case OperatorType.Subtraction :
						// content.Add(lastVariable, lastConstant);
						break;

					case OperatorType.Multiplication :
					case OperatorType.Division :
						if (lastOperator == null)
							lastOperator = currentOperator;
						else;
						//error
						break;

					case OperatorType.Power :
						break ;	

					default :
						//error
						break;		
				}
			}
			else if (tokens[i] is Constant)
			{
				if (lastConstant == null)
					lastConstant = tokens[i] as Constant;
				else;
				//error	
			}
			else if (tokens[i] is Variable)
			{
				if (lastVariable == null)
					lastVariable = tokens[i] as Variable;
				else;
				//error	
			}
		}
	}
}