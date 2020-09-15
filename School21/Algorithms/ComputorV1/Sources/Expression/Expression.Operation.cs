using System.Collections.Generic;

public partial class			Expression
{
	public class				Operation : Element
	{
		public List<Element>	Children;

		public OperatorType		OperatorType
		{
			get ;
			private set ;
		}

		public					Operation(OperatorType operatorType)
		{
			OperatorType = operatorType;
			Children = new List<Element>();
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