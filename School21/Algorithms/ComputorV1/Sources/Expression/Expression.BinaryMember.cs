public partial class			Expression
{
	public class				BinaryMember : IMember
	{
		public OperatorType? OperatorType;

		public IMember			LeftChild;
		public IMember			RightChild;

		public					BinaryMember
								(
									OperatorType? operatorType = null,
									IMember left = null,
									IMember right = null
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
			string result = "";

			result += "[";
			result += LeftChild?.ToString();
			result += " " + (OperatorType == null ? "?" : OperatorType?.AsString()) + " ";
			result += RightChild?.ToString();
			result += "]";

			return result;
		}
	}
}