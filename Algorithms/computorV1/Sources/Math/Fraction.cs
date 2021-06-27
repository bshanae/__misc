using Computor;

public static partial class				Math
{
	public struct						Fraction
	{
		public float					Numerator
		{
			get ;
			private set ;
		}
		public float					Denominator
		{
			get ;
			private set ;
		}

		public float					Value => Numerator / Denominator;

		public							Fraction(float a, float b = 1f)
		{
			Numerator = a;
			Denominator = b;
			
			Reduce();
		}
		
		public static implicit operator	Fraction(float value) => new Fraction(value);
		
		public bool						IsWhole()
		{
			return Math.IsWhole(Numerator) && Math.IsWhole(Denominator);
		}

		private void					Reduce()
		{
			if (!IsWhole())
				return ;
			
			int							gcd = GreatestCommonDivisor((int)Numerator, (int)Denominator);
				
			Numerator /= gcd;
			Denominator /= gcd;

			if (Denominator < 0f)
			{
				Numerator *= -1f;
				Denominator *= -1f;
			}
		}

		public static bool				operator == (Fraction left, Fraction right) =>
			left.Denominator == right.Denominator && left.Numerator == right.Numerator;
		
		public static bool				operator != (Fraction left, Fraction right)
		{
			return
				left.Denominator != right.Denominator ||
				left.Numerator != right.Numerator;
		}
		
		public override string			ToString()
		{
			if (IsWhole())
				return Denominator != 1f ? $"{Numerator} / {Denominator}" : $"{Numerator}";
			else
				return Value.ToStandardString();
		}
	}
}