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
	private static final float	LOG_DELAY = 1.2f;
	private static final float	MILLISECONDS_IN_A_SECOND = 1000;

	private final Battle		battle;
	private final BattleLogger	battleLogger;

	private Timer				timer;
	private boolean				shouldShowLog;

	public						BattleDelegate(Enemy opponent)
	{
		battle = new Battle(opponent);
		battleLogger = new BattleLogger();

		battle.attachLogger(battleLogger);

		timer = null;
		shouldShowLog = false;
	}

	@Override
	protected void				whenActivated(boolean isFirstTime)
	{
		showLog();
	}

	@Override
	protected void				whenUpdated()
	{
		updateTimer();
		showLogIfNeeded();
	}

	@Override
	protected void				whenResponded(Commands.Abstract command)
	{
	}

	private void				showLog()
	{
		sendRequest(new Requests.BattleLog(battleLogger));
	}

	private void				showLogIfNeeded()
	{
		if (shouldShowLog)
		{
			showLog();
			shouldShowLog = false;
		}
	}

	private void				updateTimer()
	{
		if (timer == null)
		{
			timer = new Timer();
			timer.schedule
			(
				new TimerTask()
				{
					@Override
					public void	run()
					{
						timer = null;
						shouldShowLog = true;
					}
				},
				(int)(LOG_DELAY * MILLISECONDS_IN_A_SECOND)
			);
		}
	}
}
