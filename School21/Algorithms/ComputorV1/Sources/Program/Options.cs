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
				bool				deleteFlag = true;
				
				switch (flags[i])
				{
					case "standard" :
					case "Standard" :
						Report = ReportFormat.Standard;
						break ;
					
					case "internal" :
					case "Internal" :
						Report = ReportFormat.Internal;
						break ;
					
					case "test" :
					case "Test" :
						Report = ReportFormat.Test;
						break ;
					
					default :
						deleteFlag = false;
						break ;
				}
				
				if (deleteFlag)
					flags.RemoveAt(i--);
			}
		}
	}
}