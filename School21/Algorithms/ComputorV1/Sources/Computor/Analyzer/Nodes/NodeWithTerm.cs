namespace							Computor
{
	public static partial class		Analyzer
	{
		public class				NodeWithTerm : Node
		{
			public readonly Term	Term;

			public					NodeWithTerm(Term term)
			{
				Term = term;
			}
			
			public override string	ToString()
			{
				return Term.ToString();
			}
		}
	}
}