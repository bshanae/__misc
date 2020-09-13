
public class				UnaryGroup : IGroup
{
	public Token			Token;

	public					UnaryGroup(Token token = null)
	{
		Token = token;
	}

	public override string	ToString()
	{
		return Token == null ? "?" : Token.ShortDescription();
	}
}