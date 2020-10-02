namespace 					Equation
{
	public abstract	class	Operand : Token
	{
		public float		Factor = 1f;

		
		protected			Operand(string @string) : base(@string)
		{ }
	}
}