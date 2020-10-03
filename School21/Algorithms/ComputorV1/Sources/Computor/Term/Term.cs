using System;

namespace						Computor
{
	public class				Term
	{
		public float			Factor;
		public float			Power;

		public					Term(float factor = 1f, float power = 1f)
		{
			Factor = factor;
			Power = power;
		}

		public static Term		Sum(Term left, Term right)
		{
			if (left.Power != right.Power)
				throw new Exception("[Equation.Term, Sum] Can't sum terms with different powers");
			
			return new Term(left.Factor + right.Factor, left.Power);
		}

		public override string	ToString()
		{
			bool				shouldShowFactor;
			bool				shouldShowVariable;
			bool				shouldShowPower;

			shouldShowVariable = Factor != 0f && Power != 0f;
			shouldShowPower = Power != 0f && Power != 1f;
			shouldShowFactor = Factor != 1f || !shouldShowVariable;

			string				result = "";

			if (shouldShowFactor)
				result += $"{Factor}";
			if (shouldShowFactor && shouldShowVariable)
				result += " * ";
			if (shouldShowVariable)
				result += "x";
			if (shouldShowPower)
				result += $" ^ {Power}";

			return result;
		}
	}
}