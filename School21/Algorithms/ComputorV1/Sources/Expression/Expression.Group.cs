using System.Collections.Generic;

public partial class			Expression
{
	public class				Group : Element
	{
		public List<Element>	Children;

		public					Group()
		{
			Children = new List<Element>();
		}

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