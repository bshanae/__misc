using System;
using System.Collections.Generic;
using System.IO;
using Computor;
using NUnit.Framework;

[TestFixture]  
public static class			Tester
{
	#region					Fields

	private static string	_output;
	
	#endregion

	[SetUp]
	public static void		RestoreWorkspace()
	{
		Workspace.Expression = null;
		Workspace.Tokens = new List<Token>();
		Workspace.Terms = new List<Term>();
		Workspace.SortedTerms = new Dictionary<int, Term>();
		Workspace.EquationRoots = new List<Math.Fraction>();
		Workspace.AreRootsInfinite = false;

		_output = null;
	}

	[TestCase("2 * x ^ 2 - 4 * x - 2 = 0", "-0.414214, 2.414214")]
	[TestCase("6 * x ^ 2 + 11 * x - 35 = 0", "-7 / 2, 5 / 3")]
	[TestCase("-4 * x ^ 2 - 7 * x + 12 = 0", "-2.815522, 1.065522")]
	[TestCase("20 * x ^ 2 -15 * x - 10 = 0", "-0.425391, 1.175390")]
	[TestCase("x ^ 2 - x - 3 = 0", "-1.302776, 2.302776")]
	[TestCase("5 * x ^ 2 - 2 * x - 9 = 0", "-1.156466, 1.556466")]
	[TestCase("3 * x ^ 2 + 4 * x + 2 = 0", "")]
	[TestCase("-x ^ 2 + 6 * x + 18 = 0", "-2.196153, 8.196153")]
	[TestCase("x + x ^ 2 + x * x ^ 1 = 0", "-0.5, 0")]
	[TestCase("x ^ 1 * x = 0", "0")]
	[TestCase("x ^ 2 / 2 / 2 = 0", "0")]
	[TestCase("2x^2 + 4x - 2 = 0", "-2.414214, 0.414214")]
	[TestCase("x * x = 0", "0")]
	public static void		ValidCases(string input, string expected)
	{
		RunProgram(input);
		Assert.AreEqual(expected, _output);
	}


	[TestCase("-x ^ 2 = -4", "-2, 2")]
	[TestCase("x = 5", "5")]
	[TestCase("x * x = 5", "-2.236066, 2.236066")]
	[TestCase("2 * x = 7", "7 / 2")] 
	public static void		IncompleteFormCases(string input, string expected)
	{
		RunProgram(input);
		Assert.AreEqual(expected, _output);
	}
	
	[TestCase("0 = 4", "")]
	[TestCase("4 = 4", "Any")]
	[TestCase("x = x", "Any")]
	public static void		SpecialCases(string input, string expected)
	{
		RunProgram(input);
		Assert.AreEqual(expected, _output);
	}

	[TestCase(null, Error.Code.ExpressionIsNotGiven)]
	
	[TestCase("ajnakak", Error.Code.InvalidCharacter)]
	[TestCase("y = 0", Error.Code.InvalidCharacter)]

	[TestCase("x = 1.3.3.3", Error.Code.BadFloat)]
	[TestCase("x = ..0101", Error.Code.BadFloat)]
	
	[TestCase("xx = 0", Error.Code.MissingOperator)]
	[TestCase("xxxxx = 0", Error.Code.MissingOperator)]
	[TestCase("x3 = 0", Error.Code.MissingOperator)]
	[TestCase("+2 = 0", Error.Code.MissingOperator)]
	[TestCase("*1 = 0", Error.Code.MissingOperator)]
	[TestCase("^8 = 0", Error.Code.MissingOperator)]
	
	[TestCase("x++ = 0", Error.Code.MissingOperand)]
	[TestCase("1-+2 = 0", Error.Code.MissingOperand)]
	[TestCase("1---2 = 0", Error.Code.MissingOperand)]
	
	[TestCase("x^x = 0", Error.Code.PowerIsNotConstant)]
	[TestCase("2^x = 0", Error.Code.PowerIsNotConstant)]
	
	[TestCase("x^1.1 = 0", Error.Code.PowerIsNotInteger)]
	[TestCase("x^.11 * x^1.2 = 0", Error.Code.PowerIsNotInteger)]

	[TestCase("1 = 0 = 1", Error.Code.MoreThanOneEqualitySign)]
	[TestCase("1 = 0 = 1 = x", Error.Code.MoreThanOneEqualitySign)]
	
	[TestCase(" = ", Error.Code.MissingLeftPart)]
	[TestCase("= ", Error.Code.MissingLeftPart)]
	[TestCase(" = 0", Error.Code.MissingLeftPart)]
	
	[TestCase("1 = ", Error.Code.MissingRightPart)]
	[TestCase("x + 5 = ", Error.Code.MissingRightPart)]
	
	[TestCase("x ^ 3 = 0", Error.Code.InvalidPower)]
	[TestCase("x * x * x = 0", Error.Code.MissingRightPart)]
	public static void		ErrorCases(string input, Error.Code code)
	{
		Error.Exception		exception;
			
		exception = Assert.Throws<Error.Exception>(() => RunProgram(input));
		Assert.AreEqual(exception.Code, code);
	}
	
	private static void		RunProgram(string input = null)
	{
		using var			stringWriter = new StringWriter();
		
		Console.SetOut(stringWriter);
		Program.Main(input != null ? new[] {input, "test"} : new[] {"test"});

		_output = stringWriter.ToString();
	}
}