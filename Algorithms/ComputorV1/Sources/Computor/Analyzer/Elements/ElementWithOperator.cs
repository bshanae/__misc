namespace									Computor
{
	public class							ElementWithOperator : Element
	{
		public readonly Operator			Operator;

		public								ElementWithOperator(Operator @operator)
		{
			Operator = @operator;
		}

		public override string				ToString()
		{
			return "[" + Operator + "]";
		}
	}
}