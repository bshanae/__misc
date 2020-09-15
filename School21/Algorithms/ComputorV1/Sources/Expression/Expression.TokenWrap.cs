public partial class 			Expression
{
	public class				TokenWrap : IElement
	{
		public Token			Token;

		public					TokenWrap(Token token = null)
		{
			Token = token;
		}

		public override string	ToString()
		{
			return Token == null ? "?" : Token.ShortDescription();
		}
	}
}