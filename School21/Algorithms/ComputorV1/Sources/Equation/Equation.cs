using System;

public partial class		Equation
{
	private const int		MAXIMUM_POWER = 2;

	private Element			root;

	#region					Public methods
	
	public					Equation(Expression expression)
	{
		root = Element.Convert(expression.Root);

		Console.WriteLine("Equation :");
		Console.WriteLine(this);

		Reduce();
		
		Console.WriteLine("Reduced equation :");
		Console.WriteLine(this);
	}

	public override string	ToString()
	{
		return root.ToString();
	}
	
	#endregion
	
	#region					Private methods

	private void			Reduce()
	{
		root = ReduceHorizontally(root);
	}

	private static Element	ReduceHorizontally(Element element)
	{
		if (element is Operation operation)
		{
			for (int i = 0; i < operation.Children.Count; i++)
				operation.Children[i] = ReduceHorizontally(operation.Children[i]);
			
			if (!operation.OperatorType.CanCalculate())
				return element;
			
			int?			targetIndex = null;
			bool			shouldCheckPowers = operation.OperatorType.IsAnyOf(OperatorType.Addition, OperatorType.Subtraction);
			
			for (int i = 0; i < operation.Children.Count; i++)
			{
				if (!(operation.Children[i] is Term))
					continue;

				if (targetIndex == null)
				{
					targetIndex = i;
					continue;
				}
				
				var			targetTerm = operation.Children[targetIndex.Value] as Term;
				var			currentTerm = operation.Children[i] as Term;
				
				if (shouldCheckPowers && targetTerm.Power != currentTerm.Power)
					continue;

				operation.Children[targetIndex.Value] = operation.OperatorType.Calculate(targetTerm, currentTerm);
				operation.Children.RemoveAt(i--);
			}

			if (operation.Children.Count == 1)
				return operation.Children[0];
		}

		return element;
	}

	private static Element	ReduceVertically(Element element)
	{
		if (element is Operation operation && operation.OperatorType.CanCalculate())
		{
			
		}

		return null;
	}
	
	#endregion
}