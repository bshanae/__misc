public static partial class		Math
{
	public struct				Fraction
	{
		public float			Numerator
		{
			get ;
			private set ;
		}
		public float			Divider
		{
			get ;
			private set ;
		}

		public float			Value => Numerator / Divider;

		public					Fraction(float a, float b = 1f)
		{
			Numerator = a;
			Divider = b;
			
			Reduce();
		}

		public override string	ToString()
		{
			return IsWhole() ? $"{Numerator} / {Divider}" : Value.ToString();
		}

		private bool			IsWhole()
		{
			return Math.IsWhole(Numerator) && Math.IsWhole(Divider);
		}

		private void			Reduce()
		{
			if (!IsWhole())
				return ;
			
			int					gcd = GreatestCommonDivisor((int)Numerator, (int)Divider);
				
			Numerator /= gcd;
			Divider /= gcd;
		}
	}
}
