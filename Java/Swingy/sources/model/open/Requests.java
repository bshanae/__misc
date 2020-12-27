package model.open;

import application.utils.Point;
import model.closed.managers.battle.BattleLogger;

import java.util.List;

public abstract class						Requests
{
	public interface						Abstract {}

	public interface						System extends  Abstract {}

	public interface						Ui extends  Abstract {}

// --------------------------------------->	Empty

	public static class						SwitchToConsole implements System
	{}

	public static class						SwitchToGui implements System
	{}

	public static class						HeroSelector implements Ui
	{
		public final List<Pockets.Hero>		heroes;

		public 								HeroSelector(List<Pockets.Hero> heroes)
		{
			this.heroes = heroes;
		}
	}

	public static class						HeroNameEntry implements Ui {}

	public static class						ClassSelector implements Ui {}


// --------------------------------------->	With string

	private static abstract class			WithMessage implements Ui
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

	public static class						Map implements Ui
	{
		public final Pockets.Map			map;
		public final Point					pivot;

		public								Map(model.closed.managers.Map map, Point pivot)
		{
			this.map = new Pockets.Map(map);
			this.pivot = pivot;
		}
	}

	public static class						Battle implements Ui
	{
		public final Pockets.BattleLog		log;
		public final boolean				isBattleFinished;

		public								Battle(model.closed.managers.battle.Battle battle)
		{
			log = new Pockets.BattleLog(battle.getLogger());
			isBattleFinished = battle.isFinished();
		}
	}
}
