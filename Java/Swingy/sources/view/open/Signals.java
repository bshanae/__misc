package view.open;

import model.open.Pockets;

public abstract class					Signals
{
	public interface					Abstract {}

// -----------------------------------> Console

	public static class					Console implements Abstract
	{
		public final String				input;
		public final Context			context;

		public							Console(String input, Context context)
		{
			this.input = input;
			this.context = context;
		}
	}

// -----------------------------------> GUI

	public static abstract class		Gui
	{
		public interface				Abstract extends Signals.Abstract { }

		public static class				CreateHero implements Abstract
		{ }

		public static class				SelectHero implements Abstract
		{
			public final Pockets.Hero	hero;

			public						SelectHero(Pockets.Hero hero)
			{
				this.hero = hero;
			}
		}


		public static class				DeleteHero implements Abstract
		{
			public final Pockets.Hero	hero;

			public						DeleteHero(Pockets.Hero hero)
			{
				this.hero = hero;
			}
		}
	}
}
