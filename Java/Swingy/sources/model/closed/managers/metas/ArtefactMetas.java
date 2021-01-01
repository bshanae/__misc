package model.closed.managers.metas;

import model.closed.objects.artefacts.Artefact;
import model.closed.objects.creatures.hero.HeroClass;

public class								ArtefactMetas
{
// ---------------------------------------> Interface

	public static abstract class			Abstract
	{
		private final float					dropProbability;

		public								Abstract(float dropProbability)
		{
			this.dropProbability = dropProbability;
		}

		public final float					getDropProbability()
		{
			return dropProbability;
		}

		public abstract int					getHeroClassFlags();

		public abstract Artefact			getInstance();
	}

// ---------------------------------------> Helms

	public static class						OldHelm extends Abstract
	{
		public								OldHelm(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Helms.OldHelm();
		}
	}

	public static class						LeatherHelm extends Abstract
	{
		public								LeatherHelm(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Helms.LeatherHelm();
		}
	}

	public static class						SteelHelm extends Abstract
	{
		public								SteelHelm(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Helms.SteelHelm();
		}
	}

	public static class						SoldierHelm extends Abstract
	{
		public								SoldierHelm(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Helms.SoldierHelm();
		}
	}

	public static class						KnightHelm extends Abstract
	{
		public								KnightHelm(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Helms.KnightHelm();
		}
	}

	public static class						LegendaryHelm extends Abstract
	{
		public								LegendaryHelm(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Helms.LegendaryHelm();
		}
	}


// ---------------------------------------> Armors

	public static class						OldArmor extends Abstract
	{
		public								OldArmor(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Armors.OldArmor();
		}
	}

	public static class						LeatherArmor extends Abstract
	{
		public								LeatherArmor(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Armors.LeatherArmor();
		}
	}

	public static class						ChainArmor extends Abstract
	{
		public								ChainArmor(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Armors.ChainArmor();
		}
	}

	public static class						SoldierArmor extends Abstract
	{
		public								SoldierArmor(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Armors.SoldierArmor();
		}
	}

	public static class						KnightArmor extends Abstract
	{
		public								KnightArmor(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Armors.KnightArmor();
		}
	}

	public static class						LegendaryArmor extends Abstract
	{
		public								LegendaryArmor(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag() | HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Armors.LegendaryArmor();
		}
	}

// ---------------------------------------> Weapons : Warrior

	public static class						Hammer extends Abstract
	{
		public								Hammer(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.Hammer();
		}
	}

	public static class						GreatHammer extends Abstract
	{
		public								GreatHammer(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.GreatHammer();
		}
	}

// ---------------------------------------> Weapons : Warrior + Swordsman + Assassin

	public static class						OldSword extends Abstract
	{
		public								OldSword(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.OldSword();
		}
	}

	public static class						SteelSword extends Abstract
	{
		public								SteelSword(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.SteelSword();
		}
	}

	public static class						SoldierSword extends Abstract
	{
		public								SoldierSword(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.SoldierSword();
		}
	}

	public static class						KnightSword extends Abstract
	{
		public								KnightSword(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.WARRIOR.toFlag() | HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.KnightSword();
		}
	}


// ---------------------------------------> Weapons : Swordsman

	public static class						Rapier extends Abstract
	{
		public								Rapier(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.SWORDSMAN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.Rapier();
		}
	}

	public static class						KnightRapier extends Abstract
	{
		public								KnightRapier(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.SWORDSMAN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.KnightRapier();
		}
	}

	public static class						LegendaryRapier extends Abstract
	{
		public								LegendaryRapier(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.SWORDSMAN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.LegendaryRapier();
		}
	}

// ---------------------------------------> Weapons : Swordsman + Assassin

	public static class						OldScimitar extends Abstract
	{
		public								OldScimitar(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.OldScimitar();
		}
	}

	public static class						SteelScimitar extends Abstract
	{
		public								SteelScimitar(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.SteelScimitar();
		}
	}

	public static class						BanditScimitar extends Abstract
	{
		public								BanditScimitar(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.BanditScimitar();
		}
	}

	public static class						LegendaryScimitar extends Abstract
	{
		public								LegendaryScimitar(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.SWORDSMAN.toFlag() | HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.LegendaryScimitar();
		}
	}

// ---------------------------------------> Weapons : Assassin

	public static class						OldDagger extends Abstract
	{
		public								OldDagger(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.OldDagger();
		}
	}

	public static class						SteelDagger extends Abstract
	{
		public								SteelDagger(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.SteelDagger();
		}
	}

	public static class						BanditDagger extends Abstract
	{
		public								BanditDagger(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.BanditDagger();
		}
	}

	public static class						EnchantedDagger extends Abstract
	{
		public								EnchantedDagger(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.ASSASSIN.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.EnchantedDagger();
		}
	}

// ---------------------------------------> Weapons : Mage

	public static class						BrokenStuff extends Abstract
	{
		public								BrokenStuff(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.BrokenStuff();
		}
	}

	public static class						StudentStuff extends Abstract
	{
		public								StudentStuff(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.StudentStuff();
		}
	}

	public static class						MasterStuff extends Abstract
	{
		public								MasterStuff(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.MasterStuff();
		}
	}

	public static class						RoyalMageStuff extends Abstract
	{
		public								RoyalMageStuff(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.RoyalMageStuff();
		}
	}

	public static class						CursedStuff extends Abstract
	{
		public								CursedStuff(float dropProbability)
		{
			super(dropProbability);
		}

		@Override
		public int							getHeroClassFlags()
		{
			return HeroClass.MAGE.toFlag();
		}

		@Override
		public Artefact						getInstance()
		{
			return new model.closed.objects.artefacts.Weapons.CursedStuff();
		}
	}
}
