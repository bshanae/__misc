using System;

namespace										Computor
{
	public static class							Analyzer
	{
		private static void						Log(string message)
		{
			Console.WriteLine(message);
			Console.WriteLine(string.Join(", ", Workspace.FinalGroup));
		}
		
		public static void						BuildElements()
		{
			foreach (var token in Workspace.Tokens)
				switch (token)
				{
					case Constant constant :
						new ElementWithTerm(Term.FromConstant(constant)).Place(Workspace.FinalGroup.AddHolder());
						break;
					
					case Variable variable :
						new ElementWithTerm(Term.FromVariable(variable)).Place(Workspace.FinalGroup.AddHolder());
						break;
					
					case Operator @operator :
						new ElementWithOperator(@operator).Place(Workspace.FinalGroup.AddHolder());
						break;
				}
			
			Log("Built elements");
		}
		
		public static void						GroupElements()
		{
			GroupElementsByPriority(Operator.Priorities.Power);
			Log("Grouped elements A : ");
			
			GroupElementsByPriority(Operator.Priorities.MultiplicationAndDivision);
			Log("Grouped elements B : ");
			
			GroupElementsByPriority(Operator.Priorities.AdditionAndSubtraction);
			Log("Grouped elements C : ");
			
			GroupElementsByPriority(Operator.Priorities.Equality);
			Log("Grouped elements D : ");

			static void							GroupElementsByPriority(Operator.Priorities priority)
			{
				Group							group;
				
				for (int i = 0; i < Workspace.FinalGroup.Count; i++)
					if (Workspace.FinalGroup[i].Element is ElementWithOperator elementWithOperator)
						if (elementWithOperator.Operator.TypePriority == priority)
						{
							Workspace.FinalGroup.ValidateIndex(i - 1);
							Workspace.FinalGroup.ValidateIndex(i + 1);
							
							if (Workspace.FinalGroup[i - 1].Element is Group testGroup && testGroup.Priority == priority)
							{
								group = testGroup;
							}
							else
							{
								group = new Group(priority);
								
								Workspace.FinalGroup.AddHolder(i - 1).Place(group);
								Workspace.FinalGroup[i].Element.Replace(group.AddHolder());
								Workspace.FinalGroup.Refresh();
							}
							
							Workspace.FinalGroup[i + 0].Element.Replace(group.AddHolder());
							Workspace.FinalGroup[i + 1].Element.Replace(group.AddHolder());
								
							Workspace.FinalGroup.Refresh();
							i--;
						}
			}
		}

		public static void						ReduceElements()
		{
			ReduceGroupsOfPriority(Operator.Priorities.Power);
			Log("Reduced elements A : ");
			
			ReduceGroupsOfPriority(Operator.Priorities.MultiplicationAndDivision);
			Log("Reduced elements B : ");
			
			ReduceGroupsOfPriority(Operator.Priorities.Equality);
			Log("Reduced elements D : ");
			
			ReduceGroupsOfPriority(Operator.Priorities.AdditionAndSubtraction);
			Log("Reduced elements C : ");

			static void							ReduceGroupsOfPriority(Operator.Priorities priority)
			{
				foreach (var holder in Workspace.FinalGroup)
					ReduceRecursively(holder);
				
				void							ReduceRecursively(Holder holder)
				{
					if (holder.Element is Group group)
					{
						group.ForEach(ReduceRecursively);

						if (group.Priority == priority)
						{
							group.TryReduce();
							group.Refresh();
						}
					}
				}
			}
		}

	}
}