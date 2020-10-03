public static partial class		Math
{
	public struct				Fraction
	{
		public float			Numerator
		{
			get ;
			private set ;
		}
		public float			Denominator
		{
			get ;
			private set ;
		}

		public float			Value => Numerator / Denominator;

		public					Fraction(float a, float b = 1f)
		{
			Numerator = a;
			Denominator = b;
			
			Reduce();
		}

		public override string	ToString()
		{
			return IsWhole() ? $"{Numerator} / {Denominator}" : Value.ToString();
		}

		private bool			IsWhole()
		{
			return Math.IsWhole(Numerator) && Math.IsWhole(Denominator);
		}

		private void			Reduce()
		{
			if (!IsWhole())
				return ;
			
			int					gcd = GreatestCommonDivisor((int)Numerator, (int)Denominator);
				
			Numerator /= gcd;
			Denominator /= gcd;
		}
	}
}