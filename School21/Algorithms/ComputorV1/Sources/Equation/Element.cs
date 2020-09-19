using System;

public partial class			Equation
{
	public abstract class		Element : ICloneable
	{
		public static Element	Convert(Expression.Element element)
		{
			switch (element)
			{
				case Expression.Token token :
					return new Term(token);
				
				case Expression.Operation operation :
					return new Operation(operation);
			}
			
			Error.Raise("Can't create Equation.Element from Expression.Element");
			return null;
		}

		public abstract object	Clone();
	}
}