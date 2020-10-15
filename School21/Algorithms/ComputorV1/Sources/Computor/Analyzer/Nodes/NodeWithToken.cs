namespace							Computor
{
	public static partial class		Analyzer
	{
		public class				NodeWithToken : Node
		{
			public readonly Token	token;

			public					NodeWithToken(Token token)
			{
				this.token = token;
			}
			
			public override string	ToString()
			{
				return token.ToString();
			}
		}
	}
}