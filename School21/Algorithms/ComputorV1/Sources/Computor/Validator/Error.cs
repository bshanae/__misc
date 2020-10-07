namespace						Computor
{
	public static class			Error
	{
		public enum				Code
		{
			ExpressionIsNotGiven,
			InvalidCharacter,
			BadFloat
		}

		public static string	GetMessage(Code code) =>
			code switch
			{
				Code.ExpressionIsNotGiven => "Expression is not given, pass it as argument to executable",
				Code.InvalidCharacter => "Invalid character appeared in given expression",
				Code.BadFloat => "Invalid floating point number",
				_ => "Unknown error"
			};
	}
}