package model.closed.objects.creatures.hero;

import application.utils.Describable;
import model.closed.objects.creatures.Creature;

public class				Hero
							extends Creature
							implements Describable
{
	private final String	name;
	private final HeroClass heroClass;

	private int				level;
	private int				experience;
	private int				attack;
	private int				defense;
	private int				hp;

	@Override
	public String			getShortDescription()
	{
		return name;
	}

	@Override
	public String			getLongDescription()
	{
		return "[Hero : name = '" + name + "', class = " + heroClass.getShortDescription() + "]";
	}
	
	public					Hero(String name, HeroClass heroClass)
	{
		this.name = name;
		this.heroClass = heroClass;
		this.level = 0;
		this.experience = 0;
		this.attack = 0;
		this.defense = 0;
		this.hp = 0;
	}

	public String			getName()
	{
		return name;
	}

	public HeroClass		getHeroClass()
	{
		return heroClass;
	}

	public int				getLevel()
	{
		return level;
	}

	public void				setLevel(int level)
	{
		this.level = level;
	}

	public int				getExperience()
	{
		return experience;
	}

	public void				addExperience(int value)
	{
		this.experience = value;
	}

	public int				getAttack()
	{
		return attack;
	}

	public void				setAttack(int attack)
	{
		this.attack = attack;
	}

	public int				getDefense()
	{
		return defense;
	}

	public void				setDefense(int defense)
	{
		this.defense = defense;
	}

	public int				getHp()
	{
		return hp;
	}

	public void				setHp(int hp)
	{
		this.hp = hp;
	}
}