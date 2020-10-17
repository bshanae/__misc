using System;

namespace							Computor
{
	public static class				Analyzer
	{
		#region						Nested types
		
		private class				Expectation
		{
			public enum				Options
			{
				Operand = 0x00001,
				ConstantForPower = 0x00010,
				InternalOperator = 0x01000,
				ExternalOperator = 0x00100,
				End = 0x10000
			}

			private readonly int	_options;

			public					Expectation(params Options[] options)
			{
				foreach (var option in options)
					_options |= (int)option;
			}
			
			public static bool		IsTokenExpected(Options option, Token token)
			{
				switch (option)
				{
					case Options.Operand :
						return token is Operand;
					
					case Options.ConstantForPower :
						return token is Constant;
					
					case Options.InternalOperator :
						if (token is Operator internalOperator)
							return internalOperator.IsAnyOf
								(
									Operator.Types.Multiplication,
									Operator.Types.Division,
									Operator.Types.Power
								);
						else
							return false;
						
					case Options.ExternalOperator :
						if (token is Operator externalOperator)
							return externalOperator.IsAnyOf
								(
									Operator.Types.Addition,
									Operator.Types.Subtraction,
									Operator.Types.Equality
								);
						else
							return false;

					case Options.End :
						return token == null;
				}
				
				throw new Exception("[Equation.Solver.Expectation] Unexpected path");
			}

			public bool				IsTokenExpected(Token token)
			{
				bool				result = false;
				
				void				CheckSpecificOption(Options option)
				{
					if (IsOptionSet(option))
						result = result || IsTokenExpected(option, token);	
				}
				
				CheckSpecificOption(Options.Operand);
				CheckSpecificOption(Options.ConstantForPower);
				CheckSpecificOption(Options.InternalOperator);
				CheckSpecificOption(Options.ExternalOperator);
				CheckSpecificOption(Options.End);

				return result;
			}

			public bool				IsOptionSet(Options option)
			{
				return (_options & (int)option) == (int)option;
			}
		}
		
		#endregion
		
		#region						Fields

		private static Token		_currentToken;
		private static Expectation	_currentExpectation;
		private static Term			_currentTerm;
		private static Operator		_lastInternalOperator;
		private static Operator		_lastExternalOperator;
		private static bool			_isRightSideOfEquation;
		
		#endregion
		
		#region						Main methods
		
		public static void			BuildTerms()
		{
			_currentToken = null;
			_currentTerm = null;
			_lastInternalOperator = null;
			_lastExternalOperator = null;
			_isRightSideOfEquation = false;
			
			_currentExpectation = new Expectation(Expectation.Options.Operand);

			foreach (var token in Workspace.Tokens)
				ProcessToken(token);
			
			ProcessToken(null);
		}

		public static void			ReduceTerms()
		{
			_currentToken = null;
			_currentTerm = null;
			_lastInternalOperator = null;
			_lastExternalOperator = null;
			_isRightSideOfEquation = false;
			
			_currentExpectation = new Expectation(Expectation.Options.Operand);

			foreach (var token in Workspace.Tokens)
				ProcessToken(token);
			
			ProcessToken(null);
		}

		public static void			SortTerms()
		{
			foreach (var term in Workspace.Terms)
				SortTerm(term);
		}
		
		#endregion
		
		#region						Term processing

		private static void			ProcessToken(Token currentToken)
		{
			bool					TryProcessOption(Expectation.Options option)
			{
				if (!_currentExpectation.IsOptionSet(option))
					return false;
				if (!Expectation.IsTokenExpected(option, _currentToken))
					return false;
				
				ProcessOption(option);
				return true;
			}
			
			_currentToken = currentToken;
			
			if (TryProcessOption(Expectation.Options.Operand))
				;
			else if (TryProcessOption(Expectation.Options.ConstantForPower))
				;
			else if (TryProcessOption(Expectation.Options.InternalOperator))
				;
			else if (TryProcessOption(Expectation.Options.ExternalOperator))
				;
			else if (TryProcessOption(Expectation.Options.End))
				;
			else
				throw new Exception("[Equation.Solver] Can't process token");
		}

		#endregion
		
		#region						Option processing
		
		private static void			ProcessOption(Expectation.Options option)
		{
			switch (option)
			{
				case Expectation.Options.Operand :
					ProcessOperand();
					break;

				case Expectation.Options.ConstantForPower :
					ProcessConstantForPower();
					break;

				case Expectation.Options.InternalOperator :
					ProcessInternalOperator();
					break;
				
				case Expectation.Options.ExternalOperator :
					ProcessExternalOperator();
					break;

				case Expectation.Options.End :
					ProcessEnd();
					break;
			}
		}
		
		private static void			ProcessOperand()
		{
			float					localFactor = 1f;

			if (_lastExternalOperator?.Type == Operator.Types.Subtraction)
				localFactor *= -1f;
			if (_isRightSideOfEquation)
				localFactor *= -1f;
			
			if (_currentToken is Constant constant)
			{
				_currentTerm ??= new Term(constant.Factor * localFactor, 0f);

				if (_lastInternalOperator == null || _lastInternalOperator.Type == Operator.Types.Multiplication)
					_currentTerm.Factor *= constant.Value;
				else if (_lastInternalOperator.Type == Operator.Types.Division)
					_currentTerm.Factor /= constant.Value;
				
				_lastInternalOperator = null;
			}
			else if (_currentToken is Variable variable)
			{
				_currentTerm ??= new Term(variable.Factor * localFactor, 0f);
				
				if (_lastInternalOperator == null || _lastInternalOperator.Type == Operator.Types.Multiplication)
					_currentTerm.Power++;
				else if (_lastInternalOperator.Type == Operator.Types.Division)
					_currentTerm.Power--;

				_lastInternalOperator = null;
			}
			else
				throw new Exception("[Solver] Term building error");
			
			_currentExpectation = new Expectation
				(
					Expectation.Options.InternalOperator,
					Expectation.Options.ExternalOperator,
					Expectation.Options.End
				);
		}
		
		private static void			ProcessConstantForPower()
		{
			if (_currentToken is Constant constant)
			{
				if (_lastInternalOperator.Type != Operator.Types.Power)
					throw new Exception("[Solver] Term building error");

				_currentTerm.Power += constant.Value - 1;
				_lastInternalOperator = null;
			}
			else
				throw new Exception("[Solver] Term building error");
			
			_currentExpectation = new Expectation
				(
				Expectation.Options.InternalOperator,
					Expectation.Options.ExternalOperator,
					Expectation.Options.End
				);
		}
		
		private static void			ProcessInternalOperator()
		{
			if (_currentToken is Operator @operator)
			{
				_lastInternalOperator = @operator;
				
				if (@operator.Type == Operator.Types.Power)
					_currentExpectation = new Expectation(Expectation.Options.ConstantForPower);
				else
					_currentExpectation = new Expectation(Expectation.Options.Operand);
			}
			else
				throw new Exception("[Solver] Term building error");
		}
		
		private static void			ProcessExternalOperator()
		{
			if (_currentToken is Operator @operator)
			{
				Workspace.Terms.Add(_currentTerm);
				_currentTerm = null;
				
				_lastExternalOperator = @operator;
				
				if (@operator.Type == Operator.Types.Equality)
					_isRightSideOfEquation = true;
			}
			else
				throw new Exception("[Solver] Term building error");
			
			_currentExpectation = new Expectation(Expectation.Options.Operand);
		}

		private static void			ProcessEnd()
		{
			if (_currentTerm != null)
			{
				Workspace.Terms.Add(_currentTerm);
				_currentTerm = null;
			}

			_currentExpectation = null;
		}

		#endregion
		
		#region						Term sorting

		private static void			SortTerm(Term term)
		{
			var						termPower = (int)term.Power;

			if (!Workspace.SortedTerms.ContainsKey(termPower))
				Workspace.SortedTerms[termPower] = term;
			else
				Workspace.SortedTerms[termPower] = Term.Sum(Workspace.SortedTerms[termPower], term);
		}
		
		#endregion
	}
}