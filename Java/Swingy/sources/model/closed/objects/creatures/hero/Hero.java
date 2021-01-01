package model.closed.objects.creatures.hero;

import application.service.Debug;
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
	public int					getLevel()
	{
		return level;
	}

	@Override
	public int					getBaseHealth()
	{
		return calculateOwnHealth() + (helm != null ? helm.getHealthIncrease() : 0);
	}

	@Override
	public int					getDefense()
	{
		return calculateOwnDefense() + (armor != null ? armor.getDefense() : 0);
	}

	@Override
	public List<Attack>			getAttacks()
	{
		return weapon != null ? transformAttacks(weapon.getAttacks()) : new LinkedList<>();
	}

	public HeroClass			getHeroClass()
	{
		return heroClass;
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

// ---------------------------> Public methods

	public void					addExperience(int value)
	{
		Debug.logFormat("[Model/Hero] Hero gained %d experience", value);

		this.experience += value;
		updateLevel();
	}

// ---------------------------> Private methods

	private int					calculateOwnHealth()
	{
		return 100 * (level + 1);
	}

	private int					calculateOwnDefense()
	{
		return 5 * (level + 1);
	}

	private int					calculateAttackGain()
	{
		return 10 * (level + 1);
	}

	private int					calculateExperienceForNextLevel()
	{
		return level * 1000 + (level - 1) * (level - 1) * 450;
	}

	private void				updateLevel()
	{
		int						experienceForNextLevel;

		experienceForNextLevel = calculateExperienceForNextLevel();
		if (experience >= experienceForNextLevel)
		{
			experience -= experienceForNextLevel;
			level++;

			Debug.logFormat("[Model/Hero] Hero upgraded to level %d", level);
		}
	}

	private List<Attack>		transformAttacks(List<Attack> rawAttacks)
	{
		int						gain;
		List<Attack>			attacks;

		gain = calculateAttackGain();
		attacks = new LinkedList<>();

		for (Attack rawAttack : rawAttacks)
			attacks.add(rawAttack.applyGain(gain));

		return attacks;
	}
}