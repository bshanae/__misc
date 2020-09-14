public partial class 	Expression
{
	public class		UnaryMember : IMember
	{
		public Token	Token;

		public			UnaryMember(Token token = null)
		{
			Token = token;
		}

		public override string ToString()
		{
			return Token == null ? "?" : Token.ShortDescription();
		}
	}
}