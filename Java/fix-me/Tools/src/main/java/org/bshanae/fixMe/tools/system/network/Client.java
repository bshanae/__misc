package org.bshanae.fixMe.tools.system.network;

import org.bshanae.fixMe.tools.system.logging.Logger;
import org.bshanae.fixMe.tools.system.Console;

import java.io.IOException;
import java.net.SocketAddress;
import java.net.SocketException;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.util.LinkedList;
import java.util.Queue;

public class						Client
{
	private static final class		LostConnectionToSocketException extends Exception {}

	private static final int		BUFFER_SIZE = 1024;

	private final SocketAddress		address;

	private final Logger			logger;
	private final Queue<Pocket>		input;
	private final Queue<Pocket>		output;

	private SocketChannel			socketChannel;
	private boolean					isRunning;

	private int						connectCount;
	private boolean					didReconnect;

	public boolean					didReconnect()
	{
		return didReconnect;
	}

	public void						markReconnectAsRead()
	{
		didReconnect = false;
	}

	public							Client(SocketAddress address)
	{
		this.address = address;

		this.logger = new Logger(this.getClass());
		this.input = new LinkedList<>();
		this.output = new LinkedList<>();

		this.connectCount = 0;
		this.didReconnect = false;
	}

	public void						launch()
	{
		isRunning = true;

		while (true)
		{
			try
			{
				if (connect())
					work();

				break;
			}
			catch (LostConnectionToSocketException exception)
			{
				logger.logInfo("Lost connection to server");
			}
		}
	}

	public void 					terminate()
	{
		isRunning = false;
	}

	private boolean					connect()
	{
		while (isRunning)
		{
			if (tryConnect())
				return true;

			try
			{
				Thread.sleep(3500);
			}
			catch (InterruptedException ignored)
			{
				return false;
			}
		}

		return false;
	}

	private boolean					tryConnect()
	{
		Console.write("Trying to connect to server...");

		try
		{
			socketChannel = SocketChannel.open(address);
			socketChannel.configureBlocking(false);

			if (connectCount++ > 0)
				didReconnect = true;

			Console.write("Connected to server!");
		}
		catch (IOException exception)
		{
			return false;
		}

		return true;
	}

	private void					work() throws LostConnectionToSocketException
	{
		try
		{
			final ByteBuffer		buffer = ByteBuffer.allocate(BUFFER_SIZE);

			String					string;
			Pocket					pocket;
			int						read;

			logger.logInfo("Connecting to server at {}", address);

			while (isRunning)
			{
				try
				{
					buffer.clear();
					read = socketChannel.read(buffer);

					if (read > 0)
					{
						string = new String(buffer.array(), 0, buffer.position());
						logger.logInfo("Received message '{}'", string);

						input.add(new Pocket(string));
					}
					else if (read == -1)
					{
						throw new LostConnectionToSocketException();
					}
				}
				catch (SocketException exception)
				{
					logger.logInfo("Caught socket exception '{}'", exception.getMessage());
					throw new LostConnectionToSocketException();
				}

				if (!output.isEmpty())
				{
					pocket = output.poll();
					logger.logInfo("Sending message '{}'", pocket.getString());

					socketChannel.write(ByteBuffer.wrap(pocket.getString().getBytes()));
				}
			}

			socketChannel.close();
			logger.logInfo("Disconnecting");
		}
		catch (IOException exception)
		{
			logger.logException("Exception", exception);
		}
	}

	public void 					send(Pocket pocket)
	{
		output.add(pocket);
	}

	public Pocket					receive()
	{
		return input.isEmpty() ? null : input.poll();
	}
}
