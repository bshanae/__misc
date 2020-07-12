public class				Group
{
	public Variable			Variable
	{
		get;
		private set;
	}

	public float			Factor
	{
		get;
		private set;
	}
	
	public float			Power
	{
		get ;
		private set;
	}

	public					Group
							(
								Variable variable = null,
								float factor = 1f,
								float power = 1f
							)
	{
		Variable = variable;
		Factor = factor;
		Power = power;
	}

	public override string	ToString()
	{
		string				variableName = " ";

		if (Variable != null)
			variableName = "" + Variable.String[0];
		return $"Group : {{variable = {variableName}, factor = {Factor}, power = {Power}}}";
	}
}