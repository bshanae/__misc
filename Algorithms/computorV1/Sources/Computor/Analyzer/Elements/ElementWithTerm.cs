namespace								Computor
{
	public class						ElementWithTerm : Element
	{
		public readonly Term			Term;
		
		public							ElementWithTerm(Term term)
		{
			Term = term;
		}

		public override string			ToString()
		{
			return "[" + Term + "]";
		}
	}
}