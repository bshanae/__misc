using System.Collections.Generic;

public partial class			Expression
{
	public class				BinaryMember : IMember
	{
		public List<IMember>	Children;

		public OperatorType		OperatorType
		{
			get ;
			private set ;
		}

		public					BinaryMember(OperatorType operatorType)
		{
			OperatorType = operatorType;
			Children = new List<IMember>();
		}

		public override string	ToString()
		{
			string result = "";

			result += "[";
			
			for (var i = 0; i < Children.Count; i++) 
			{
				result += Children[i];
				if (i < Children.Count - 1)
					result += " " + OperatorType.AsString() + " ";
			}
			
			result += "]";

			return result;
		}
	}
}