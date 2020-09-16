using System;

public partial class		Equation
{
	public class			Term
	{
		public float		Factor
		{ get; }
		
		public int			Power
		{ get; }

							Term(float factor, int power)
		{
			Factor = factor;
			Power = power;
		}
	
	}
}