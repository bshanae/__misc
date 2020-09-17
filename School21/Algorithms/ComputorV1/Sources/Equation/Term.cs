using System;

public partial class			Equation
{
	public class				Term : Element
	{
		public float			Factor
		{ get; }
		
		public int				Power
		{ get; }

		public					Term(float factor, int power)
		{
			Factor = factor;
			Power = power;
		}
		public					Term(Expression.Token token)
		{
			if (token.Value is Constant constant)
			{
				Factor = constant.Value;
				Power = 0;
			}
			else if (token.Value is Variable variable)
			{
				Factor = 1;
				Power = 1;	
			}
			else
				Error.Raise("Can't create equation term");
		}
		
		public override string	ToString()
		{
			string				result = "";

			bool				writeFactor = Factor != 1f;
			bool				writeName = Power > 0;
			bool				writePower = Power > 1;

			if (!writeName && !writePower)
				writeFactor = true;

			if (writeFactor)
				result += Factor;

			if (writeFactor && writeName)
				result += " * ";
			
			if (writeName)
				result += "x";
			
			if (writePower)
				result += " ^ " + Power;
			
			return result;
		}
	}
}