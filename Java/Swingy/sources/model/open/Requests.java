package model.open;

import application.common.Point;

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
		private final List<Pockets.Hero>	heroes;

		public List<Pockets.Hero>			getHeroes()
		{
			return heroes;
		}

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
		private final String				message;

		public String						getMessage()
		{
			return  message;
		}

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
		private final Pockets.Map			map;
		private final Point					pivot;

		public Pockets.Map					getMap()
		{
			return map;
		}

		public Point						getPivot()
		{
			return pivot;
		}

		public								Map(model.closed.gameObjects.Map map, Point pivot)
		{
			this.map = new Pockets.Map(map);
			this.pivot = pivot;
		}
	}
}
