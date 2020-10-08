namespace						Computor
{
	public static class			Error
	{
		public class			Exception : System.Exception
		{
			public Code			Code
			{
				get;
			}
			
			public				Exception(Code code) : base(code.GetDescription())
			{
				Code = code;
			}
		}
		
		public enum				Code
		{
			ExpressionIsNotGiven,
			InvalidCharacter,
			BadFloat,
			MissingOperator,
			MissingOperand,
			PowerIsNotConstant,
			PowerIsNotInteger,
			MoreThanOneEqualitySign,
			InvalidPower
		}

		public static string	GetDescription(this Code code) =>
			code switch
			{
				Code.ExpressionIsNotGiven => "Expression is not given, pass it as argument to executable",
				Code.InvalidCharacter => "Invalid character in given expression",
				Code.BadFloat => "Invalid floating point number",
				Code.MissingOperator => "Missing operator",
				Code.MissingOperand => "Missing operand",
				Code.PowerIsNotConstant => "Power should be followed by constant",
				Code.PowerIsNotInteger => "Power should be followed by whole number",
				Code.MoreThanOneEqualitySign => "There should be one equality sign",
				Code.InvalidPower => "Invalid degree of equation",
				_ => "Unknown error"
			};
	}
}