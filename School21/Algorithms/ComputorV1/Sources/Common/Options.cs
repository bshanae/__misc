public static class		Options
{
	public static bool	Verbose = false;
	
	public static void	Parse(string[] flags)
	{
		foreach (string flag in flags)
			switch (flag)
			{
				case "Verbose" :
				case "verbose" :
					Verbose = true;
					break;
			}
	}
}
