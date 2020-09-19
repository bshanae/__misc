public static partial class		Expression
{
	public class				Token : Element
	{
		public global::Token	Value;

		public					Token(global::Token token = null)
		{
			Value = token;
		}

		public override object	Clone()
		{
			return new Token(Value);
		}

		public override string	ToString()
		{
			return Value == null ? "?" : Value.ShortDescription();
		}
	}
}