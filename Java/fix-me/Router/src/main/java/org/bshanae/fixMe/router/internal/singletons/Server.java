package org.bshanae.fixMe.router.internal.singletons;

import org.bshanae.fixMe.tools.system.Console;

import java.net.InetSocketAddress;
import java.net.SocketAddress;

public class								Server extends org.bshanae.fixMe.tools.system.network.Server
{
	private static final SocketAddress		BROKER_ADDRESS = new InetSocketAddress("localhost", 5000);
	private static final SocketAddress		MARKET_ADDRESS = new InetSocketAddress("localhost", 5001);

	private static Server					instance;

	public static Server					getInstance()
	{
		if (instance == null)
			instance = new Server();

		return instance;
	}

	private									Server()
	{
		if (register(BROKER_ADDRESS))
			Console.write("Registered broker");
		else
			Console.write("Failed to register broker");

		if (register(MARKET_ADDRESS))
			Console.write("Registered market");
		else
			Console.write("Failed to register market");
	}
}
