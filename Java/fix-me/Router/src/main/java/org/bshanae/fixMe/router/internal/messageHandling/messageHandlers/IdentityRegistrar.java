package org.bshanae.fixMe.router.internal.messageHandling.messageHandlers;

import org.bshanae.fixMe.router.internal.singletons.RoutingTable;
import org.bshanae.fixMe.router.internal.singletons.Server;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessage;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessageEncoder;

import java.net.SocketAddress;

public class				IdentityRegistrar extends MessageHandler
{
	@Override
	protected boolean		tryHandleMessage(FixMessage message, SocketAddress address)
	{
		FixMessage.Request	request;

		request = FixMessage.Request.fromCode(message.getFieldAsString(FixMessage.Key.REQUEST));
		if (request != FixMessage.Request.INIT)
			return false;

		int					newId;
		FixMessage			messageWithNewId;

		newId = RoutingTable.getInstance().register(address);
		messageWithNewId = new FixMessage(message);
		messageWithNewId.setField(FixMessage.Key.RECIPIENT_ID, newId);

		Server.getInstance().send(FixMessageEncoder.encode(messageWithNewId), address);
		return true;
	}
}
