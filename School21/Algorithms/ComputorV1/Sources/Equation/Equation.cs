using System;
using System.Collections.Generic;

public partial class					Equation
{
	private const int					MAXIMUM_POWER = 2;

	private Element						elementsRoot;
	private Dictionary<int, List<Term>>	sortedTerms;

	#region								Public methods
	
	public								Equation(Expression expression)
	{
		elementsRoot = Element.Convert(expression.Root);

		Console.WriteLine("Equation :");
		Console.WriteLine(elementsRoot);

		MoveAllTermToLeftSide();
		Console.WriteLine("Move all terms to left side :");
		Console.WriteLine(elementsRoot);
		
		ConvertOperation(OperatorType.Division);
		Console.WriteLine("Converted division to multiplication :");
		Console.WriteLine(elementsRoot);
		
		ConvertOperation(OperatorType.Subtraction);
		Console.WriteLine("Converted subtraction to addition :");
		Console.WriteLine(elementsRoot);
		
		Reduce();
		Console.WriteLine("Reduced equation :");
		Console.WriteLine(elementsRoot);
		
		SortTerms();
		Console.WriteLine("Sorted terms :");
		foreach (var keyValue in sortedTerms)
		{
			int							power = keyValue.Key;
			List<Term>					terms = keyValue.Value;

			if (terms.Count > 0)
			{
				Console.Write($"Power {power} : ");

				for (int i = 0; i < terms.Count; i++)
				{
					Console.Write(terms[i]);
					if (i < terms.Count - 1)
						Console.Write(", ");
				}

				Console.WriteLine();
			}
		}
	}

	public override string				ToString()
	{
		return elementsRoot.ToString();
	}
	
	#endregion
	
	#region								Private methods

	private void						MoveAllTermToLeftSide()
	{
		if (elementsRoot is Operation operation && operation.OperatorType == OperatorType.Equality)
			elementsRoot = new Operation(OperatorType.Subtraction, operation.left, operation.right);
		else
			Error.Raise("Invalid expression");
	}

	private void						ConvertOperation(OperatorType operatorType)
	{
		elementsRoot = ConvertOperationRecursively(elementsRoot, operatorType);
	}
	
	private Element						ConvertOperationRecursively(Element element, OperatorType operatorType)
	{
		Operation						operation = element as Operation;

		if (operation != null)
		{
			operation.left = ConvertOperationRecursively(operation.left, operatorType);
			operation.right = ConvertOperationRecursively(operation.right, operatorType);
		}

		if (operation != null && operation.OperatorType == operatorType)
		{
			OperatorType				newType;
			Operation					newRightElement;
			
			switch (operatorType)
			{
				case OperatorType.Subtraction :
					newType = OperatorType.Addition;
					newRightElement = new Operation(OperatorType.Multiplication, operation.right, new Term(-1, 0));
					break;
				
				case OperatorType.Division :
					newType = OperatorType.Multiplication;
					newRightElement = new Operation(OperatorType.Power, operation.right, new Term(-1, 0));
					break;
				
				default :
					Error.Raise();
					return element;
			}

			return new Operation(newType, operation.left, newRightElement);
		}

		return element;
	}
	
	private void						Reduce()
	{
		elementsRoot = Reduce(elementsRoot);
	}

	private static Element				Reduce(Element element)
	{
		if (element is Operation operation)
		{
			operation.left = Reduce(operation.left);
			operation.right = Reduce(operation.right);
			
			if (!operation.OperatorType.CanCalculate())
				return element;

			Term						left = operation.left as Term;
			Term						right = operation.right as Term;

			if (left == null || right == null)
				return element;

			bool						shouldCheckPowers = operation.OperatorType.IsAnyOf(OperatorType.Addition, OperatorType.Subtraction);
			bool						arePowersSame = left.Power == right.Power;
			
			if (shouldCheckPowers && !arePowersSame)
				return element;

			return operation.OperatorType.Calculate(left, right);			
		}

		return element;
	}

	private void						SortTerms()
	{
		sortedTerms = new Dictionary<int, List<Term>>();
		for (int i = 0; i <= MAXIMUM_POWER; i++)
			sortedTerms[i] = new List<Term>();
		
		SortTermsRecursively(elementsRoot);
	}
	
	private void						SortTermsRecursively(Element element)
	{
		switch (element)
		{
			case Operation operation :
				SortTermsRecursively(operation.left);
				SortTermsRecursively(operation.right);
				break;
			
			case Term term :
				Error.Assert(sortedTerms.ContainsKey(term.Power), "Unexpected term power");
				if (!term.IsZero)
					sortedTerms[term.Power].Add(term);
				break;
		}
	}

	#endregion
}