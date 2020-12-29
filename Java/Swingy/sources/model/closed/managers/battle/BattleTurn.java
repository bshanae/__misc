package model.closed.managers.battle;

enum					BattleTurn
{
	HERO,
	OPPONENT;

	public BattleTurn	next()
	{
		switch (this)
		{
			case HERO:
				return OPPONENT;

			case OPPONENT:
				return HERO;
		}

		return null;
	}
}