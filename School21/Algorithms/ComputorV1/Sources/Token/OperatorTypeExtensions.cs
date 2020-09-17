using System;
using System.Linq;

public static partial class	OperatorTypeExtensions
{
	public static bool		IsAnyOf(this OperatorType type, params OperatorType[] types)
	{
		return types.Any(item => item == type);
	}
		
	public static string	AsString(this OperatorType type) =>
		type switch
		{
			OperatorType.Addition => "+",
			OperatorType.Subtraction => "-",
			OperatorType.Multiplication => "*",
			OperatorType.Division => "/",
			OperatorType.Power => "^",
			OperatorType.Equality => "=",
			_ => "?"
		};

	public static bool		CanCalculate(this OperatorType type) =>
		type switch
		{
			OperatorType.Addition => true,
			OperatorType.Subtraction => true,
			OperatorType.Multiplication => true,
			OperatorType.Division => true,
			OperatorType.Power => true,
			_ => false
		};
}