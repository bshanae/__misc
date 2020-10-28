using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace									Computor
{
	public class							Group : Element, IEnumerable<Holder>, ICollection
	{
		private const bool					FlatRepresentation = true;
		
		public readonly Operator.Priorities	Priority;
		private readonly List<Holder>		_holders = new List<Holder>();
		
		public Holder						this[int index] => _holders[index];

		public int							Count => _holders.Count;
		
		public bool							IsSynchronized => true;
		public object						SyncRoot => null;

		public								Group(Operator.Priorities purpose)
		{
			Priority = purpose;
		}

		public Holder						AddHolder(int index = -1)
		{
			var								holder = new Holder();
			
			if (index == -1)
				_holders.Add(holder);
			else
				_holders.Insert(index, holder);
			
			return holder;
		}

		public void							RemoveHolder(int index)
		{
			RemoveHolders(index, 1);
		}

		public void							RemoveHolders(int index, int count)
		{
			_holders.RemoveRange(index, count);
		}

		public void							ClearHolders()
		{
			_holders.Clear();
		}

		public void							ForEach(Action<Holder> action)
		{
		    foreach (var item in this)
		        action(item);
		}
		
		public void							CopyTo(Array array, int index)
		{
			throw new NotImplementedException();
		}

		public void							TryReduce()
		{
			switch (Priority)
			{
				case Operator.Priorities.Power :
					ReducePower();
					break;
					 
				case Operator.Priorities.MultiplicationAndDivision :
					ReduceMultiplicationAndDivision();
					break;
					 
				case Operator.Priorities.AdditionAndSubtraction :
					ReduceAdditionAndSubtraction();
					break;
				
				case Operator.Priorities.Equality :
					ReduceEquality();
					break;
			}

			void							ReducePower()
			{
				var							lastIndex = Count - 1;
				Term						rightTerm;

				Error.Assert(this[lastIndex].Element is ElementWithTerm);
				rightTerm = ((ElementWithTerm)this[lastIndex].Element).Term;
				
				for (int i = lastIndex - 1; i >= 0; i -= 2)
				{
					this.ValidateIndex(i);
					this.ValidateIndex(i - 1);

					var						elementWithOperator = this[i].Element as ElementWithOperator;
					var						elementWithTerm = this[i - 1].Element as ElementWithTerm;
						
					Error.Assert(elementWithOperator != null && elementWithTerm != null);

					rightTerm = Term.Aggregate
					(
						elementWithTerm.Term,
						rightTerm,
						elementWithOperator.Operator.Type
					);
				}
				
				ClearHolders();
				new ElementWithTerm(rightTerm).ConnectHolder(AddHolder());
			}

			void							ReduceMultiplicationAndDivision()
			{
				Error.Assert(this[0].Element is ElementWithTerm);
				
				var							leftTerm = ((ElementWithTerm)this[0].Element).Term;

				for (int i = 1; i < Count; i += 2)
				{
					this.ValidateIndex(i);
					this.ValidateIndex(i + 1);
					
					var						elementWithOperator = this[i].Element as ElementWithOperator;
					var						elementWithTerm = this[i + 1].Element as ElementWithTerm;
						
					Error.Assert(elementWithOperator != null && elementWithTerm != null);

					leftTerm = Term.Aggregate
					(
						leftTerm, 
						elementWithTerm.Term,
						elementWithOperator.Operator.Type
					);
				}
					
				ClearHolders();
				new ElementWithTerm(leftTerm).ConnectHolder(AddHolder());
			}
			
			void							ReduceAdditionAndSubtraction()
			{
				for (int i = 0; i < Count; i += 2)
				{
					Error.Assert(this[i].Element is ElementWithTerm);
					
					var						targetTerm = ((ElementWithTerm)this[i].Element).Term;

					for (int j = i + 1; j < Count;)
					{
						this.ValidateIndex(j);
						this.ValidateIndex(j + 1);
						
						var					elementWithOperator = this[j].Element as ElementWithOperator;
						var					elementWithTerm = this[j + 1].Element as ElementWithTerm;
						
						Error.Assert(elementWithOperator != null && elementWithTerm != null);

						if (targetTerm.Power == elementWithTerm.Term.Power)
						{
							targetTerm = Term.Aggregate
							(
								targetTerm,
								elementWithTerm.Term,
								elementWithOperator.Operator.Type
							);

							RemoveHolders(j, 2);
							this[i].ConnectElement(new ElementWithTerm(targetTerm));
						}
						else
							j += 2;
					}
				}
			}

			void							ReduceEquality()
			{
				Error.Assert
				(
					this[1].Element is ElementWithOperator @operator &&
					@operator.Operator.Type == Operator.Types.Equality &&
					Count == 3
				);
				
				var							leftGroup = WrapInGroupIfNeeded(this[0].Element);
				var							rightGroup = WrapInGroupIfNeeded(this[2].Element);

				if (rightGroup.Count > 0)
					new ElementWithOperator(new Operator("-")).ConnectHolder(leftGroup.AddHolder());

				foreach (var holder in rightGroup)
					if (holder.Element is ElementWithOperator elementWithOperator)
					{
						if (elementWithOperator.Operator.Type == Operator.Types.Addition)
							leftGroup.AddHolder().ConnectElement(new ElementWithOperator(new Operator("-")));
						else if (elementWithOperator.Operator.Type == Operator.Types.Subtraction)
							leftGroup.AddHolder().ConnectElement(new ElementWithOperator(new Operator("+")));
						else
							Error.RaiseInternalError();
					}
					else if (holder.Element is ElementWithTerm)
						leftGroup.AddHolder().ConnectElement(holder.Element);
					else
						Error.RaiseInternalError();
				
				ClearHolders();
				Refresh();

				Group						WrapInGroupIfNeeded(Element element)
				{
					if (element is Group group)
						return group;
					else if (element is ElementWithTerm)
					{
						Group				newGroup;
						
						newGroup = new Group(Operator.Priorities.AdditionAndSubtraction);
						newGroup.AddHolder().ConnectElement(element);

						return newGroup;
					}
					
					Error.RaiseInternalError();
					return null;
				}
			}
		}

		public void							Refresh()
		{
			for (int i = 0; i < Count; i++)
				if (this[i].HasElement)
					RemoveHolder(i--);

			if (Holder != null)
			{
				if (Count == 0)
					DisconnectHolder();
				else if (Count == 1)
					DisconnectHolder().ConnectElement(this[0].Element);
			}
		}

		public override string				ToString()
		{
			if (FlatRepresentation)
				return $"{{{string.Join(", ", this.ToList())}}}";
			else
			{
				var							stringBuilder = new StringBuilder();
				
				WriteRecursively(this, 0);
				return stringBuilder.ToString();
	
				void						WriteRecursively(Group group, int indentCount)
				{
					string					bracketsIndentation = MultiplyIndents(indentCount);
					string					bodyIndentation = MultiplyIndents(indentCount + 1);
					
					stringBuilder.Append(bracketsIndentation + "{" + "\n");
	
					foreach (var holder in group._holders)
						if (holder.Element is Group childGroup)
							WriteRecursively(childGroup, indentCount + 1);
						else
							stringBuilder.Append(bodyIndentation + holder.Element + "\n");
	
					stringBuilder.Append(bracketsIndentation + "}" + "\n");
				}
	
				static string				MultiplyIndents(int number)
				{
					var						tabBuilder = new StringBuilder();
	
					for (int i = 0; i < number; i++)
						tabBuilder.Append("  ");
	
					return tabBuilder.ToString();
				}
			}
		}

		public IEnumerator<Holder>			GetEnumerator() => _holders.GetEnumerator();
		IEnumerator							IEnumerable.GetEnumerator() => _holders.GetEnumerator();
	}
}