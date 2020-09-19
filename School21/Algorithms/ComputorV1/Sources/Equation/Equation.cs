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

		ConvertOperation(OperatorType.Subtraction);
		Console.WriteLine("Converted subtraction to addition :");
		Console.WriteLine(elementsRoot);
		
		ConvertOperation(OperatorType.Division);
		Console.WriteLine("Converted division to multiplication :");
		Console.WriteLine(elementsRoot);

		ApplyMultiplication();
		Console.WriteLine("Applied multiplication :");
		Console.WriteLine(elementsRoot);

		Reduce();
		Console.WriteLine("Reduced equation :");
		Console.WriteLine(elementsRoot);
		
		DiscardZeros();
		Console.WriteLine("Discarded nulls :");
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
		elementsRoot = ConvertOperation(elementsRoot, operatorType);
	}
	
	private Element						ConvertOperation(Element element, OperatorType operatorType)
	{
		Operation						operation = element as Operation;

		if (operation != null)
		{
			operation.left = ConvertOperation(operation.left, operatorType);
			operation.right = ConvertOperation(operation.right, operatorType);
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
	
	private void						ApplyMultiplication()
	{
		elementsRoot = ApplyMultiplication(elementsRoot);
	}
	
	private static Element				ApplyMultiplication(Element element)
	{
		if (element is Operation parentOperation)
		{
			parentOperation.left = ApplyMultiplication(parentOperation.left);
			parentOperation.right = ApplyMultiplication(parentOperation.right);

			if (parentOperation.OperatorType != OperatorType.Multiplication)
				return element;
			
			Operation					childOperation;
			Term						childTerm;

			childOperation = parentOperation.left as Operation ?? parentOperation.right as Operation;
			childTerm = parentOperation.left as Term ?? parentOperation.right as Term;

			if
			(
				childOperation != null
				&& childOperation.OperatorType != OperatorType.Multiplication
				&& childTerm != null
				&& childTerm.Power == 0
			)
			{
				Operation				transformedOperation;
				
				transformedOperation = new Operation(childOperation.OperatorType);
				transformedOperation.left = ApplyMultiplication(childOperation.left, childTerm);
				transformedOperation.right = ApplyMultiplication(childOperation.right, childTerm);

				return transformedOperation;
			}
		}

		return element;
	}

	private static Element				ApplyMultiplication(Element element, Term term)
	{
		return new Operation(OperatorType.Multiplication, element, term);			
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

	private void						DiscardZeros()
	{
		elementsRoot = DiscardZeros(elementsRoot);
	}

	private static Element				DiscardZeros(Element element)
	{
		if (element is Operation operation && operation.OperatorType == OperatorType.Addition)
		{
			DiscardZeros(operation.left);
			DiscardZeros(operation.right);

			if (operation.left is Term leftTerm && leftTerm.IsZero)
				return operation.right;
			
			if (operation.right is Term rightTerm && rightTerm.IsZero)
				return operation.left;
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

	private void						Solve()
	{
		
	}

	#endregion
}