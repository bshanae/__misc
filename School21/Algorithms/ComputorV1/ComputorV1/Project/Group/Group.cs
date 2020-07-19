using System;

public class				Group
{
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

	public					Group(float factor = 0f, float power = 0f)
	{
		Factor = factor;
		Power = power;
	}

	public override string	ToString()
	{
		string				variableName = " ";

		return $"Group : {{factor = {Factor}, power = {Power}}}";
	}
	
	public static Group		operator + (Group left, Group right)
	{
		Group				result = new Group();
		
		if (!Compatible(left, right))
			throw new Exception("Can't add groups");
		
		result.Power = left.Power;
		result.Factor = left.Factor + right.Factor;
		return result;
	}
	
	public static Group		operator - (Group left, Group right)
	{
		Group				result = new Group();

		if (!Compatible(left, right))
			throw new Exception("Can't subtract groups");
		
		result.Power = left.Power;
		result.Factor = left.Factor - right.Factor;
		return result;
	}

	private static bool		Compatible(Group left, Group right)
	{
		return left.Power == right.Power;
	}
}