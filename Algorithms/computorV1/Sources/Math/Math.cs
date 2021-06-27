public static partial class	Math
{
	private const float		Epsilon = 0.00000000001f;

	#region					Public methods

	public static float		SquareRoot(float value)
	{
		float				low = 0f;
		float				high = value;
		float				middle = 0f;
		
		for (int i = 0 ; i < 1000 ; i++)
		{
		    middle = (low + high) / 2f;
			
		    if (AlmostEqual(middle * middle, value))
				return middle;
		    if (middle * middle > value)
				high = middle;
		    else
				low = middle;
		}

		return middle;
	}

	public static Complex	ComplexSquareRoot(float value)
	{
		if (value < 0f)
			return new Complex(0f, SquareRoot(-1f * value));
		else
			return new Complex(SquareRoot(value));
	}
	
	public static bool		AlmostEqual(float a, float b, float epsilon = Epsilon)
	{
		return Absolute(a - b) < epsilon;
	}
	
	public static bool		AlmostEqual(Complex a, Complex b, float epsilon = Epsilon)
	{
		return Absolute(a.RealPart - b.RealPart) < epsilon && Absolute(a.ImaginaryPart - b.ImaginaryPart) < epsilon;
	}
	
	public static float		Absolute(float value)
	{
		return value < 0 ? value * -1f : value;
	}

	private static int		Floor(float value)
	{
		int					intValue = (int)value;
		
		return value < intValue ? intValue - 1 : intValue;
	}
	
	public static bool		IsWhole(float value)
	{
		return AlmostEqual(Floor(value), value);
	}

	public static float		WholePower(float a, float b)
	{
		Error.Assert(IsWhole(a) && IsWhole(b));

		float				result = 1;
		
		if (b < 0)
		{
			for (int i = (int)b; i < 0; i++)
				result /= a;
		}
		else if (b > 0)
		{
			for (int i = (int)b; i > 0; i--)
				result *= a;
		}

		return result;
	}
	
	public static int		GreatestCommonDivisor(int a, int b)
	{
		int					temporary = b;
		
	    while (b != 0)
	    {
	        temporary = b;
	        b = a % b;
	        a = temporary;
	    }
		
	    return a;
	}

	public static float		Min(float a, float b) => a < b ? a : b;
	public static float		Max(float a, float b) => a > b ? a : b;
	
	public static int		Min(int a, int b) => a < b ? a : b;
	public static int		Max(int a, int b) => a > b ? a : b;

	#endregion
}