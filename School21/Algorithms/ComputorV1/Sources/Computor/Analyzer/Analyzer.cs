using System;

namespace										Computor
{
	public static class							Analyzer
	{
		private static void						Log(string message)
		{
			Console.WriteLine(message);
			Console.WriteLine(Workspace.FinalHolder);
		}
		
		public static void						BuildElements()
		{
			foreach (var token in Workspace.Tokens)
				switch (token)
				{
					case Constant constant :
						Workspace.FinalGroup.AddHolder().ConnectElement(new ElementWithTerm(Term.FromConstant(constant)));
						break;
					
					case Variable variable :
						Workspace.FinalGroup.AddHolder().ConnectElement(new ElementWithTerm(Term.FromVariable(variable)));
						break;
					
					case Operator @operator :
						Workspace.FinalGroup.AddHolder().ConnectElement(new ElementWithOperator(@operator));
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
								
								Workspace.FinalGroup.AddHolder(i - 1).ConnectElement(group);
								group.AddHolder().ConnectElement(Workspace.FinalGroup[i].Element);

								Workspace.FinalGroup.Refresh();
							}
							
							group.AddHolder().ConnectElement(Workspace.FinalGroup[i + 0].Element);
							group.AddHolder().ConnectElement(Workspace.FinalGroup[i + 1].Element);
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

		public static void						ExtractTerms()
		{
			Error.Assert(Workspace.FinalGroup.Count == 3);
			
			if (Workspace.FinalGroup[0].Element is ElementWithTerm elementWithTerm)
				Workspace.Terms.Add(elementWithTerm.Term);
			else if (Workspace.FinalGroup[0].Element is Group group)
			{
				float							nextElementSign = 1f;
				
				foreach (var holder in group)
					if (holder.Element is ElementWithTerm childElementWithTerm)
					{
						childElementWithTerm.Term.Factor *= nextElementSign;
						Workspace.Terms.Add(childElementWithTerm.Term);
					}
					else if (holder.Element is ElementWithOperator elementWithOperator)
					{
						if (elementWithOperator.Operator.Type == Operator.Types.Addition)
							nextElementSign = 1f;
						else if (elementWithOperator.Operator.Type == Operator.Types.Subtraction)
							nextElementSign = -1f;
						else
							Error.RaiseInternalError();
					}
					else
						Error.RaiseInternalError();
			}
			else
				Error.RaiseInternalError();
		}

		public static void						SortTerms()
		{
			foreach (var term in Workspace.Terms)
			{
				Error.Assert(!Workspace.SortedTerms.ContainsKey((int)term.Power));
				Workspace.SortedTerms[(int)term.Power] = term;
			}
		}
	}
}