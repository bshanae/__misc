package model.closed.gameConcepts.delegates.common;

import controller.open.Commands;
import model.closed.gameConcepts.delegates.Delegate;
import model.open.Requests;

public class        		ErrorDelegate extends Delegate
{
	private final String	message;

	public          		ErrorDelegate(String message)
	{
		this.message = message;
	}

	@Override
	public void				whenActivated(boolean isFirstTimeActivated)
	{
		sendRequest(new Requests.Error(message));
	}

	@Override
	public void				whenResponded(Commands.Abstract command)
	{
		resolve();
	}
}
