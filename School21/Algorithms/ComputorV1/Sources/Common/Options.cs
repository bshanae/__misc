using System.Collections.Generic;

public static class		Options
{
	public static bool	Verbose = false;
	public static bool	Test = false;
	
	public static void	Parse(List<string> flags)
	{
		for (int i = 0; i < flags.Count; i++)
			switch (flags[i])
			{
				case "Verbose" :
				case "verbose" :
					Verbose = true;
					flags.RemoveAt(i--);
					break;
				
				case "Terbose" :
				case "terbose" :
					Test = true;
					flags.RemoveAt(i--);
					break;
			}
	}
}
