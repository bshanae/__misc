using System.Linq;
using System.Collections.Generic;
public partial class			Equation
{
	public class				Operation : Element
	{
		public List<Element>	Children = new List<Element>();

		public OperatorType		OperatorType
		{ get; }

		public					Operation(OperatorType @operator)
		{
			OperatorType = @operator;
		}

		public					Operation(Expression.Operation operation)
		{
			OperatorType = operation.OperatorType;
			Children = operation.Children.Select(Element.Convert).ToList();
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