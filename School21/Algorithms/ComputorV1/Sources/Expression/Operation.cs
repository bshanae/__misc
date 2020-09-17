public partial class			Expression
{
	public class				Operation : IComplexElement
	{
		public OperatorType		OperatorType
		{ get ; }

		public					Operation(OperatorType operatorType)
		{
			OperatorType = operatorType;
		}

		public override string	ToString()
		{
			string result = "";

			result += "[";
			
			for (var i = 0; i < Children.Count; i++) 
			{
				result += Children[i];
				if (i < Children.Count - 1)
					result += " " + OperatorType.AsString() + " ";
			}
			
			result += "]";

			return result;
		}
	}
}