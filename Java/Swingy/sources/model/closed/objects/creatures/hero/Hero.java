package model.closed.objects.creatures.hero;

import model.closed.objects.Attack;
import model.closed.objects.artefacts.Armors;
import model.closed.objects.artefacts.Helms;
import model.closed.objects.artefacts.Weapons;
import model.closed.objects.creatures.Creature;

import java.util.LinkedList;
import java.util.List;

public class					Hero extends Creature
{
// ---------------------------> Attributes

	private final HeroClass 	heroClass;
	private int					level;
	private int					experience;

	private Helms.Abstract		helm;
	private Armors.Abstract		armor;
	private Weapons.Abstract	weapon;

// ---------------------------> Properties

	@Override
	public int					getBaseHealth()
	{
		// TODO
		return 1000;
	}

	public HeroClass			getHeroClass()
	{
		return heroClass;
	}

	public int					getLevel()
	{
		return level;
	}

	public void					setLevel(int level)
	{
		this.level = level;
	}

	public int					getExperience()
	{
		return experience;
	}

	public void					setExperience(int value)
	{
		this.experience = value;
	}

	public Helms.Abstract		getHelm()
	{
		return helm;
	}

	public void					setHelm(Helms.Abstract helm)
	{
		this.helm = helm;
	}

	public Armors.Abstract		getArmor()
	{
		return armor;
	}

	public void					setArmor(Armors.Abstract armor)
	{
		this.armor = armor;
	}

	public Weapons.Abstract		getWeapon()
	{
		return weapon;
	}

	public void					setWeapon(Weapons.Abstract weapon)
	{
		this.weapon = weapon;
	}

	@Override
	public List<Attack>			getAttacks()
	{
		return weapon != null ? weapon.getAttacks() : new LinkedList<>();
	}

// ---------------------------> Constructor

	public						Hero(String name, HeroClass heroClass)
	{
		super(name);

		this.heroClass = heroClass;
		this.level = 0;
		this.experience = 0;

		// TODO Remove
		setWeapon(new Weapons.Sword());
	}

}