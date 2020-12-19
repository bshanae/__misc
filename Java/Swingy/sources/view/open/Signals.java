package view.open;

import model.open.Pockets;

public abstract class					Signals
{
	public static abstract class		Abstract
	{
		private Context					context;

		public Context					getContext()
		{
			return context;
		}

		public void						setContext(Context context)
		{
			if (this.context != null)
				throw new RuntimeException("Can't set context more than once");

			this.context = context;
		}
	}

// -----------------------------------> Console

	public static class					Console extends Abstract
	{
		public final String				input;

		public							Console(String input)
		{
			this.input = input;
		}
	}

// -----------------------------------> GUI

	public static abstract class		Gui
	{
		public static abstract class	Abstract extends Signals.Abstract {}

		public static class				CreateHero extends Abstract {}

		public static class				SelectHero extends Abstract
		{
			public final Pockets.Hero	hero;

			public						SelectHero(Pockets.Hero hero)
			{
				this.hero = hero;
			}
		}

		public static class				DeleteHero extends Abstract
		{
			public final Pockets.Hero	hero;

			public						DeleteHero(Pockets.Hero hero)
			{
				this.hero = hero;
			}
		}

		public static class				Enter extends Signals.Abstract
		{
			public						Enter(String value)
			{ }
		}
	}
}
