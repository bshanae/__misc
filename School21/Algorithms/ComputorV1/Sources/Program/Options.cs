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
	
		public static void			Parse()
		{
			for (int i = 0; i < arguments.Count; i++)
			{
				bool				deleteFlag = true;
				
				switch (arguments[i])
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
					arguments.RemoveAt(i--);
			}
		}
	}
}