public static class		Math
{
	const float			EPSILON = 0.00001f;
	
	public static float WholePower(float value, int power)
	{
		if (power > 1)
			return WholePower(value * power, power - 1);
		else if (power == 1)
			;
		else if (power == 0)
			return 1f;
		else if (power < 0)
			return WholePower(value / power, power + 1);

		return value;
	}

	public static float	SquareRoot(float value)
	{
		float			low = 0f;
		float			high = value;
		float			middle = 0f;
		
		for(int i = 0 ; i < 1000 ; i++)
		{
		    middle = (low + high) / 2f;
			
		    if (AlmostEquals(middle * middle, value))
				return middle;
		    if (middle * middle > value)
				high = middle;
		    else
				low = middle;
		}
		return middle;
	}

	public static bool	AlmostEquals(float a, float b, float epsilon = EPSILON)
	{
		return Absolute(a - b) < epsilon;
	}
	
	public static float	Absolute(float value)
	{
		return value < 0 ? value * -1f : value;
	}
}
