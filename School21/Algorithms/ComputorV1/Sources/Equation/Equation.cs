using System.Collections.Generic;

public static partial class						Equation
{
	private const int							MAXIMUM_POWER = 2;

	private static Element						elementsRoot;
	private static Dictionary<int, List<Term>>	sortedTerms;
	private static Math.Fraction?[]				equationRoots;

	public static Math.Fraction?				FirstRoot => equationRoots[0];
	public static Math.Fraction?				SecondRoot => equationRoots[1];

	#region										Public methods
	
	public static void							Build()
	{
		elementsRoot = Element.Convert(Expression.Root);
		equationRoots = new Math.Fraction?[]{null, null};

		Printer.PrintLineIfVerbose("Equation :");
		Printer.PrintLineIfVerbose(elementsRoot);
		Printer.PrintLineIfVerbose();

		MoveAllTermToLeftSide();
		Printer.PrintLineIfVerbose("Moved all terms to left side :");
		Printer.PrintLineIfVerbose(elementsRoot);
		Printer.PrintLineIfVerbose();

		ConvertOperation(OperatorType.Subtraction);
		Printer.PrintLineIfVerbose("Converted subtraction to addition :");
		Printer.PrintLineIfVerbose(elementsRoot);
		Printer.PrintLineIfVerbose();
		
		ConvertOperation(OperatorType.Division);
		Printer.PrintLineIfVerbose("Converted division to multiplication :");
		Printer.PrintLineIfVerbose(elementsRoot);
		Printer.PrintLineIfVerbose();

		ApplyMultiplication();
		Printer.PrintLineIfVerbose("Applied multiplication :");
		Printer.PrintLineIfVerbose(elementsRoot);
		Printer.PrintLineIfVerbose();

		Reduce();
		Printer.PrintLineIfVerbose("Reduced equation :");
		Printer.PrintLineIfVerbose(elementsRoot);
		Printer.PrintLineIfVerbose();
		
		DiscardZeros();
		Printer.PrintLineIfVerbose("Discarded nulls :");
		Printer.PrintLineIfVerbose(elementsRoot);
		Printer.PrintLineIfVerbose();
		
		SortTerms();
		Printer.PrintLineIfVerbose("Sorted terms :");
		PrintSortedTerms();
		Printer.PrintLineIfVerbose();
		
		SumSortedTerms();
		Printer.PrintLineIfVerbose("Summed sorted terms :");
		PrintSortedTerms();
		Printer.PrintLineIfVerbose();
		
		Solve();
		PrintRoots();
	}

	#endregion
	
	#region										Private methods

	private static void							MoveAllTermToLeftSide()
	{
		if (elementsRoot is Operation operation && operation.OperatorType == OperatorType.Equality)
			elementsRoot = new Operation(OperatorType.Subtraction, operation.left, operation.right);
		else
			Error.Raise("Invalid expression");
	}

	private static void							ConvertOperation(OperatorType operatorType)
	{
		elementsRoot = ConvertOperation(elementsRoot, operatorType);
	}
	
	private static Element						ConvertOperation(Element element, OperatorType operatorType)
	{
		Operation								operation = element as Operation;

		if (operation != null)
		{
			operation.left = ConvertOperation(operation.left, operatorType);
			operation.right = ConvertOperation(operation.right, operatorType);
		}

		if (operation != null && operation.OperatorType == operatorType)
		{
			OperatorType						newType;
			Operation							newRightElement;
			
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
	
	private static void							ApplyMultiplication()
	{
		elementsRoot = ApplyMultiplication(elementsRoot);
	}
	
	private static Element						ApplyMultiplication(Element element)
	{
		if (element is Operation parentOperation)
		{
			parentOperation.left = ApplyMultiplication(parentOperation.left);
			parentOperation.right = ApplyMultiplication(parentOperation.right);

			if (parentOperation.OperatorType != OperatorType.Multiplication)
				return element;
			
			Operation							childOperation;
			Term								childTerm;

			childOperation = parentOperation.left as Operation ?? parentOperation.right as Operation;
			childTerm = parentOperation.left as Term ?? parentOperation.right as Term;

			if
			(
				childOperation != null
				&& !childOperation.OperatorType.IsAnyOf(OperatorType.Multiplication, OperatorType.Power)
				&& childTerm != null
				&& childTerm.Power == 0
			)
			{
				Operation						transformedOperation;
				
				transformedOperation = new Operation(childOperation.OperatorType);
				transformedOperation.left = ApplyMultiplication(childOperation.left, childTerm);
				transformedOperation.right = ApplyMultiplication(childOperation.right, childTerm);

				return ApplyMultiplication(transformedOperation);
			}
		}

		return element;
	}

	private static Element						ApplyMultiplication(Element element, Term term)
	{
		return new Operation(OperatorType.Multiplication, element, term);			
	}
	
	private static void							Reduce()
	{
		elementsRoot = Reduce(elementsRoot);
	}

	private static Element						Reduce(Element element)
	{
		if (element is Operation operation)
		{
			operation.left = Reduce(operation.left);
			operation.right = Reduce(operation.right);
			
			if (!operation.OperatorType.CanCalculate())
				return element;

			Term								left = operation.left as Term;
			Term								right = operation.right as Term;

			if (left == null || right == null)
				return element;

			bool								shouldCheckPowers = operation.OperatorType.IsAnyOf(OperatorType.Addition, OperatorType.Subtraction);
			bool								arePowersSame = left.Power == right.Power;
			
			if (shouldCheckPowers && !arePowersSame)
				return element;

			return operation.OperatorType.Calculate(left, right);			
		}

		return element;
	}

	private static void							DiscardZeros()
	{
		elementsRoot = DiscardZeros(elementsRoot);
	}

	private static Element						DiscardZeros(Element element)
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

	private static void							SortTerms()
	{
		sortedTerms = new Dictionary<int, List<Term>>();
		for (int i = 0; i <= MAXIMUM_POWER; i++)
			sortedTerms[i] = new List<Term>();
		
		SortTermsRecursively(elementsRoot);
	}
	
	private static void							SortTermsRecursively(Element element)
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

	private static void							SumSortedTerms()
	{
		foreach (var keyValue in sortedTerms)
		{
			var									power = keyValue.Key;
			var									terms = keyValue.Value;
			
			float								factorSum = 0;

			foreach (var term in terms)
				factorSum += term.Factor;

			sortedTerms[power].RemoveAll(term => true);
			if (factorSum != 0f)
				sortedTerms[power].Add(new Term(factorSum, power));
		}
	}

	private static void							PrintSortedTerms()
	{
		foreach (var keyValue in sortedTerms)
		{
			int									power = keyValue.Key;
			List<Term>							terms = keyValue.Value;

			if (terms.Count > 0)
			{
				Printer.PrintIfVerbose($"Power {power} : ");

				for (int i = 0; i < terms.Count; i++)
				{
					Printer.PrintIfVerbose(terms[i]);
					if (i < terms.Count - 1)
						Printer.PrintIfVerbose(", ");
				}

				Printer.PrintLineIfVerbose();
			}
		}
	}

	private static void							Solve()
	{
		float									a = GetFactorByPower(2);
		float									b = GetFactorByPower(1);
		float									c = GetFactorByPower(0);
		
		if (a != 0f && b != 0f)
			SolveCompleteQuadraticEquation(a, b ,c);
		else
			SolveIncompleteQuadraticEquation(a, b ,c);
	}

	private static void							SolveCompleteQuadraticEquation(float a, float b, float c)
	{
		float									discriminant = b * b - 4 * a * c;

		if (discriminant > 0)
		{
			equationRoots[0] = new Math.Fraction(-b + Math.SquareRoot(discriminant), 2 * a);
			equationRoots[1] = new Math.Fraction(-b - Math.SquareRoot(discriminant), 2 * a);
		}
		else if (discriminant == 0)
			equationRoots[0] = new Math.Fraction(-b, 2 * a);
	}
	
	private static void							SolveIncompleteQuadraticEquation(float a, float b, float c)
	{
		if (a == 0)
			equationRoots[0] = new Math.Fraction(c, -b);
		else if (b == 0)
		{
			equationRoots[0] = new Math.Fraction(-Math.SquareRoot(c / -a));
			equationRoots[1] = new Math.Fraction(+Math.SquareRoot(c / -a));
		}
	}

	private static float						GetFactorByPower(int power)
	{
		var										list = sortedTerms.GetValueOrNull(power);

		if (list != null && list.Count > 0)
			return list[0].Factor;
		else
			return 0f;
	}

	private static void							PrintRoots()
	{
		if (equationRoots[0] != null && equationRoots[1] != null)
			Printer.PrintLine($"Equation roots : {equationRoots[0]}, {equationRoots[1]}");
		else if (equationRoots[0] != null && equationRoots[1] == null)
			Printer.PrintLine($"Equation root : {equationRoots[0]}");
		else if (equationRoots[0] == null && equationRoots[1] == null)
			Printer.PrintLine("Equation has no roots");
	}

	#endregion
}