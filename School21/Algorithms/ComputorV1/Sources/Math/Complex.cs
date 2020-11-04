using Computor;

public static partial class				Math
{
	public struct						Complex
	{
		public float					RealPart { get; }
		public float					ImaginaryPart { get; }

		public bool						IsReal => ImaginaryPart == 0f;
		public bool						IsImaginary => ImaginaryPart != 0f;

		public							Complex(float realPart, float imaginaryPart = 0f)
		{
			RealPart = realPart;
			ImaginaryPart = imaginaryPart;
		}
		
		public							Complex(Complex complex)
		{
			RealPart = complex.RealPart;
			ImaginaryPart = complex.ImaginaryPart;
		}
		
		public static implicit operator	Complex(float value) => new Complex(value);
		
		public static Complex			operator + (Complex complex) => new Complex(complex);
		public static Complex			operator - (Complex complex) => new Complex(-complex.RealPart, -complex.ImaginaryPart);

		public static Complex			operator + (Complex left, Complex right) =>
			new Complex(left.RealPart + right.RealPart, left.ImaginaryPart + right.ImaginaryPart);
		
		public static Complex			operator - (Complex left, Complex right) =>
			new Complex(left.RealPart - right.RealPart, left.ImaginaryPart - right.ImaginaryPart);
		
		public static Complex			operator * (Complex left, Complex right)
		{
			Error.Assert(!right.IsImaginary);
			
			// This functionality is limited and doesn't support complete complex number properties!
			return new Complex(left.RealPart * right.RealPart, left.ImaginaryPart * right.RealPart);
		}
		
		public static Complex			operator * (Complex complex, float real) =>
			new Complex(complex.RealPart * real, complex.ImaginaryPart * real);
		
		public static Complex			operator / (Complex left, Complex right)
		{
			Error.Assert(!right.IsImaginary);

			// This functionality is limited and doesn't support complete complex number properties!
			return new Complex(left.RealPart / right.RealPart, left.ImaginaryPart / right.RealPart);
		}

		public static Complex			operator / (Complex complex, float real) =>
			new Complex(complex.RealPart / real, complex.ImaginaryPart / real);

		public static bool				operator == (Complex left, Complex right) =>
			left.RealPart == right.RealPart && left.ImaginaryPart == right.ImaginaryPart;
		
		public static bool				operator != (Complex left, Complex right) =>
			left.RealPart != right.RealPart || left.ImaginaryPart != right.ImaginaryPart;

		public override string			ToString()
		{
			if (ImaginaryPart > 0f)
				return RealPart.ToStandardString() + " + " + ImaginaryPart.ToStandardString() + "i";
			else if (ImaginaryPart < 0f)
				return RealPart.ToStandardString() + " - " + (-1f * ImaginaryPart).ToStandardString() + "i";
			else
				return RealPart.ToStandardString();
		}
	}
}