using System;

namespace							Computor
{
	public static partial class		Analyzer
	{
		#region						Main methods
		
		public static void			CollectTerms()
		{
			foreach (var token in Workspace.Tokens)
				Workspace.Nodes.Add(new NodeWithToken(token));
			Log("Parsed nodes");

			CollectExpressionsByPriority(3);
			Log("Collected expression of priority 3");
			
			CollectExpressionsByPriority(2);
			Log("Collected expression of priority 2");
			
			CollectExpressionsByPriority(1);
			Log("Collected expression of priority 1");
			
			CollectExpressionsByPriority(0);
			Log("Collected expression of priority 0");
		}
		
		private static void			Log(string message)
		{
			Console.WriteLine(message + " : ");
			
			for (int i = 0; i < Workspace.Nodes.Count; i++)
			{
				Console.Write(Workspace.Nodes[i]);
				if (i < Workspace.Nodes.Count - 1)
					Console.Write(" ");	
			}

			Console.WriteLine();
		}
		
		#endregion
		
		#region						Private methods

		private static void			CollectExpressionsByPriority(int priority)
		{
			bool					IsUsefulOperator(int index)
			{
				return
					Workspace.Nodes[index] is NodeWithToken nodeWithToken &&
					nodeWithToken.token is Operator @operator &&
					@operator.Type.GetPriority() == priority;
			}
			
			for (int i = 0; i < Workspace.Nodes.Count; i++)
				if (IsUsefulOperator(i))
				{
					CheckIndex(i - 1);
					CheckIndex(i + 1);

					int			totalRemovedNodes = 1;
					var			newNode = new NodeWithExpression();

					newNode.Nodes.Add(Workspace.Nodes[i - 1]);

					for (int j = i; j < Workspace.Nodes.Count; j += 2)
						if (IsUsefulOperator(j))
						{
							CheckIndex(j + 1);

							newNode.Nodes.Add(Workspace.Nodes[j]);
							newNode.Nodes.Add(Workspace.Nodes[j + 1]);

							totalRemovedNodes += 2;
						}
						else
							break ;

					Workspace.Nodes.RemoveRange(i - 1, totalRemovedNodes);
					Workspace.Nodes.Insert(i - 1, newNode);

					i--;
				}
		}

		private static void			CheckIndex(int index)
		{
			if (index < 0 || index > Workspace.Nodes.Count - 1)
				throw new Exception("[Analyzer] Invalid node index");
		}
		
		#endregion
	}
}