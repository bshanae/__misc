using System;

public static class					Error
{
	public class					UsageException : Exception
	{
		public readonly UsageErrors	Error;
		
		public						UsageException(UsageErrors usageError) : base(usageError.GetDescription())
		{
			Error = usageError;
		}
	}
	
	public class					InternalException : Exception { }
	
	public class					InternalAssertionException : Exception { }

	
	public enum						UsageErrors
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

	private static string			GetDescription(this UsageErrors usageError) =>
		usageError switch
		{
			UsageErrors.ExpressionIsNotGiven => "Expression is not given, pass it as argument to executable",
			UsageErrors.InvalidCharacter => "Invalid character in given expression",
			UsageErrors.BadFloat => "Invalid floating point number",
			UsageErrors.MissingOperator => "Missing operator",
			UsageErrors.MissingOperand => "Missing operand",
			UsageErrors.PowerIsNotConstant => "Power should be followed by constant",
			UsageErrors.PowerIsNotInteger => "Power should be followed by whole number",
			UsageErrors.MoreThanOneEqualitySign => "There should be one equality sign",
			UsageErrors.InvalidPower => "Invalid degree of equation",
			_ => "Unknown error"
		};

	public static void				RaiseUsageError(UsageErrors error)
	{
		throw new UsageException(error);
	}
	
	public static void				RaiseInternalError()
	{
		throw new InternalException();
	}
	
	public static void				Assert(bool condition)
	{
		if (!condition)
			throw new InternalAssertionException();
	}
}