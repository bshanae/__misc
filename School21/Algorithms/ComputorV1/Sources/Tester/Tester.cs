using System;
using System.Collections.Generic;
using System.IO;
using Computor;
using NUnit.Framework;

[TestFixture]  
public static class				Tester
{
	#region						Data

	private const float			PrecisionEpsilon = 0.00001f;
	private static string		_output;
	
	#endregion

	[SetUp]
	public static void			RestoreWorkspace()
	{
		Workspace.Expression = null;
		Workspace.Tokens = new List<Token>();
		Workspace.FinalHolder.ConnectElement(new Group(Operator.Priorities.Final));
		Workspace.Terms = new List<Term>();
		Workspace.SortedTerms = new Dictionary<int, Term>();
		Workspace.Solutions = new List<Math.Fraction>();
		Workspace.SolutionKind = SolutionKinds.Undefined;

		_output = null;
	}

	// [TestCase("-4 * x ^ 2 - 7 * x + 12 = 0", "-2.815522, 1.065522")]
	// [TestCase("20 * x ^ 2 -15 * x - 10 = 0", "-0.425391, 1.175390")]
	// [TestCase("x ^ 2 - x - 3 = 0", "-1.302776, 2.302776")]
	// [TestCase("5 * x ^ 2 - 2 * x - 9 = 0", "-1.156466, 1.556466")]
	// [TestCase("3 * x ^ 2 + 4 * x + 2 = 0", "")]
	// [TestCase("-x ^ 2 + 6 * x + 18 = 0", "-2.196153, 8.196153")]
	// [TestCase("x + x ^ 2 + x * x ^ 1 = 0", "-1 / 2, 0")]
	// [TestCase("x ^ 1 * x = 0", "0")]
	// [TestCase("x ^ 2 / 2 / 2 = 0", "0")]
	// [TestCase("2x^2 + 4x - 2 = 0", "-2.414214, 0.414214")]
	// [TestCase("x * x = 0", "0")]
	[Test]
	public static void			ValidCases()
	{
		RunProgram("2 * x ^ 2 - 4 * x - 2 = 0");
		Assert.IsTrue(CheckTwoSolutions(-0.414214f, 2.414214f));
		
		RunProgram("6 * x ^ 2 + 11 * x - 35 = 0");
		Assert.IsTrue(CheckTwoSolutions(new Math.Fraction(-7f, 2f), new Math.Fraction(5f, 3f)));
	}

	[TestCase("-x ^ 2 = -4", "-2, 2")]
	[TestCase("x = 5", "5")]
	[TestCase("x * x = 5", "-2.236068, 2.236068")]
	[TestCase("2 * x = 7", "7 / 2")]
	public static void			IncompleteFormCases(string input, string expected)
	{
		RunProgram(input);
		Assert.AreEqual(expected, _output);
	}
	
	[TestCase("x^2/x^2 = 1", "Any")]
	[TestCase("x^2^2 = 16", "2")]
	[TestCase("x*2^2 = 16", "4")]
	[TestCase("x*2/2-1-2-3 = 0", "6")]
	public static void			ComplexCases(string input, string expected)
	{
		RunProgram(input);
		Assert.AreEqual(expected, _output);
	}
	
	[TestCase("0 = 4", "")]
	[TestCase("4 = 4", "Any")]
	[TestCase("x = x", "Any")]
	public static void			SpecialCases(string input, string expected)
	{
		RunProgram(input);
		Assert.AreEqual(expected, _output);
	}

	[TestCase(null, Error.UsageErrors.ExpressionIsNotGiven)]
	
	[TestCase("ajnakak", Error.UsageErrors.InvalidCharacter)]
	[TestCase("y = 0", Error.UsageErrors.InvalidCharacter)]

	[TestCase("x = 1.3.3.3", Error.UsageErrors.BadFloat)]
	[TestCase("x = ..0101", Error.UsageErrors.BadFloat)]
	
	[TestCase("xx = 0", Error.UsageErrors.MissingOperator)]
	[TestCase("xxxxx = 0", Error.UsageErrors.MissingOperator)]
	[TestCase("x3 = 0", Error.UsageErrors.MissingOperator)]

	[TestCase("x++ = 0", Error.UsageErrors.MissingOperand)]
	[TestCase("1-+2 = 0", Error.UsageErrors.MissingOperand)]
	[TestCase("1---2 = 0", Error.UsageErrors.MissingOperand)]
	[TestCase(" = ", Error.UsageErrors.MissingOperand)]
	[TestCase("= ", Error.UsageErrors.MissingOperand)]
	[TestCase(" = 0", Error.UsageErrors.MissingOperand)]
	[TestCase("1 = ", Error.UsageErrors.MissingOperand)]
	[TestCase("x + 5 = ", Error.UsageErrors.MissingOperand)]
	[TestCase("x * x * x = ", Error.UsageErrors.MissingOperand)]
	[TestCase("+2 = 0", Error.UsageErrors.MissingOperand)]
	[TestCase("*1 = 0", Error.UsageErrors.MissingOperand)]
	[TestCase("^8 = 0", Error.UsageErrors.MissingOperand)]
	[TestCase("x = 0*", Error.UsageErrors.MissingOperand)]
	
	[TestCase("x^x = 0", Error.UsageErrors.PowerIsNotConstant)]
	[TestCase("2^x = 0", Error.UsageErrors.PowerIsNotConstant)]
	
	[TestCase("x^1.1 = 0", Error.UsageErrors.PowerIsNotInteger)]
	[TestCase("x^.11 * x^1.2 = 0", Error.UsageErrors.PowerIsNotInteger)]

	[TestCase("1 = 0 = 1", Error.UsageErrors.MoreThanOneEqualitySign)]
	[TestCase("1 = 0 = 1 = x", Error.UsageErrors.MoreThanOneEqualitySign)]

	[TestCase("x ^ 3 = 0", Error.UsageErrors.InvalidPower)]
	public static void			ErrorCases(string input, Error.UsageErrors usageError)
	{
		Error.UsageException	exception;
			
		exception = Assert.Throws<Error.UsageException>(() => RunProgram(input));
		Assert.AreEqual(usageError, exception.Error);
	}
	
	private static void			RunProgram(string input = null)
	{
		using var				stringWriter = new StringWriter();
		
		Console.SetOut(stringWriter);
		Program.Main(input != null ? new[] {input, "test"} : new[] {"test"});

		_output = stringWriter.ToString();
	}

	private static bool			CheckNoSolutions()
	{
		return Workspace.SolutionKind == SolutionKinds.NoSolutions;
	}

	private static bool			CheckOneSolution(float x)
	{
		return
			Workspace.SolutionKind == SolutionKinds.OneSolution &&
			Math.AlmostEqual(Workspace.Solutions[0].Value, x, PrecisionEpsilon);
	}
	
	private static bool			CheckOneSolution(Math.Fraction fraction)
	{
		return Workspace.SolutionKind == SolutionKinds.OneSolution && Workspace.Solutions[0] == fraction;
	}

	private static bool			CheckTwoSolutions(float x1, float x2)
	{
		return
			Workspace.SolutionKind == SolutionKinds.TwoSolutions &&
			Math.AlmostEqual(Workspace.Solutions[0].Value, x1) &&
			Math.AlmostEqual(Workspace.Solutions[1].Value, x2);
	}
	
	private static bool			CheckTwoSolutions(Math.Fraction x1, Math.Fraction x2)
	{
		return
			Workspace.SolutionKind == SolutionKinds.TwoSolutions &&
			Workspace.Solutions[0] == x1 &&
			Workspace.Solutions[1] == x2;
	}

	private static bool			CheckInfiniteRoots()
	{
		return Workspace.SolutionKind == SolutionKinds.InfiniteSolutions;
	}
}