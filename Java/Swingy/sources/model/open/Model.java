package model.open;

import application.service.Debug;
import application.patterns.SingletonMap;
import application.patterns.uniqueNotifier.UniqueListener;
import application.patterns.uniqueNotifier.UniqueNotifier;
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
		Debug.log("[Model/Model] Sending request of type " + request.getClass());
		requestQueue.add(request);
	}

	@Override
	public void								listen(Commands.Abstract command)
	{
		Debug.log("[Model/Model] Received command of type " + command.getClass());
		Game.getInstance().respondToCommand(command);
	}
}
