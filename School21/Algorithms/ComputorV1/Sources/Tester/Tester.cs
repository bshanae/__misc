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
	
	#region					Valid cases

	[Test]
	public static void		Valid1()
	{
		RunProgram("2 * x ^ 2 - 4 * x - 2 = 0");
		Assert.AreEqual("-0.414214, 2.414214", _output);
	}
	
	[Test]
	public static void		Valid2()
	{
		RunProgram("6 * x ^ 2 + 11 * x - 35 = 0");
		Assert.AreEqual("-7 / 2, 5 / 3", _output);
	}
	
	[Test]
	public static void		Valid3()
	{
		RunProgram("-4 * x ^ 2 - 7 * x + 12 = 0");
		Assert.AreEqual("-2.815522, 1.065522", _output);
	}
	
	[Test]
	public static void		Valid4()
	{
		RunProgram("20 * x ^ 2 -15 * x - 10 = 0");
		Assert.AreEqual("-0.425391, 1.175390", _output);
	}
	
	[Test]
	public static void		Valid5()
	{
		RunProgram("x ^ 2 - x - 3 = 0");
		Assert.AreEqual("-1.302776, 2.302776", _output);
	}
	
	[Test]
	public static void		Valid6()
	{
		RunProgram("5 * x ^ 2 - 2 * x - 9 = 0");
		Assert.AreEqual("-1.156466, 1.556466", _output);
	}
	
	[Test]
	public static void		Valid7()
	{
		RunProgram("3 * x ^ 2 + 4 * x + 2 = 0");
		Assert.AreEqual("", _output);
	}
	
	[Test]
	public static void		Valid8()
	{
		RunProgram("-x ^ 2 + 6 * x + 18 = 0");
		Assert.AreEqual("-2.196153, 8.196153", _output);
	}
	
	#endregion

	#region					Incomplete orm
	
	[Test]
	public static void		Incomplete1()
	{
		RunProgram("-x ^ 2 = -4");
		Assert.AreEqual("-2, 2", _output);
	}
	
	[Test]
	public static void		Incomplete2()
	{
		RunProgram("x = 5");
		Assert.AreEqual("5", _output);
	}
	
	[Test]
	public static void		Incomplete3()
	{
		RunProgram("x * x = 5");
		Assert.AreEqual("-2.236066, 2.236066", _output);
	}
	
	
	[Test]
	public static void		Incomplete4()
	{
		RunProgram("2 * x = 7");
		Assert.AreEqual("7 / 2", _output);
	}
	
	#endregion
	
	#region					Special cases
	
	[Test]
	public static void		SpecialCase1()
	{
		RunProgram("0 = 4");
		Assert.AreEqual("", _output);
	}
	
	[Test]
	public static void		SpecialCase2()
	{
		RunProgram("4 = 4");
		Assert.AreEqual("Any", _output);
	}

	#endregion
	
	#region					Error

	// "="
	// "1 ="
	// "1 = = 1"
	// "1 = 1 = 1"
	
	#endregion
	
	#region					Private methos
	
	private static void		RunProgram(string input)
	{
		using var			stringWriter = new StringWriter();
		
		Console.SetOut(stringWriter);
		Program.Main(new []{input, "test"});

		_output = stringWriter.ToString();
	}

	#endregion
}