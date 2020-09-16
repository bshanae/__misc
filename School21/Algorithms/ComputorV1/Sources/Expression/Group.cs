public partial class			Expression
{
	public class				Group : IComplexElement
	{
		public override string	ToString()
		{
			var					result = "";

			result += "(";
			
			foreach (var child in Children)
				result += child;

			result += ")";

			return result;
		}
	}
}