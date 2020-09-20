public static partial class		Math
{
	public struct				Fraction
	{
		public float			Numerator { get ; }
		public float			Divider { get ; }

		public float			Value => Numerator / Divider;

		public					Fraction(float a, float b = 1f)
		{
			Numerator = a;
			Divider = b;
			
			Reduce();
		}

		public override string	ToString()
		{
			return IsWhole(Numerator) && IsWhole(Divider) ? $"{Numerator} / {Divider}" : Value.ToString();
		}

		private void			Reduce()
		{
//								TODO Implement this 
		}
	}
}
