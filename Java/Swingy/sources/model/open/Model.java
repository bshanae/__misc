package model.open;

import application.common.SingletonMap;
import application.common.uniqueNotifier.UniqueListener;
import application.common.uniqueNotifier.UniqueNotifier;
import controller.open.Commands;
import model.closed.Game;

import java.util.LinkedList;
import java.util.Queue;

public class								Model
												extends UniqueNotifier<Requests.Abstract>
												implements UniqueListener<Commands.Abstract>
{
	private final Queue<Requests.Abstract>	requestQueue;

	public static Model						getInstance()
	{
		return SingletonMap.getInstanceOf(Model.class);
	}

	public boolean							isTerminated()
	{
		return Game.getInstance().isTerminated();
	}

	public									Model()
	{
		requestQueue = new LinkedList<>();
	}

	public void								run()
	{
		Game.getInstance().run();
	}

	public void								update()
	{
		Game.getInstance().update();

		if (!requestQueue.isEmpty())
			super.notifyListener(requestQueue.poll());
	}

	public void								notifyListener(Requests.Abstract request)
	{
		requestQueue.add(request);
	}

	@Override
	public void								listen(Commands.Abstract command)
	{
		Game.getInstance().respondToCommand(command);
	}
}
