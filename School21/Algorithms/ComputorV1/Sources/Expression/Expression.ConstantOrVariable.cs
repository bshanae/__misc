public partial class 	Expression
{
	public class		ConstantOrVariable : Element
	{
		public Token	Token;

		public			ConstantOrVariable(Token token = null)
		{
			Token = token;
		}

		public override string ToString()
		{
			return Token == null ? "?" : Token.ShortDescription();
		}
	}
}