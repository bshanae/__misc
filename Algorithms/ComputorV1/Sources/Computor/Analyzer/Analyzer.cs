namespace										Computor
{
	public static class							Analyzer
	{
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
		}
		
		public static void						GroupElements(Operator.Priorities priority)
		{
			Group								group;

			for (int i = 0; i < Workspace.FinalGroup.Count; i++)
			{
				if (Workspace.FinalGroup[i].Element is ElementWithOperator elementWithOperator)
				{
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
		}

		public static void						ReduceElements(Operator.Priorities priority)
		{
			foreach (var holder in Workspace.FinalGroup)
				ReduceRecursively(holder);
			
			void								ReduceRecursively(Holder holder)
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

		public static void						ExtractTerms()
		{
			bool								didEncounterEquality = false;
			Operator.Types						lastOperatorType = Operator.Types.Undefined;

			Workspace.FinalGroup.ForEach(holder => ProcessElement(holder.Element));

			void								ProcessElement(Element element)
			{
				if (element is ElementWithTerm elementWithTerm)
				{
					elementWithTerm.Term.Factor *= GetMultiplier();
					Workspace.Terms.Add(elementWithTerm.Term);
				}
				else if (element is ElementWithOperator elementWithOperator)
				{
					Error.Assert
					(
						elementWithOperator.Operator.IsAnyOf
						(
							Operator.Types.Addition,
							Operator.Types.Subtraction,
							Operator.Types.Equality
						)
					);
					
					lastOperatorType = elementWithOperator.Operator.Type;
					didEncounterEquality = didEncounterEquality || lastOperatorType == Operator.Types.Equality;
				}
				else if (element is Group group)
				{
					Error.Assert(group.Priority == Operator.Priorities.AdditionAndSubtraction);
					group.ForEach(holder => ProcessElement(holder.Element));
				}
				else
					Error.RaiseInternalError();
			}

			float								GetMultiplier()
			{
				return
					(lastOperatorType == Operator.Types.Subtraction ? -1f : 1f)
					*
					(didEncounterEquality ? -1f : 1f);
			}
		}

		public static void						SortTerms()
		{
			foreach (var term in Workspace.Terms)
			{
				var								power = (int)term.Power;

				if (!Workspace.SortedTerms.ContainsKey(power))
					Workspace.SortedTerms[(int) term.Power] = term;
				else
					Workspace.SortedTerms[(int) term.Power] = Workspace.SortedTerms[(int) term.Power] + term;
			}
		}
	}
}