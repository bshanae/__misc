using NUnit.Framework;

[TestFixture]  
public static class			Tester
{
	
	// Solve("1 * x ^ 1 * x + 2 * x * 2 + 3 - 5 = 0");
		// Solve("1 * x * 2 + 2 - 3 = x ^ 2 + 2 * x - x * 3");
		
		// Errors
		// Solve("=");
		// Solve("1 =");
		// Solve("1 = = 1");
		// Solve("1 = 1 = 1");
		
		// Incomplete quadratic form
		// Solve("x ^ 2 = 4");
		// Solve("x = 4");
		// Solve("x * x = 5");
		// Solve("2 * x = 4");
		
		// Special cases
		// Solve("4 = 4");
		// Solve("0 = 4");
		// Solve("x = 4");
		
		// Random
		// Solve("2 * 3 ^ -1 * x = 8");
		// Solve("2 * 3 ^ -1 * x = 8");
		
		// Correct
		// Solve("x - x = 0");
	
	[Test]
	public static void		NormalCases()
	{
		Assert.True(RunComputorForExpected("6 * x ^ 2 + 11 * x - 35 = 0", 1.666667f, -3.5f));
		Assert.True(RunComputorForExpected("2 * x ^ 2 - 4 * x - 2 = 0", 2.41421f, -0.41421f));
		// Test("-4 * x ^ 2 - 7 * x +12 = 0", "Equation roots : ");
		// Test("20 * x ^ 2 -15 * x - 10 = 0", "Equation roots : ");
		// Test("x ^ 2 - x - 3 = 0", "Equation roots : ");
		// Test("5 * x ^ 2 - 2 * x - 9 = 0", "Equation roots : ");
		// Test("3 * x ^ 2 + 4 * x + 2 = 0", "Equation roots : ");
		// Test("-x ^ 2 +6 * x + 18 = 0", "Equation roots : ");
	}
	
	private static bool		RunComputorForExpected(string expression, float? firstRoot, float? secondRoot)
	{
		ComputorV1.Main(new []{expression, "Test", "Verbose"});
		return AreRootsEqual(Equation.FirstRoot, firstRoot) && AreRootsEqual(Equation.SecondRoot, secondRoot);
	}

	private static bool		AreRootsEqual(float? a, float? b)
	{
		return a.HasValue == b.HasValue && Math.AlmostEquals(a.Value, b.Value, 0.001f);
	}
}
