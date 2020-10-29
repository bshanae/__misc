using System;
using System.Collections.Generic;
using System.IO;
using Computor;
using NUnit.Framework;
using NUnit.Framework.Internal.Execution;

[TestFixture]  
public static class				Tester
{
	#region						Data

	private const float			PrecisionEpsilon = 0.00001f;
	private static string		_output;
	
	#endregion

	#region 					Tests
	
	[Test]
	public static void			ValidCases()
	{
		{
			RunProgram("2 * x ^ 2 - 4 * x - 2 = 0");
			Assert.IsTrue(CheckTwoSolutions(-0.414214f, 2.414214f));

			RunProgram("-4 * x ^ 2 - 7 * x + 12 = 0");
			Assert.IsTrue(CheckTwoSolutions(-2.815521f, 1.065521f));

			RunProgram("20 * x ^ 2 -15 * x - 10 = 0");
			Assert.IsTrue(CheckTwoSolutions(-0.425391f, 1.175390f));

			RunProgram("x ^ 2 - x - 3 = 0");
			Assert.IsTrue(CheckTwoSolutions(-1.302776f, 2.302776f));

			RunProgram("5 * x ^ 2 - 2 * x - 9 = 0");
			Assert.IsTrue(CheckTwoSolutions(-1.156466f, 1.556466f));

			RunProgram("-x ^ 2 + 6 * x + 18 = 0");
			Assert.IsTrue(CheckTwoSolutions(-2.196153f, 8.196153f));
			
			RunProgram("2x^2 + 4x - 2 = 0");
			Assert.IsTrue(CheckTwoSolutions(-2.414214f, 0.414214f));

			RunProgram("6 * x ^ 2 + 11 * x - 35 = 0");
			Assert.IsTrue(CheckTwoSolutions(new Math.Fraction(-7f, 2f), new Math.Fraction(5f, 3f)));

			RunProgram("x + x ^ 2 + x * x ^ 1 = 0");
			Assert.IsTrue(CheckTwoSolutions(new Math.Fraction(-1f, 2f), new Math.Fraction(0f)));
		}

		{
			RunProgram("x ^ 1 * x = 0");
			Assert.IsTrue(CheckOneSolution(0f));
			
			RunProgram("x ^ 2 / 2 / 2 = 0");
			Assert.IsTrue(CheckOneSolution(0f));
			
			RunProgram("x*x = 0");
			Assert.IsTrue(CheckOneSolution(0f));
		}

		{
			RunProgram("3 * x ^ 2 + 4 * x + 2 = 0");
			Assert.IsTrue(CheckNoSolutions());
		}
	}
	
	[Test]
	public static void			ComplexCases()
	{
		RunProgram("2 * x ^ 2 - 4 * x - 2 = 0");
		Assert.IsTrue(CheckTwoSolutions(-0.414214f, 2.414214f));

		RunProgram("x^2/x^2 = 1");
		Assert.IsTrue(CheckInfiniteSolutions());

		RunProgram("x^2^2/x = 27");
		Assert.IsTrue(CheckOneSolution(3f));

		RunProgram("x*2^2 = 16");
		Assert.IsTrue(CheckOneSolution(4f));

		RunProgram("x*2/2-1-2-3 = 0");
		Assert.IsTrue(CheckOneSolution(6f));
	}
	
	[Test]
	public static void			IncompleteFormCases()
	{
		RunProgram("-x ^ 2 = -4");
		Assert.IsTrue(CheckTwoSolutions(-2f, 2f));
		
		RunProgram("x = 5");
		Assert.IsTrue(CheckOneSolution(5f));
		
		RunProgram("x + 3 = 5");
		Assert.IsTrue(CheckOneSolution(2f));
		
		RunProgram("x * x = 5");
		Assert.IsTrue(CheckTwoSolutions(-2.236068f, 2.236068f));
		
		RunProgram("2 * x = 7");
		Assert.IsTrue(CheckOneSolution(new Math.Fraction(7f, 2f)));
	}

	[Test]
	public static void			SpecialCases()
	{
		RunProgram("0 = 4");
		Assert.IsTrue(CheckNoSolutions());
			
		RunProgram("4 = 4");
		Assert.IsTrue(CheckInfiniteSolutions());
		
		RunProgram("x = x");
		Assert.IsTrue(CheckInfiniteSolutions());
	}

	[Test]
	public static void			ErrorCases()
	{
		{
			RunProgramAndCheckError(null, Error.UsageErrors.ExpressionIsNotGiven);
		}

		{
			RunProgramAndCheckError("ajnakak", Error.UsageErrors.InvalidCharacter);
			RunProgramAndCheckError("y = 0", Error.UsageErrors.InvalidCharacter);
		}

		{
			RunProgramAndCheckError("x = 1.3.3.3", Error.UsageErrors.BadFloat);
			RunProgramAndCheckError("x = ..0101", Error.UsageErrors.BadFloat);
		}

		{
			RunProgramAndCheckError("xx = 0", Error.UsageErrors.MissingOperator);
			RunProgramAndCheckError("xxxxx = 0", Error.UsageErrors.MissingOperator);
			RunProgramAndCheckError("x3 = 0", Error.UsageErrors.MissingOperator);
		}

		{
			RunProgramAndCheckError("x++ = 0", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("1-+2 = 0", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("1---2 = 0", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError(" = ", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("= ", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError(" = 0", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("1 = ", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("x + 5 = ", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("x * x * x = ", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("+2 = 0", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("*1 = 0", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("^8 = 0", Error.UsageErrors.MissingOperand);
			RunProgramAndCheckError("x = 0*", Error.UsageErrors.MissingOperand);
		}

		{
			RunProgramAndCheckError("x^x = 0", Error.UsageErrors.PowerIsNotConstant);
			RunProgramAndCheckError("2^x = 0", Error.UsageErrors.PowerIsNotConstant);
		}

		{
			RunProgramAndCheckError("x^1.1 = 0", Error.UsageErrors.PowerIsNotInteger);
			RunProgramAndCheckError("x^.11 * x^1.2 = 0", Error.UsageErrors.PowerIsNotInteger);
		}

		{
			RunProgramAndCheckError("1 = 0 = 1", Error.UsageErrors.MoreThanOneEqualitySign);
			RunProgramAndCheckError("1 = 0 = 1 = x", Error.UsageErrors.MoreThanOneEqualitySign);
		}

		{
			RunProgramAndCheckError("x ^ 3 = 0", Error.UsageErrors.InvalidPower);
		}
	}

	#endregion

	#region 					Service methods
	
	private static void			RunProgram(string input = null)
	{
		RestoreWorkspace();
		
		using var				stringWriter = new StringWriter();
		
		Console.SetOut(stringWriter);
		Program.Main(input != null ? new[] {input, "test"} : new[] {"test"});

		_output = stringWriter.ToString();
		
		static void			RestoreWorkspace()
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
	}

	private static bool			RunProgramAndCheckError(string input, Error.UsageErrors error)
	{
		try
		{
			RunProgram(input);
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

	private static bool			CheckInfiniteSolutions()
	{
		return Workspace.SolutionKind == SolutionKinds.InfiniteSolutions;
	}

	#endregion
}