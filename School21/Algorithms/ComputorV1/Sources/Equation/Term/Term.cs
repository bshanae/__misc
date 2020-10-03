namespace						Equation
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

		public override string	ToString()
		{
			bool				shouldShowFactor;
			bool				shouldShowVariable;
			bool				shouldShowPower;

			shouldShowVariable = Power != 0f;
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