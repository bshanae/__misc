public static partial class			Program
{
	public static class				Options
	{
		public enum					Modes
		{
			Standard,
			Internal,
			Test
		}

		public static Modes	Report = Modes.Standard;
	
		public static void			Parse()
		{
			for (int i = 0; i < arguments.Count; i++)
			{
				bool				deleteFlag = true;
				
				switch (arguments[i])
				{
					case "standard" :
					case "Standard" :
						Report = Modes.Standard;
						break ;
					
					case "internal" :
					case "Internal" :
						Report = Modes.Internal;
						break ;
					
					case "test" :
					case "Test" :
						Report = Modes.Test;
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