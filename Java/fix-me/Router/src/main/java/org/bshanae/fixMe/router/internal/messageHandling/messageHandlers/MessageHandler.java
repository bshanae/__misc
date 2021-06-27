package org.bshanae.fixMe.router.internal.messageHandling.messageHandlers;

import lombok.Setter;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessage;

import java.net.SocketAddress;

public abstract class			MessageHandler
{
	@Setter
	private MessageHandler		nextHandler;

	public void					handleMessage(FixMessage message, SocketAddress address)
	{
		if (!tryHandleMessage(message, address))
		{
			if (nextHandler != null)
				nextHandler.handleMessage(message, address);
		}
	}

	protected abstract boolean	tryHandleMessage(FixMessage message, SocketAddress address);
}
