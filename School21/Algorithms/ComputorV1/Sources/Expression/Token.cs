public partial class 			Expression
{
	public class				Token : Element
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