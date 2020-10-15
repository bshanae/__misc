public static partial class			Program
{
	public static class				Options
	{
		public enum					ReportFormats
		{
			Standard,
			Internal,
			Test
		}

		public static ReportFormats	Report = ReportFormats.Standard;
	
		public static void			Parse()
		{
			for (int i = 0; i < arguments.Count; i++)
			{
				bool				deleteFlag = true;
				
				switch (arguments[i])
				{
					case "standard" :
					case "Standard" :
						Report = ReportFormats.Standard;
						break ;
					
					case "internal" :
					case "Internal" :
						Report = ReportFormats.Internal;
						break ;
					
					case "test" :
					case "Test" :
						Report = ReportFormats.Test;
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