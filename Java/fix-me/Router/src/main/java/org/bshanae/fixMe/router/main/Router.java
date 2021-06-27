package org.bshanae.fixMe.router.main;

import lombok.Getter;
import org.bshanae.fixMe.router.internal.messageHandling.MessageHandlersChain;
import org.bshanae.fixMe.router.internal.messageHandling.messageHandlers.IdentityRegistrar;
import org.bshanae.fixMe.router.internal.messageHandling.messageHandlers.MessageForwarder;
import org.bshanae.fixMe.router.internal.messageHandling.messageHandlers.MessageValidator;
import org.bshanae.fixMe.router.internal.singletons.Server;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessageDecoder;
import org.bshanae.fixMe.tools.system.AsyncExecutor;
import org.bshanae.fixMe.tools.system.network.Pocket;

public class                    		Router
{
	private final AsyncExecutor			asyncExecutor;
	private final MessageHandlersChain	messageHandlersChain;

	@Getter
	private boolean						isRunning;

										Router()
	{
		asyncExecutor = new AsyncExecutor();

		messageHandlersChain = new MessageHandlersChain();
		messageHandlersChain.addHandler(new MessageValidator());
		messageHandlersChain.addHandler(new IdentityRegistrar());
		messageHandlersChain.addHandler(new MessageForwarder());
	}

	void								launchInBackground()
	{
		asyncExecutor.execute(this::launchSelf);
		asyncExecutor.execute(this::launchServer);
	}

	private void						launchSelf()
	{
		isRunning = true;
		while (isRunning)
		{
			try
			{ Thread.sleep(100); }
			catch (InterruptedException ignored)
			{ return; }

			tryProcessNewMessage();
		}
	}

	private void						launchServer()
	{
		Server.getInstance().launch();
	}

	void								terminate()
	{
		isRunning = false;

		Server.getInstance().terminate();
		asyncExecutor.terminate();
	}

	private void						tryProcessNewMessage()
	{
		Pocket							pocket;

		if ((pocket = Server.getInstance().receive()) != null)
			messageHandlersChain.handleMessage(FixMessageDecoder.decode(pocket), pocket.getAddress());
	}
}
