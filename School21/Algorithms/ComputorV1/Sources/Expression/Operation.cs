public static partial class		Expression
{
	public class				Operation : Element
	{
		public OperatorType		OperatorType
		{ get ; }
		
		public Element			Left
		{ get ; }
		
		public Element			Right
		{ get ; }

		public					Operation
								(
									OperatorType operatorType,
									Element left,
									Element right
								)
		{
			OperatorType = operatorType;
			Left = left;
			Right = right;
		}

		public override object	Clone()
		{
			return new Operation(OperatorType, Left.Clone() as Element, Right.Clone() as Element);
		}

		public override string	ToString()
		{
			return $"[{Left} {OperatorType.AsString()} {Right}]";
		}
	}
}