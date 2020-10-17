namespace						Computor
{
	public static class			Error
	{
		public class			Exception : System.Exception
		{
			public Codes			Code
			{
				get;
			}
			
			public				Exception(Codes code) : base(code.GetDescription())
			{
				Code = code;
			}
		}
		
		public enum				Codes
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

		public static string	GetDescription(this Codes code) =>
			code switch
			{
				Codes.ExpressionIsNotGiven => "Expression is not given, pass it as argument to executable",
				Codes.InvalidCharacter => "Invalid character in given expression",
				Codes.BadFloat => "Invalid floating point number",
				Codes.MissingOperator => "Missing operator",
				Codes.MissingOperand => "Missing operand",
				Codes.PowerIsNotConstant => "Power should be followed by constant",
				Codes.PowerIsNotInteger => "Power should be followed by whole number",
				Codes.MoreThanOneEqualitySign => "There should be one equality sign",
				Codes.InvalidPower => "Invalid degree of equation",
				_ => "Unknown error"
			};
	}
}