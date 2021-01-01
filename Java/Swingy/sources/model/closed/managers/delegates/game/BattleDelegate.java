package model.closed.managers.delegates.game;

import controller.open.Commands;
import model.closed.managers.battle.Battle;
import model.closed.managers.battle.BattleLogger;
import model.closed.managers.delegates.Delegate;
import model.closed.objects.creatures.enemies.Enemy;
import model.open.Requests;

import java.util.Timer;
import java.util.TimerTask;

public class					BattleDelegate extends Delegate
{
	private class				RequestBattleTurnTask extends TimerTask
	{
		@Override
		public void				run()
		{
			timer = null;
			shouldExecuteTurn = true;
		}
	}

	private static final float	LOG_DELAY = 1.f;
	private static final float	MILLISECONDS_IN_A_SECOND = 1000;

	private final Battle		battle;

	private Timer				timer;
	private boolean				shouldExecuteTurn;

	public						BattleDelegate(Enemy opponent)
	{
		battle = new model.closed.managers.battle.Battle(opponent);
		battle.setLogger(new BattleLogger());

		timer = null;
		shouldExecuteTurn = false;
	}

	@Override
	protected void				whenActivated(boolean isFirstTime)
	{
		showLog();
	}

	@Override
	protected void				whenUpdated()
	{
		if (timer == null)
		{
			timer = new Timer();
			timer.schedule(new RequestBattleTurnTask(), (int)(LOG_DELAY * MILLISECONDS_IN_A_SECOND));
		}

		if (shouldExecuteTurn)
		{
			if (!battle.isFinished())
			{
				battle.executeTurn();
				showLog();
			}

			shouldExecuteTurn = false;
		}
	}

	@Override
	protected void				whenResponded(Commands.Abstract command)
	{
		if (command instanceof Commands.Ok)
			requestResolution();
	}

	private void				showLog()
	{
		sendRequest(new Requests.Battle(battle));
	}
}
