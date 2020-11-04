using System.Collections.Generic;
using Computor;
using NUnit.Framework;

[TestFixture]  
public static class				Tester
{
	#region						Data

	private const float			PrecisionEpsilon = 0.0001f;
	
	#endregion

	#region 					Tests
	
	[Test]
	public static void			Normal()
	{
		{
			RunProgram("2 * x ^ 2 - 4 * x - 2 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(-0.414214f, 2.414214f));

			RunProgram("-4 * x ^ 2 - 7 * x + 12 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(-2.815521f, 1.065521f));

			RunProgram("20 * x ^ 2 -15 * x - 10 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(-0.425391f, 1.175390f));

			RunProgram("x ^ 2 - x - 3 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(-1.302776f, 2.302776f));

			RunProgram("5 * x ^ 2 - 2 * x - 9 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(-1.156466f, 1.556466f));

			RunProgram("-x ^ 2 + 6 * x + 18 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(-2.196153f, 8.196153f));
			
			RunProgram("2x^2 + 4x - 2 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(-2.414214f, 0.414214f));

			RunProgram("6 * x ^ 2 + 11 * x - 35 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(new Math.Fraction(-7f, 2f), new Math.Fraction(5f, 3f)));

			RunProgram("x + x ^ 2 + x * x ^ 1 = 0", "--test");
			Assert.IsTrue(CheckTwoSolutions(new Math.Fraction(-1f, 2f), new Math.Fraction(0f)));
		}

		{
			RunProgram("x ^ 1 * x = 0", "--test");
			Assert.IsTrue(CheckOneSolution(0f));
			
			RunProgram("x ^ 2 / 2 / 2 = 0", "--test");
			Assert.IsTrue(CheckOneSolution(0f));
			
			RunProgram("x*x = 0", "--test");
			Assert.IsTrue(CheckOneSolution(0f));
		}
	}
	
	[Test]
	public static void			ImaginarySolution()
	{
		{
			RunProgram("3 * x ^ 2 + 4 * x + 2 = 0", "--test");
			Assert.IsTrue
			(
				CheckImaginarySolutions
				(
					new Math.Complex(-0.666666f, +0.471404f),
					new Math.Complex(-0.666666f, -0.471404f)
				)
			);
			
			RunProgram("x ^ 2 = -16", "--test");
			Assert.IsTrue
			(
				CheckImaginarySolutions
				(
					new Math.Complex(-4f, 1f),
					new Math.Complex(+4f, 1f)
				)
			);
		}
	}
	
	[Test]
	public static void			Evaluation()
	{
		RunProgram("2 * x ^ 2 - 4 * x - 2 = 0", "--test");
		Assert.IsTrue(CheckTwoSolutions(-0.414214f, 2.414214f));

		RunProgram("x ^ 2 / x ^ 2 = 1", "--test");
		Assert.IsTrue(CheckInfiniteSolutions());

		RunProgram("x ^ 2 ^ 2 / x / x = 9", "--test");
		Assert.IsTrue(CheckTwoSolutions(-3f, 3f));

		RunProgram("x * 2 ^ 2 = 16", "--test");
		Assert.IsTrue(CheckOneSolution(4f));

		RunProgram("x * 2 / 2 - 1 - 2 - 3 = 0", "--test");
		Assert.IsTrue(CheckOneSolution(6f));
		
		RunProgram("5 * x ^ 2 = 20", "--test");
		Assert.IsTrue(CheckTwoSolutions(-2f, 2f));

		RunProgram("1 * 5 * x ^ 2 = 20", "--test");
		Assert.IsTrue(CheckTwoSolutions(-2f, 2f));
		
		RunProgram("2 * 5 * x ^ 2 / 2 = 20", "--test");
		Assert.IsTrue(CheckTwoSolutions(-2f, 2f));
		
		RunProgram("x ^ 2 * 1 * 5 = 20", "--test");
		Assert.IsTrue(CheckTwoSolutions(-2f, 2f));
		
		RunProgram("X - 5 + 5 = 0", "--test");
		Assert.IsTrue(CheckOneSolution(0f));
		
		RunProgram("x ^ 3 - x ^ 3 = 0", "--test");
		Assert.IsTrue(CheckInfiniteSolutions());
		
		RunProgram("x ^ 2 / x ^ 2 = 1", "--test");
		Assert.IsTrue(CheckInfiniteSolutions());
		
		RunProgram("x^2^2/2*x/x^4 = 5", "--test");
		Assert.IsTrue(CheckOneSolution(10f));
		
		RunProgram("x/x/x^2*x^3 = 5", "--test");
		Assert.IsTrue(CheckOneSolution(5f));
		
		RunProgram("x = x - 5 + 2x - 3x + 1x - 10x", "--test");
		Assert.IsTrue(CheckOneSolution(new Math.Fraction(-1f, 2f)));
		
		RunProgram("x ^ 2 + 6 x ^ 2 - 9 * 6 = 19 + 4", "--test");
		Assert.IsTrue(CheckTwoSolutions(-3.316625f, 3.316625f));
		
		RunProgram("18x - 250x ^ 2 + x ^ 3 / x / x = 500x", "--test");
		Assert.IsTrue(CheckTwoSolutions(-1.924f, 0f));
		
		RunProgram("x/x * x/x * x/x * x*x/x = 5", "--test");
		Assert.IsTrue(CheckOneSolution(5f));
		
		RunProgram("x ^ 1 = x ^ 0", "--test");
		Assert.IsTrue(CheckOneSolution(1f));
	}
	
	[Test]
	public static void			IncompleteForm()
	{
		RunProgram("x ^ 2 = 4", "--test");
		Assert.IsTrue(CheckTwoSolutions(-2f, 2f));

		RunProgram("-x ^ 2 = -4", "--test");
		Assert.IsTrue(CheckTwoSolutions(-2f, 2f));

		RunProgram("x = 5", "--test");
		Assert.IsTrue(CheckOneSolution(5f));
		
		RunProgram("x + 3 = 5", "--test");
		Assert.IsTrue(CheckOneSolution(2f));
		
		RunProgram("x * x = 5", "--test");
		Assert.IsTrue(CheckTwoSolutions(-2.236068f, 2.236068f));
		
		RunProgram("2 * x = 7", "--test");
		Assert.IsTrue(CheckOneSolution(new Math.Fraction(7f, 2f)));
	}

	[Test]
	public static void			Special()
	{
		RunProgram("0 = 4", "--test");
		Assert.IsTrue(CheckNoSolutions());
			
		RunProgram("4 = 4", "--test");
		Assert.IsTrue(CheckInfiniteSolutions());
		
		RunProgram("x = x", "--test");
		Assert.IsTrue(CheckInfiniteSolutions());
	}

	[Test]
	public static void			Error()
	{
		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.InvalidCommandLineArguments));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.InvalidCommandLineArguments, "--hi", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.InvalidCommandLineArguments, "--report=hi", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.InvalidCommandLineArguments, "abc", "abc", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.EmptyExpression, "", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.InvalidCharacter, "ajnakak", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.InvalidCharacter, "y = 0", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.BadFloat, "x = 1.3.3.3", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.BadFloat, "x = ..0101", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperator, "xx = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperator, "xxxxx = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperator, "x3 = 0", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "x++ = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "1-+2 = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "1---2 = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, " = ", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "= ", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, " = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "1 = ", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "x + 5 = ", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "x * x * x = ", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "+2 = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "*1 = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "^8 = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MissingOperand, "x = 0*", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.PowerIsNotConstant, "x^x = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.PowerIsNotConstant, "2^x = 0", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.PowerIsNotInteger, "x^1.1 = 0", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.PowerIsNotInteger, "x^.11 * x^1.2 = 0", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MoreThanOneEqualitySign, "1 = 0 = 1", "--test"));
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.MoreThanOneEqualitySign, "1 = 0 = 1 = x", "--test"));
		}

		{
			Assert.IsTrue(RunProgramAndCheckError(global::Error.UsageErrors.InvalidPower, "x ^ 3 = 0", "--test"));
		}
	}

	#endregion

	#region 					Service methods
	
	private static void			RunProgram(params string[] arguments)
	{
		PrepareEnvironment();
		Program.Main(arguments);

		static void				PrepareEnvironment()
		{
			Program.Options.Test = true;
			
			Workspace.Expression = null;
			Workspace.Tokens = new List<Token>();
			Workspace.FinalHolder.ConnectElement(new Group(Operator.Priorities.Final));
			Workspace.Terms = new List<Term>();
			Workspace.SortedTerms = new Dictionary<int, Term>();
			Workspace.Solutions = new List<Math.Fraction>();
			Workspace.SolutionKind = SolutionKinds.Undefined;
		}
	}

	private static bool			RunProgramAndCheckError(Error.UsageErrors error, params string[] arguments)
	{
		try
		{
			RunProgram(arguments);
			return false;
		}
		catch (Error.UsageException exception)
		{
			return exception.Error == error;
		}
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
			Math.AlmostEqual(Workspace.Solutions[0].Value, x1, PrecisionEpsilon) &&
			Math.AlmostEqual(Workspace.Solutions[1].Value, x2, PrecisionEpsilon);
	}
	
	private static bool			CheckTwoSolutions(Math.Fraction x1, Math.Fraction x2)
	{
		return
			Workspace.SolutionKind == SolutionKinds.TwoSolutions &&
			Workspace.Solutions[0] == x1 &&
			Workspace.Solutions[1] == x2;
	}

	private static bool			CheckImaginarySolutions(Math.Complex x1, Math.Complex x2)
	{
		return
			Workspace.SolutionKind == SolutionKinds.ImaginarySolutions &&
			Math.AlmostEqual(Workspace.ComplexSolutions[0], x1, PrecisionEpsilon) &&
			Math.AlmostEqual(Workspace.ComplexSolutions[1], x2, PrecisionEpsilon);
	}

	private static bool			CheckInfiniteSolutions()
	{
		return Workspace.SolutionKind == SolutionKinds.InfiniteSolutions;
	}

	#endregion
}