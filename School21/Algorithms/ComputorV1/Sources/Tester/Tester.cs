using NUnit.Framework;

[TestFixture]  
public static class			Tester
{
	#region					Valid cases	
	
	[Test]
	public static void		Valid1()
	{
		RunProgram("2 * x ^ 2 - 4 * x - 2 = 0");
		Assert.True(DoesOutputEqual("2.41421, -0.41421"));
	}
	
	[Test]
	public static void		Valid2()
	{
		RunProgram("6 * x ^ 2 + 11 * x - 35 = 0");
		Assert.True(DoesOutputEqual("1.666667, -3.5"));
	}
	
	[Test]
	public static void		Valid3()
	{
		RunProgram("-4 * x ^ 2 - 7 * x + 12 = 0");
		Assert.True(DoesOutputEqual("-2.815521, 1.065521"));
	}
	
	[Test]
	public static void		Valid4()
	{
		RunProgram("20 * x ^ 2 -15 * x - 10 = 0");
		Assert.True(DoesOutputEqual("-0.425390, 1.175390"));
	}
	
	[Test]
	public static void		Valid5()
	{
		RunProgram("x ^ 2 - x - 3 = 0");
		Assert.True(DoesOutputEqual("-1.302775, 2.302775"));
	}
	
	[Test]
	public static void		Valid6()
	{
		RunProgram("5 * x ^ 2 - 2 * x - 9 = 0");
		Assert.True(DoesOutputEqual("-1.156465, 1.556465"));
	}
	
	[Test]
	public static void		Valid7()
	{
		RunProgram("3 * x ^ 2 + 4 * x + 2 = 0");
		Assert.True(DoesOutputEqual(""));
	}
	
	[Test]
	public static void		Valid8()
	{
		RunProgram("-x ^ 2 + 6 * x + 18 = 0");
		Assert.True(DoesOutputEqual("-2.196152, 8.196152"));
	}
	
	#endregion

	#region					Incomplete orm
	
	[Test]
	public static void		Incomplete1()
	{
		RunProgram("-x ^ 2 = -4");
		Assert.True(DoesOutputEqual("-2, 2"));
	}
	
	[Test]
	public static void		Incomplete2()
	{
		RunProgram("x = 5");
		Assert.True(DoesOutputEqual("5"));
	}
	
	[Test]
	public static void		Incomplete3()
	{
		RunProgram("x * x = 5");
		Assert.True(DoesOutputEqual("-2.236067, +2.236067"));
	}
	
	
	[Test]
	public static void		Incomplete4()
	{
		RunProgram("2 * x = 7");
		Assert.True(DoesOutputEqual("3.5"));
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
		Program.Main(new []{input, "test"});
	}

	private static bool		DoesOutputEqual(string expected)
	{
		return expected == TestContext.Out.ToString();
	}

	#endregion
}