package model.closed.objects.artefacts;

import application.utils.Range;
import model.closed.objects.Attack;

import java.util.LinkedList;
import java.util.List;

public abstract class					Weapons
{
// -----------------------------------> Interface

	public static abstract class		Abstract extends Artefact
	{
		protected						Abstract(String name)
		{
			super(name);
		}

		public abstract List<Attack>	getAttacks();
	}

// -----------------------------------> Warrior

	public static class					Hammer extends Abstract
	{
		public							Hammer()
		{
			super("Hammer");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Regular blow", 95, new Range<>(20), 0.01f));
			attacks.add(new Attack("Strong blow", 5, new Range<>(80), 0.01f));

			return attacks;
		}
	}

	public static class					GreatHammer extends Abstract
	{
		public							GreatHammer()
		{
			super("Great hammer");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Regular blow", 95, new Range<>(90), 0.01f));
			attacks.add(new Attack("Strong blow", 5, new Range<>(250), 0.01f));

			return attacks;
		}
	}

// -----------------------------------> Warrior + Swordsman + Assassin

	public static class					OldSword extends Abstract
	{
		public							OldSword()
		{
			super("Old sword");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 100, new Range<>(30, 40), 0.1f));

			return attacks;
		}
	}

	public static class					SteelSword extends Abstract
	{
		public							SteelSword()
		{
			super("Steel sword");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Light blow", 50, new Range<>(60, 90), 0.1f));
			attacks.add(new Attack("Strong blow", 40, new Range<>(80, 110), 0.1f));

			return attacks;
		}
	}

	public static class					SoldierSword extends Abstract
	{
		public							SoldierSword()
		{
			super("Soldier sword");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 100, new Range<>(130, 140), 0.1f));

			return attacks;
		}
	}

	public static class					KnightSword extends Abstract
	{
		public							KnightSword()
		{
			super("Knight sword");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 60, new Range<>(180, 240), 0.1f));
			attacks.add(new Attack("Thrust", 40, new Range<>(400, 500), 0.3f));

			return attacks;
		}
	}


// -----------------------------------> Swordsman

	public static class					Rapier extends Abstract
	{
		public							Rapier()
		{
			super("Rapier");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Thrust", 60, new Range<>(30, 60), 0.1f));
			attacks.add(new Attack("Blow", 40, new Range<>(70), 0.1f));

			return attacks;
		}
	}

	public static class					KnightRapier extends Abstract
	{
		public							KnightRapier()
		{
			super("Knight rapier");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Thrust", 60, new Range<>(150, 400), 0.3f));
			attacks.add(new Attack("Double thrust", 20, new Range<>(200, 700), 0.25f));
			attacks.add(new Attack("Blow", 20, new Range<>(200), 0.01f));

			return attacks;
		}
	}

	public static class					LegendaryRapier extends Abstract
	{
		public							LegendaryRapier()
		{
			super("Legendary rapier");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Thrust", 60, new Range<>(400, 800), 0.3f));
			attacks.add(new Attack("Double thrust", 20, new Range<>(1000, 1800), 0.25f));
			attacks.add(new Attack("Blow", 20, new Range<>(500), 0.01f));

			return attacks;
		}
	}

// -----------------------------------> Swordsman + Assassin

	public static class					OldScimitar extends Abstract
	{
		public							OldScimitar()
		{
			super("Old scimitar");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 100, new Range<>(10, 40), 0.2f));

			return attacks;
		}
	}

	public static class					SteelScimitar extends Abstract
	{
		public							SteelScimitar()
		{
			super("Steel scimitar");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 100, new Range<>(40, 70), 0.2f));

			return attacks;
		}
	}

	public static class					BanditScimitar extends Abstract
	{
		public							BanditScimitar()
		{
			super("Bandit scimitar");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 100, new Range<>(120, 200), 0.2f));

			return attacks;
		}
	}

	public static class					LegendaryScimitar extends Abstract
	{
		public							LegendaryScimitar()
		{
			super("Legendary scimitar");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 100, new Range<>(500, 2500), 0.3f));

			return attacks;
		}
	}

// -----------------------------------> Assassin

	public static class					OldDagger extends Abstract
	{
		public							OldDagger()
		{
			super("Old dagger");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 100, new Range<>(20, 30), 0.5f));

			return attacks;
		}
	}

	public static class					SteelDagger extends Abstract
	{
		public							SteelDagger()
		{
			super("Steel dagger");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 100, new Range<>(100, 150), 0.5f));

			return attacks;
		}
	}

	public static class					BanditDagger extends Abstract
	{
		public							BanditDagger()
		{
			super("Bandit dagger");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 80, new Range<>(200, 250), 0.5f));
			attacks.add(new Attack("Bleeding cut", 20, new Range<>(300), 0.8f));

			return attacks;
		}
	}

	public static class					EnchantedDagger extends Abstract
	{
		public							EnchantedDagger()
		{
			super("Enchanted dagger");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Blow", 80, new Range<>(800, 900), 0.9f));

			return attacks;
		}
	}

// -----------------------------------> Mage

	public static class					BrokenStuff extends Abstract
	{
		public							BrokenStuff()
		{
			super("Broken stuff");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Magic arrow", 85, new Range<>(25), 0.0f));

			return attacks;
		}
	}

	public static class					StudentStuff extends Abstract
	{
		public							StudentStuff()
		{
			super("Student stuff");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Magic arrow", 85, new Range<>(30), 0.0f));
			attacks.add(new Attack("Heavy magic arrow", 15, new Range<>(50), 0.0f));

			return attacks;
		}
	}

	public static class					MasterStuff extends Abstract
	{
		public							MasterStuff()
		{
			super("Master stuff");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Magic arrow", 70, new Range<>(50), 0.0f));
			attacks.add(new Attack("Heavy magic arrow", 15, new Range<>(80), 0.0f));
			attacks.add(new Attack("Magic spear", 15, new Range<>(160), 0.0f));

			return attacks;
		}
	}

	public static class					RoyalMageStuff extends Abstract
	{
		public							RoyalMageStuff()
		{
			super("Royal mage stuff");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Magic arrow", 25, new Range<>(100), 0.0f));
			attacks.add(new Attack("Heavy magic arrow", 25, new Range<>(150), 0.0f));
			attacks.add(new Attack("Magic spear", 25, new Range<>(200), 0.0f));
			attacks.add(new Attack("Heavy magic spear", 15, new Range<>(250), 0.0f));
			attacks.add(new Attack("Cristal magic spear", 10, new Range<>(750), 0.0f));

			return attacks;
		}
	}

	public static class					CursedStuff extends Abstract
	{
		public							CursedStuff()
		{
			super("Cursed stuff");
		}

		public List<Attack>				getAttacks()
		{
			List<Attack>				attacks;

			attacks = new LinkedList<>();
			attacks.add(new Attack("Dark storm", 50, new Range<>(500), 0.4f));
			attacks.add(new Attack("Dark burst", 50, new Range<>(1000), 0.8f));

			return attacks;
		}
	}
}
