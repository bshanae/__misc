public static partial class	Math
{
	private const float		Epsilon = 0.00000000001f;

	#region					Public methods

	public static float		SquareRoot(float value)
	{
		float				low = 0f;
		float				high = value;
		float				middle = 0f;
		
		for(int i = 0 ; i < 1000 ; i++)
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

	public static bool		AlmostEqual(float a, float b, float epsilon = Epsilon)
	{
		return Absolute(a - b) < epsilon;
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