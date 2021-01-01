package model.closed.objects.artefacts;

public abstract class				Helms
{
	public static abstract class	Abstract implements Artefact
	{
		private final int			healthIncrease;

		public 						Abstract(int healthIncrease)
		{
			this.healthIncrease = healthIncrease;
		}

		public int					getHealthIncrease()
		{
			return healthIncrease;
		}
	}
}
