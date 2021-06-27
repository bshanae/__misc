package org.bshanae.fixMe.router.internal.messageHandling.messageHandlers;

import org.bshanae.fixMe.router.internal.singletons.RoutingTable;
import org.bshanae.fixMe.router.internal.singletons.Server;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessage;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessageEncoder;

import java.net.SocketAddress;

public class					MessageForwarder extends MessageHandler
{
	private static FixMessage	buildErrorMessage()
	{
		FixMessage				message;

		message = new FixMessage();
		message.setField(FixMessage.Key.RESPONSE, "ERROR:UNKNOWN-ID");

		return message;
	}

	@Override
	protected boolean			tryHandleMessage(FixMessage message, SocketAddress originalAddress)
	{
		int						recipientId;
		SocketAddress			finalAddress;

		recipientId = message.getFieldAsInt(FixMessage.Key.RECIPIENT_ID);
		finalAddress = RoutingTable.getInstance().find(recipientId);

		if (finalAddress != null)
			Server.getInstance().send(FixMessageEncoder.encode(message), finalAddress);
		else
			Server.getInstance().send(FixMessageEncoder.encode(buildErrorMessage()), originalAddress);

		return true;
	}
}
