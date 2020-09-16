public partial class 			Expression
{
	public class				Token : IElement
	{
		public global::Token	Value;

		public					Token(global::Token token = null)
		{
			Value = token;
		}

		public override string	ToString()
		{
			return Value == null ? "?" : Value.ShortDescription();
		}
	}
}