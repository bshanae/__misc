package model.closed.objects;

import application.utils.Range;

public class						Attack
{
	public static final float		CRITICAL_MULTIPLIER = 2.5f;

	public final String				name;
	public final float				weight;
	public final Range<Integer>		damageRange;
	public final float				criticalChance;

	public 							Attack
									(
										String name,
										float weight,
										Range<Integer> damageRange,
										float criticalChance
									)
	{
		this.name = name;
		this.weight = weight;
		this.damageRange = damageRange;
		this.criticalChance = criticalChance;
	}
}
