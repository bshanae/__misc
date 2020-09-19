public partial class			Equation
{
	public class				Operation : Element
	{
		public OperatorType		OperatorType
		{ get; }

		public Element			left;
		public Element			right;
		public					Operation
								(
									OperatorType @operator,
									Element left = null,
									Element right = null
								)
		{
			OperatorType = @operator;
			this.left = left;
			this.right = right;
		}

		public					Operation(Expression.Operation operation)
		{
			OperatorType = operation.OperatorType;
			left = Element.Convert(operation.Left.Clone() as Expression.Element);
			right = Element.Convert(operation.Right.Clone() as Expression.Element);
		}

		public override object	Clone()
		{
			return new Operation(OperatorType, left.Clone() as Element, right.Clone() as Element);
		}

		public override string	ToString()
		{
			return $"[{left} {OperatorType.AsString()} {right}]";
		}
	}
}