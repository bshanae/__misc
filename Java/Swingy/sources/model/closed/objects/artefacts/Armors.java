package model.closed.objects.artefacts;

public abstract class				Armors
{
	public static abstract class	Abstract implements Artefact
	{
		private final int			defense;

		public						Abstract(int defense)
		{
			this.defense = defense;
		}

		public int					getDefense()
		{
			return defense;
		}
	}
}
