package controller.open;

public abstract class				Commands
{
	public interface				Abstract {}

// ------------------------------->	Without value

	public static class				Empty implements Abstract {}

	public static class				Exit implements Abstract {}

	public static class				CreateHero implements Abstract {}

	public static class				GoNorth implements Abstract {}
	public static class				GoEast implements Abstract {}
	public static class				GoSouth implements Abstract {}
	public static class				GoWest implements Abstract {}

// ------------------------------->	With value

	private static abstract class	CommandWithValue implements Abstract
	{
		public final String			value;

		public						CommandWithValue(String value)
		{
			this.value = value;
		}
	}

	public static class				Enter extends CommandWithValue
	{
		public						Enter(String value)
		{
			super(value);
		}
	}

	public static class				SelectHero extends CommandWithValue
	{
		public						SelectHero(String value)
		{
			super(value);
		}
	}

	public static class				DeleteHero extends CommandWithValue
	{
		public						DeleteHero(String value)
		{
			super(value);
		}
	}

	public static class				InfoAboutHero extends CommandWithValue
	{
		public						InfoAboutHero(String value)
		{
			super(value);
		}
	}
}
