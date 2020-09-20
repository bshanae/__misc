public static partial class		Math
{
	public struct				Fraction
	{
//								TODO Change names
		public float			_A_ { get ; }
		public float			_B_ { get ; }

		public float			_C_ => _A_ / _B_;

		public					Fraction(float a, float b = 1f)
		{
			_A_ = a;
			_B_ = b;
			
			Reduce();
		}

		public override string	ToString()
		{
			return IsWhole(_A_) && IsWhole(_B_) ? $"{_A_} / {_B_}" : _C_.ToString();
		}

		private void			Reduce()
		{
//								TODO Implement this 
		}
	}
}
