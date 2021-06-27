package org.bshanae.fixMe.router.internal.messageHandling.messageHandlers;

import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessage;
import org.bshanae.fixMe.tools.system.Console;

import java.net.SocketAddress;

public class			MessageValidator extends MessageHandler
{
	@Override
	protected boolean	tryHandleMessage(FixMessage message, SocketAddress address)
	{
		if (!message.isValid())
		{
			Console.write("Message has invalid checksum!");
			return true;
		}

		return false;
	}
}
