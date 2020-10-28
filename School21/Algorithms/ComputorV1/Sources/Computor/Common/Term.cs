namespace						Computor
{
	public class				Term
	{
		public float			Factor;
		public float			Power;

		public static Term		FromConstant(Constant constant)
		{
			return new Term(constant.Value * constant.Factor, 0f);
		}
		
		public static Term		FromVariable(Variable variable)
		{
			return new Term(variable.Factor, 1f);
		}
		
		private					Term(float factor, float power)
		{
			Factor = factor;
			Power = power;
		}
		
		public					Term(Term otherTerm)
		{
			Factor = otherTerm.Factor;
			Power = otherTerm.Power;
		}

		public static Term		Aggregate(Term left, Term right, Operator.Types type)
		{
			switch (type)
			{
				case Operator.Types.Addition :
					return left + right;
					
				case Operator.Types.Subtraction :
					return left - right;
					
				case Operator.Types.Multiplication :
					return left * right;
					
				case Operator.Types.Division :
					return left / right;
					
				case Operator.Types.Power :
					return left ^ right;
					
				default :
					Error.RaiseInternalError();
					return null;
			}
		}

		public static Term		operator + (Term left, Term right)
		{
			Error.Assert(left.Power == right.Power);
			return new Term(left.Factor + right.Factor, left.Power);
		}
		
		public static Term		operator - (Term left, Term right)
		{
			Error.Assert(left.Power == right.Power);
			return new Term(left.Factor - right.Factor, left.Power);
		}
		
		public static Term		operator * (Term left, Term right)
		{
			return new Term(left.Factor * right.Factor, left.Power + right.Power);
		}
		
		public static Term		operator / (Term left, Term right)
		{
			return new Term(left.Factor / right.Factor, left.Power - right.Power);
		}
		
		public static Term		operator ^ (Term left, Term right)
		{
			Error.Assert(right.Power == 0f);
			if (left.Power == 0)
				return new Term(Math.WholePower(left.Factor, right.Factor), 0);
			else
				return new Term(left.Factor, left.Power * right.Factor);
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