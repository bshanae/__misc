
public class				BinaryGroup : IGroup
{
	public OperatorType?	OperatorType;
	
	public IGroup			LeftChild;
	public IGroup			RightChild;

	public					BinaryGroup
							(
								OperatorType? operatorType = null,
								IGroup left = null,
								IGroup right = null
							)
	{
		OperatorType = operatorType;
		LeftChild = left;
		RightChild = right;
	}

	public bool				HaveChildren()
	{
		return LeftChild != null || RightChild != null;
	}
	
	public override string	ToString()
	{
		string				result = "";

		result += "[";
		result += LeftChild?.ToString();
		result += " " + (OperatorType == null ? "?" : OperatorType?.AsString()) + " ";
		result += RightChild?.ToString();
		result += "]";
		
		return result;
	}
}