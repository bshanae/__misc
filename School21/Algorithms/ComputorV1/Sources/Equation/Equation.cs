using System;

public class				Equation
{
	// private const int		MAX_POWER = 2;
	//
	// public Group[]			GroupByPower
	// {
	// 	get;
	// 	private set;
	// }
	//
	// public					Equation(GroupTree tree)
	// {
	// 	GroupByPower = new Group[MAX_POWER + 1];
	// 	for (int i = 0; i <= MAX_POWER; i++)
	// 		GroupByPower[i] = new Group(0, i);
	// 	
	// 	foreach (var group in tree.LeftList)
	// 		GroupByPower[(int)group.Power] += group;
	// 	foreach (var group in tree.RightList)
	// 		GroupByPower[(int)group.Power] -= group;
	// }
	//
	// public override String	ToString()
	// {
	// 	string				result = "Equation : \n";
	//
	// 	for (int i = MAX_POWER; i >= 0; i--)
	// 		result += GroupByPower[i] + "\n";
	// 	return result;
	// }
}