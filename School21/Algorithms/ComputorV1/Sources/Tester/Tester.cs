using NUnit.Framework;

[TestFixture]  
public static class			Tester
{
	#region					Valid cases	
	
	[Test]
	public static void		Valid1()
	{
		Assert.True(RunComputorForExpected("2 * x ^ 2 - 4 * x - 2 = 0", 2.41421f, -0.41421f));
	}
	
	[Test]
	public static void		Valid2()
	{
		Assert.True(RunComputorForExpected("6 * x ^ 2 + 11 * x - 35 = 0", 1.666667f, -3.5f));
	}
	
	[Test]
	public static void		Valid3()
	{
		Assert.True(RunComputorForExpected("-4 * x ^ 2 - 7 * x + 12 = 0", -2.815521f, 1.065521f));
	}
	
	[Test]
	public static void		Valid4()
	{
		Assert.True(RunComputorForExpected("20 * x ^ 2 -15 * x - 10 = 0", 1.175390f, -0.425390f));
	}
	
	[Test]
	public static void		Valid5()
	{
		Assert.True(RunComputorForExpected("x ^ 2 - x - 3 = 0", 2.302775f, -1.302775f));
	}
	
	[Test]
	public static void		Valid6()
	{
		Assert.True(RunComputorForExpected("5 * x ^ 2 - 2 * x - 9 = 0", 1.556465f, -1.156465f));
	}
	
	[Test]
	public static void		Valid7()
	{
		Assert.True(RunComputorForExpected("3 * x ^ 2 + 4 * x + 2 = 0", null, null));
	}
	
	[Test]
	public static void		Valid8()
	{
		Assert.True(RunComputorForExpected("-x ^ 2 + 6 * x + 18 = 0", -2.196152f, 8.196152f));
	}
	
	#endregion

	#region					Valid complex cases
	
	[Test]
	public static void		ValidComplex1()
	{
		Assert.True(RunComputorForExpected("1 * x ^ 1 * x + 2 * x * 2 + 3 - 5 = 0", 0.449489f, -4.449489f));
	}
	
	[Test]
	public static void		ValidComplex2()
	{
		Assert.True(RunComputorForExpected("1 * x * 2 + 2 - 3 = x ^ 2 + 2 * x - x * 3", 0.381966f, 2.618033f));
	}
	
	[Test]
	public static void		ValidComplex3()
	{
		Assert.True(RunComputorForExpected("x ^ -1 * x + x * x * x / x - 2 / 1 * 4 / 2 - 1 + 3 = 0", 0.381966f, 2.618033f));
	}

	#endregion
	
	#region					Invalid complex cases
	
	// (x + x ^ 2) * (1 + x) = 0
	
	#endregion
	
	#region					Incomplete form
	
	[Test]
	public static void		Incomplete1()
	{
		Assert.True(RunComputorForExpected("-x ^ 2 = -4", -2f, +2f));
	}
	
	[Test]
	public static void		Incomplete2()
	{
		Assert.True(RunComputorForExpected("x = 5", 5f, null));
	}
	
	[Test]
	public static void		Incomplete3()
	{
		Assert.True(RunComputorForExpected("x * x = 5", -2.236067f, +2.236067f));
	}
	
	
	[Test]
	public static void		Incomplete4()
	{
		Assert.True(RunComputorForExpected("2 * x = 7", 3.5f, null));
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
	
	private static bool		RunComputorForExpected(string expression, float? firstRoot, float? secondRoot)
	{
		ComputorV1.Main(new []{expression, "Verbose", "Test"});
		
		Printer.PrintLine($"Expected roots : {firstRoot}, {secondRoot}");
		Printer.PrintLine($"Actual roots : {Equation.FirstRoot}, {Equation.SecondRoot}");
		
		return DoesRootEqual(Equation.FirstRoot, firstRoot) && DoesRootEqual(Equation.SecondRoot, secondRoot);
	}

	private static bool		DoesRootEqual(Math.Fraction? root, float? value)
	{
		if (root == null)
			return value == null;
		else
			return value != null && Math.AlmostEquals(root.Value._C_, value.Value, 0.0001f);
	}
	
	#endregion
}
