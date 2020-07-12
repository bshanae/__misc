public class				Group
{
	public Variable			Variable
	{
		get;
		private set;
	}

	public int				Factor
	{
		get;
		private set;
	}
	
	public int				Power
	{
		get ;
		private set;
	}

							Group
							(
								Variable variable,
								int factor = 1,
								int power = 1
							)
	{
		Variable = variable;
		Factor = factor;
		Power = power;
	}
}