namespace						Computor
{
	public struct				Term
	{
		public readonly float	Factor;
		public readonly float	Power;

		public					Term(float factor = 1f, float power = 1f)
		{
			Factor = factor;
			Power = power;
		}
	}
}