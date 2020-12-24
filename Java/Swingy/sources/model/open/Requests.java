package model.open;

import application.utils.Point;

import java.util.List;

public abstract class						Requests
{
	public interface						Abstract {}

	public interface						System {}

	public interface						Ui {}

// --------------------------------------->	Empty

	public static class						SwitchToConsole implements Abstract, System
	{}

	public static class						SwitchToGui implements Abstract, System
	{}

	public static class						HeroSelector implements Abstract, Ui
	{
		public final List<Pockets.Hero>		heroes;

		public 								HeroSelector(List<Pockets.Hero> heroes)
		{
			this.heroes = heroes;
		}
	}

	public static class						HeroNameEntry implements Abstract, Ui {}

	public static class						ClassSelector implements Abstract, Ui {}


// --------------------------------------->	With string

	private static abstract class			WithMessage implements Abstract, Ui
	{
		public final String					message;

		public								WithMessage(String message)
		{
			this.message = message;
		}
	}

	public static class						Error extends WithMessage
	{
		public 								Error(String message)
		{
			super(message);
		}
	}

// --------------------------------------->	With complex structure

	public static class						Map implements Abstract, Ui
	{
		public final Pockets.Map			map;
		public final Point					pivot;

		public								Map(model.closed.managers.Map map, Point pivot)
		{
			this.map = new Pockets.Map(map);
			this.pivot = pivot;
		}
	}
}
