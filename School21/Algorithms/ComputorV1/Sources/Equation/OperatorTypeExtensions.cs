using static Equation;

public static partial class	OperatorTypeExtensions
{
	public static Term		Calculate(this OperatorType type, Term left, Term right)
	{
		switch (type)
		{
			case OperatorType.Addition :
			case OperatorType.Subtraction :
				Error.Assert(left.Power == right.Power);
				break;
				
			case OperatorType.Power :
				Error.Assert(right.Power == 0);
				break;
		}
		
		switch (type)
		{
			case OperatorType.Addition :
				return new Term(left.Factor + right.Factor, left.Power);
				
			case OperatorType.Subtraction :
				return new Term(left.Factor - right.Factor, left.Power);
				
			case OperatorType.Multiplication :
				return new Term(left.Factor * right.Factor, left.Power + right.Power);
				
			case OperatorType.Division :
				return new Term(left.Factor / right.Factor, left.Power - right.Power);
				
			case OperatorType.Power :
				return new Term(left.Factor, left.Power + right.Power);
				
			default :
				Error.Raise();
				return null;
		}
	}
}
