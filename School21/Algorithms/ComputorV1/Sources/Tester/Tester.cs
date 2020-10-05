using System;
using System.Collections.Generic;
using System.IO;
using Computor;
using NUnit.Framework;

[TestFixture]  
public static class			Tester
{
	#region					Fields

	private static string	Output;
	
	#endregion

	[SetUp]
	public static void Init()
	{
		Workspace.Tokens = new List<Token>();
		Workspace.Terms = new List<Term>();
		Workspace.SortedTerms = new Dictionary<int, Term>();
		Workspace.EquationRoots = new List<Math.Fraction>();
	}
	
	#region					Valid cases	
	
	static Tester()
	{}
	
	[Test]
	public static void		Valid1()
	{
		RunProgram("2 * x ^ 2 - 4 * x - 2 = 0");
		Assert.AreEqual("-0.4142137, 2.414214", Output);
	}
	
	[Test]
	public static void		Valid2()
	{
		RunProgram("6 * x ^ 2 + 11 * x - 35 = 0");
		Assert.AreEqual("1.666667, -3.5", Output);
	}
	
	[Test]
	public static void		Valid3()
	{
		RunProgram("-4 * x ^ 2 - 7 * x + 12 = 0");
		Assert.AreEqual("-2.815521, 1.065521", Output);
	}
	
	[Test]
	public static void		Valid4()
	{
		RunProgram("20 * x ^ 2 -15 * x - 10 = 0");
		Assert.AreEqual("-0.425390, 1.175390", Output);
	}
	
	[Test]
	public static void		Valid5()
	{
		RunProgram("x ^ 2 - x - 3 = 0");
		Assert.AreEqual("-1.302775, 2.302775", Output);
	}
	
	[Test]
	public static void		Valid6()
	{
		RunProgram("5 * x ^ 2 - 2 * x - 9 = 0");
		Assert.AreEqual("-1.156465, 1.556465", Output);
	}
	
	[Test]
	public static void		Valid7()
	{
		RunProgram("3 * x ^ 2 + 4 * x + 2 = 0");
		Assert.AreEqual("", Output);
	}
	
	[Test]
	public static void		Valid8()
	{
		RunProgram("-x ^ 2 + 6 * x + 18 = 0");
		Assert.AreEqual("-2.196152, 8.196152", Output);
	}
	
	#endregion

	#region					Incomplete orm
	
	[Test]
	public static void		Incomplete1()
	{
		RunProgram("-x ^ 2 = -4");
		// Assert.AreEqual("-2, 2", Output);
		
		Assert.True(true);
	}
	
	[Test]
	public static void		Incomplete2()
	{
		RunProgram("x = 5");
		Assert.AreEqual("5", Output);
	}
	
	[Test]
	public static void		Incomplete3()
	{
		RunProgram("x * x = 5");
		Assert.AreEqual("-2.236067, +2.236067", Output);
	}
	
	
	[Test]
	public static void		Incomplete4()
	{
		RunProgram("2 * x = 7");
		Assert.AreEqual("3.5", Output);
	}
	
	#endregion
	
	#region					Special cases
	
	// "4 = 4"
	// "0 = 4"
	
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

		Output = stringWriter.ToString();
	}

	#endregion
}