using System.Collections.Generic;

public partial class			Expression
{
	public class				Operation : Element
	{
		public List<Element>	Children = new List<Element>();
		
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