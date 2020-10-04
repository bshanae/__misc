using System;
using System.Collections.Generic;

public static partial class			Program
{
	public static class				Options
	{
		public enum					ReportFormat
		{
			Standard,
			Internal
		}

		public static ReportFormat	Report;
		public static bool			Test = false;
	
		public static void			Parse(List<string> flags)
		{

			for (int i = 0; i < flags.Count; i++)
			{
				if (DoesFlagStartWith(flags[i], "verbose"))
				{
					string		value = GetValueFromFlag(flags[i], "verbose");

					value = value.ToLower();
					if (value == "standard")
						Report = ReportFormat.Standard;
					else if (value == "internal")
						Report = ReportFormat.Internal;
					else
						throw new Exception("[Program.Options, Parse] Unknown format type");
				}
				else if (DoesFlagStartWith(flags[i], "test"))
					Test = true;
				else
					continue ;
				
				flags.RemoveAt(i--);
			}
		}
		
		private static bool			DoesFlagStartWith(string flag, string key)
		{
			return flag.ToLower().StartsWith(key.ToLower());
		}

		private static string		GetValueFromFlag(string flag, string key)
		{
			var						flagCopy = flag.ToLower().Clone() as string;

			flagCopy.Remove(0, key.Length + "=".Length);
			return flagCopy;
		}
	}
}