using System;
using System.Collections.Generic;

public partial class			Equation
{
	public class				Operation : Element
	{
		public List<Element>	Children = new List<Element>();
		
		public Operation		Parent
		{ get; }

		public OperatorType		Operator
		{ get; }

								Operation(Operation parent, OperatorType @operator)
		{
			Parent = parent;
			Operator = @operator;
		}
	}
}