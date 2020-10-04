using System;
using System.Collections.Generic;

public static partial class			Program
{
	public static class				Options
	{
		public enum					ReportFormat
		{
			Standard,
			Internal,
			Test
		}

		public static ReportFormat	Report = ReportFormat.Standard;
	
		public static void			Parse(List<string> flags)
		{

			for (int i = 0; i < flags.Count; i++)
			{
				if (DoesFlagStartWith(flags[i], "report"))
				{
					Report = GetValueFromFlag(flags[i], "report").ToLower() switch
					{
						"standard" => ReportFormat.Standard,
						"internal" => ReportFormat.Internal,
						"test" => ReportFormat.Test,
						_ => throw new Exception("[Program.Options, Parse] Unknown format type")
					};
				}
				else
					continue ;
				
				flags.RemoveAt(i--);
			}
		}
		
		private static bool			DoesFlagStartWith(string flag, string key)
		{
			return flag.ToLower().StartsWith(key);
		}

		private static string		GetValueFromFlag(string flag, string key)
		{
			return flag.ToLower().Remove(0, key.Length + "=".Length);
		}
	}
}