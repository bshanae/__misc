using System.Collections.Generic;
using System.Text;

namespace							Computor
{
	public static partial class		Analyzer
	{
		public class				NodeWithExpression : Node
		{
			public List<Node>		Nodes = new List<Node>();												
			
			public override string	ToString()
			{
				var					stringBuilder = new StringBuilder();
				
				stringBuilder.Append("{");

				for (int i = 0; i < Nodes.Count; i++)
				{
					stringBuilder.Append(Nodes[i]);
					if (i < Nodes.Count - 1)
						stringBuilder.Append(" ");
				}
				
				stringBuilder.Append("}");

				return stringBuilder.ToString();
			}
		}
	}
}