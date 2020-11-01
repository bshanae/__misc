using System;

public static class					Error
{
	#region Nested classes

	public class					UsageException : Exception
	{
		public readonly UsageErrors Error;

		public						UsageException(UsageErrors usageError)
		{
			Error = usageError;
		}
	}

	public class					InternalException : Exception { }

	public class					InternalAssertionException : Exception { }


	public enum						UsageErrors
	{
		InvalidCommandLineArguments,
		EmptyExpression,
		InvalidCharacter,
		BadFloat,
		MissingOperator,
		MissingOperand,
		PowerIsNotConstant,
		PowerIsNotInteger,
		MoreThanOneEqualitySign,
		InvalidPower
	}

	public class					Reaction
	{
		#region Constants

		private const string		InternalErrorMessage = "Computor internal error";
		private const string		InternalAssertionErrorMessage = "Computor internal assertion fail";
		private const string		UsageErrorMessage = "Computor usage error";
		private const string		UnknownErrorMessage = "Computor unknown error";
		
		#endregion
		
		#region Fields

		private readonly Action		_action;
		
		#endregion

		#region Factory methods
		
		private						Reaction(string message)
		{
			_action = () => Console.WriteLine(message);
		}

		public static Reaction		PrintInternalError(string error)
		{
			return new Reaction(AppendColonAndMessageIfNeeded(InternalErrorMessage, error));
		}
		
		public static Reaction		PrintInternalAssertionError(string error)
		{
			return new Reaction(AppendColonAndMessageIfNeeded(InternalAssertionErrorMessage, error));
		}

		public static Reaction		PrintUsageError(string error = null)
		{
			return new Reaction(AppendColonAndMessage(UsageErrorMessage, error));
		}

		public static Reaction		PrintUnknownError(string error = null)
		{
			return new Reaction(AppendColonAndMessageIfNeeded(UnknownErrorMessage, error));
		}

		public static Reaction		PrintMessage(string message)
		{
			return new Reaction(message);
		}
		
		#endregion

		#region Public methods
		
		public void					Invoke()
		{
			_action.Invoke();
		}
		
		#endregion
		
		#region Private methods

		private static string		AppendColonAndMessage(string body, string message)
		{
			return body + " : " + message;
		}
		
		private static string		AppendColonAndMessageIfNeeded(string body, string message)
		{
			return Program.Options.Debug && message != null ? AppendColonAndMessage(body, message) : body;
		}
		
		#endregion
	}

	#endregion

	#region Attributes

	private static string			UsageDescription =>
		"Format : " + Environment.NewLine +
		"	./ComputorV1 [expression] (options)" + Environment.NewLine +
		Environment.NewLine +
		"Example : " + Environment.NewLine +
		"	./ComputorV1 \"x ^ 2 + x - 1 = 4\" --report --treeview" + Environment.NewLine +
		Environment.NewLine +
		"Options : " + Environment.NewLine +
		"	--report    :  Info about internal computations" + Environment.NewLine +
		"	--treeview  :  Print token groups vertically (Only in report mode)";

	#endregion
	
	#region GetReaction

	public static Reaction			GetReaction(this Exception exception)
	{
		switch (exception)
		{
			case InternalException _ :
				return Reaction.PrintInternalError(exception.Message);
			
			case InternalAssertionException _ :
				return Reaction.PrintInternalAssertionError(exception.Message);

			case UsageException usageException :
				return usageException.Error switch
				{
					UsageErrors.InvalidCommandLineArguments => Reaction.PrintMessage(UsageDescription),
					UsageErrors.EmptyExpression => Reaction.PrintUsageError("Given expression is empty"),
					UsageErrors.InvalidCharacter => Reaction.PrintUsageError("Invalid character in given expression"),
					UsageErrors.BadFloat => Reaction.PrintUsageError("Invalid floating point number"),
					UsageErrors.MissingOperator => Reaction.PrintUsageError("Missing operator"),
					UsageErrors.MissingOperand => Reaction.PrintUsageError("Missing operand"),
					UsageErrors.PowerIsNotConstant => Reaction.PrintUsageError("Power should be followed by constant"),
					UsageErrors.PowerIsNotInteger => Reaction.PrintUsageError("Power should be followed by whole number"),
					UsageErrors.MoreThanOneEqualitySign => Reaction.PrintUsageError("There should be one equality sign"),
					UsageErrors.InvalidPower => Reaction.PrintUsageError("Invalid degree of equation"),
					_ => Reaction.PrintUsageError()
				};
			
			default :
				return Reaction.PrintUnknownError(exception.Message);
		}
	}

	
	#endregion
	
	#region Raise, Assert methods

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
	
	#endregion
}