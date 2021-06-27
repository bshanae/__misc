package org.bshanae.fixMe.router.internal.messageHandling;

import org.bshanae.fixMe.router.internal.messageHandling.messageHandlers.MessageHandler;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessage;

import java.net.SocketAddress;

public class				MessageHandlersChain
{
	private MessageHandler	first;
	private MessageHandler	last;

	public void				addHandler(MessageHandler messageHandler)
	{
		if (first == null)
		{
			first = messageHandler;
			last = messageHandler;
		}
		else
		{
			last.setNextHandler(messageHandler);
			last = messageHandler;
		}
	}

	public void 			handleMessage(FixMessage message, SocketAddress address)
	{
		first.handleMessage(message, address);
	}
}
