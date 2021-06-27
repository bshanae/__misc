package org.bshanae.fixMe.tools.system.network;

import org.bshanae.fixMe.tools.system.Console;
import org.bshanae.fixMe.tools.system.logging.Logger;

import java.io.IOException;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.*;
import java.util.*;

public class										Server
{
	private class									RetryTask extends TimerTask
	{
		@Override
		public void									run()
		{
			canRetry = true;
		}
	}

	private static final int						BUFFER_SIZE = 1024;
	private static final int						SELECT_TIMEOUT = 10;

	private final ByteBuffer						buffer;
	private final Selector							selector;

	private final Map<SocketAddress, SocketChannel>	socketChannels;

	private final Logger							logger;
	private final Queue<Pocket>						input;
	private final Queue<Pocket>						output;
	private final Queue<Pocket>						retryOutput;
	private final Timer								timerForRetrying;

	private boolean									isRunning;
	private boolean									canRetry;


	public											Server()
	{
		Selector									temporarySelector = null;

		try
		{
			temporarySelector = Selector.open();
		}
		catch (IOException ignored)
		{
		}

		buffer = ByteBuffer.allocate(BUFFER_SIZE);
		selector = temporarySelector;
		socketChannels = new HashMap<>();

		logger = new Logger(this.getClass());
		input = new LinkedList<>();
		output = new LinkedList<>();
		retryOutput = new LinkedList<>();
		timerForRetrying = new Timer();

		canRetry = false;
	}

	public boolean									register(SocketAddress address)
	{
		try
		{
			final ServerSocketChannel				serverSocketChannel = ServerSocketChannel.open();
			SelectionKey							selectionKey;

			logger.logInfo("Registering address {}", address);

			serverSocketChannel.configureBlocking(false);
			serverSocketChannel.bind(address);

			selectionKey = serverSocketChannel.register(selector, SelectionKey.OP_ACCEPT);
			selectionKey.attach(address);

			return true;
		}
		catch (IOException exception)
		{
			logger.logError("Registration error : {}", exception);
			return false;
		}
	}

	public void										launch()
	{
		Iterator<SelectionKey>						selectionKeyIterator;
		SelectionKey								selectionKey;

		Pocket										pocket;
		Iterator<Pocket>							pocketIterator;

		timerForRetrying.schedule(new RetryTask(), 0, 1000);

		try
		{
			isRunning = true;
			while (isRunning)
			{
				while (!output.isEmpty())
				{
					pocket = output.poll();
					if (!requestWriting(pocket))
						retryOutput.add(pocket);
				}

				if (canRetry)
				{
					pocketIterator = retryOutput.iterator();
					while (pocketIterator.hasNext())
					{
						if (requestWriting(pocketIterator.next()))
							pocketIterator.remove();
					}

					canRetry = false;
				}

				if (selector.select(SELECT_TIMEOUT) == 0)
					continue;

				selectionKeyIterator = selector.selectedKeys().iterator();
				while (selectionKeyIterator.hasNext())
				{
					selectionKey = selectionKeyIterator.next();

					if (selectionKey.isAcceptable())
						accept(selectionKeyIterator, selectionKey);
					else if (selectionKey.isWritable())
						write(selectionKeyIterator, selectionKey);
					else if (selectionKey.isReadable())
						read(selectionKeyIterator, selectionKey);
				}
			}

			timerForRetrying.cancel();

			for (Map.Entry<SocketAddress, SocketChannel> addressAndChannel : socketChannels.entrySet())
			{
				addressAndChannel.getValue().close();
				logger.logInfo("Closed channel at {}", addressAndChannel.getKey());
			}
		}
		catch (Exception exception)
		{
			logger.logException("Server launch error", exception);
		}
	}

	private boolean									requestWriting(Pocket pocket)
	{
		SocketChannel								socketChannel;
		SelectionKey								selectionKey;

		logger.logInfo("Requesting sending of message '{}' to {}", pocket.getString(), pocket.getAddress());

		socketChannel = socketChannels.get(pocket.getAddress());
		if (socketChannel == null)
		{
			logger.logError("Channel with address {} not found!", pocket.getAddress());
			return false;
		}

		try
		{
			selectionKey = socketChannel.register(selector, SelectionKey.OP_WRITE);
			selectionKey.attach(pocket.getString());
		}
		catch (Exception exception)
		{
			logger.logException("Can't write to channel : ", exception);
			return false;
		}

		return true;
	}

	private void									accept(Iterator<SelectionKey> iterator, SelectionKey key) throws IOException
	{
		final ServerSocketChannel					serverSocketChannel = (ServerSocketChannel) key.channel();
		final SocketChannel							socketChannel = serverSocketChannel.accept();

		if (socketChannel != null)
		{
			logger.logInfo("Connection is accepted : {}", socketChannel.getLocalAddress());

			socketChannel.configureBlocking(false);
			socketChannel.register(selector, SelectionKey.OP_READ);

			socketChannels.put(socketChannel.getLocalAddress(), socketChannel);
		}

		iterator.remove();
	}

	private void									read(Iterator<SelectionKey> iterator, SelectionKey key)
	{
		final SocketChannel							socketChannel = (SocketChannel)key.channel();
		String										string;
		int											numberOfBytesRead;

		try
		{
			buffer.clear();
			numberOfBytesRead = socketChannel.read(buffer);

			if (numberOfBytesRead < 0)
			{
				socketChannels.remove(socketChannel.getLocalAddress());
				socketChannel.close();
				iterator.remove();

				Console.write("Unregistered channel at '{}'", socketChannel.getLocalAddress());
			}
			else if (numberOfBytesRead == 0)
			{
				logger.logInfo("Received empty pocket from '{}'", socketChannel.getLocalAddress());
			}
			else
			{
				string = new String(buffer.array(), 0, buffer.position());
				logger.logInfo("Received string '{}' from {}", string, socketChannel.getLocalAddress());
				input.add(new Pocket(string, socketChannel.getLocalAddress()));
			}
		}
		catch (ClosedChannelException closedChannelException)
		{
			socketChannels.values().remove(socketChannel);
			Console.write("Unregistered a channel");
		}
		catch (IOException exception)
		{
			logger.logException("Caught exception while reading", exception);
		}
	}

	private void									write(Iterator<SelectionKey> iterator, SelectionKey key) throws IOException
	{
		final SocketChannel							socketChannel = (SocketChannel)key.channel();
		final String								string = (String) key.attachment();

		logger.logInfo("Sending message '{}' to {}", string, socketChannel.getLocalAddress());
		socketChannel.write(ByteBuffer.wrap(string.getBytes()));

		socketChannel.register(selector, SelectionKey.OP_READ);
		iterator.remove();
	}

	public void										terminate()
	{
		isRunning = false;
	}

	public void 									send(Pocket pocket, SocketAddress address)
	{
		output.add(new Pocket(pocket.getString(), address));
	}

	public Pocket									receive()
	{
		return input.isEmpty() ? null : input.poll();
	}
}
