package org.bshanae.fixMe.broker;

import lombok.Getter;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessage;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessageDecoder;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessageEncoder;
import org.bshanae.fixMe.tools.marketing.stock.Instrument;
import org.bshanae.fixMe.tools.marketing.stock.Stock;
import org.bshanae.fixMe.tools.system.AsyncExecutor;
import org.bshanae.fixMe.tools.system.network.Client;
import org.bshanae.fixMe.tools.system.network.Pocket;
import org.bshanae.fixMe.tools.system.Console;

import java.net.InetSocketAddress;
import java.net.SocketAddress;

public class							Broker
{
	private static final SocketAddress	ADDRESS = new InetSocketAddress("localhost", 5000);

	private final AsyncExecutor			asyncExecutor;

	@Getter
	private final Client				client;

	private final Stock					stock;

	private Integer						id;

	@Getter
	private boolean						isRunning;

	public								Broker()
	{
		asyncExecutor = new AsyncExecutor();
		client = new Client(ADDRESS);
		stock = new Stock();
	}

	void 								launchInBackground()
	{
		asyncExecutor.execute(this::launchSelf);
		asyncExecutor.execute(this::launchClient);

		sendInitMessage();
	}

	private void						launchClient()
	{
		client.launch();
	}

	private void						launchSelf()
	{
		isRunning = true;
		while (isRunning)
		{
			try
			{
				Thread.sleep(100);
			}
			catch (InterruptedException ignored)
			{
				return;
			}

			reinitIfNeeded();
			tryProcessNewMessage();
		}
	}

	private void						sendInitMessage()
	{
		FixMessage						fixMessage;

		fixMessage = new FixMessage();
		fixMessage.setField(FixMessage.Key.REQUEST, FixMessage.Request.INIT.toCode());
		client.send(FixMessageEncoder.encode(fixMessage));
	}

	private void						reinitIfNeeded()
	{
		if (client.didReconnect())
		{
			client.markReconnectAsRead();

			id = null;
			sendInitMessage();

			Console.write("Lost connection to server, resetting id");
		}
	}

	private void						tryProcessNewMessage()
	{
		Pocket							pocket;
		FixMessage						fixMessage;
		String							response;

		if ((pocket = client.receive()) != null)
		{
			fixMessage = FixMessageDecoder.decode(pocket);
			response = fixMessage.getFieldAsString(FixMessage.Key.RESPONSE);

			if (response == null)
				tryProcessInit(fixMessage);
			else if (response.equals("OK"))
				processSuccess(fixMessage);
			else if (response.startsWith("ERROR"))
				processError(fixMessage);
			else
				throw new RuntimeException("Can't identify response");
		}
	}

	private void						tryProcessInit(FixMessage message)
	{
		if (FixMessage.Request.fromCode(message.getFieldAsString(FixMessage.Key.REQUEST)) == FixMessage.Request.INIT)
		{
			id = message.getFieldAsInt(FixMessage.Key.RECIPIENT_ID);
			Console.write("Initialized with id %d", id);
		}
	}

	private void						processSuccess(FixMessage message)
	{
		if (id == null)
			throw new RuntimeException("Broker is not initialized");

		final FixMessage.Request		request = FixMessage.Request.fromCode(message.getFieldAsString(FixMessage.Key.REQUEST));
		final Instrument				instrument = stock.getOrPut(message.getFieldAsString(FixMessage.Key.INSTRUMENT));
		final Integer					quantity = message.getFieldAsInt(FixMessage.Key.QUANTITY);
		final Integer					price = message.getFieldAsInt(FixMessage.Key.PRICE);

		if (instrument == null)
			throw new RuntimeException("Instrument not found");

		if (request == FixMessage.Request.INFO)
		{
			instrument.setQuantity(quantity);
			instrument.setPrice(price);
			Console.write(instrument.getDescription());
		}
		else if (request == FixMessage.Request.BUY)
		{
			instrument.setQuantity(instrument.getQuantity() + quantity);
			Console.write("Success");
		}
		else if (request == FixMessage.Request.SELL)
		{
			instrument.setQuantity(instrument.getQuantity() - quantity);
			Console.write("Success");
		}
		else
			throw new RuntimeException("Can't identify request");
	}

	private void						processError(FixMessage message)
	{
		String							errorMessage;
		String[]						errorMessageArray;

		errorMessage = message.getFieldAsString(FixMessage.Key.RESPONSE);
		errorMessageArray = errorMessage.split(":");

		if (errorMessageArray.length != 2)
			throw new RuntimeException("Unexpected error format");

		Console.write("Error : " + errorMessageArray[1]);
	}

	public void							terminate()
	{
		isRunning = false;
		client.terminate();

		asyncExecutor.terminate();
	}

	public void							info(int marketId, String instrument)
	{
		FixMessage						message;

		message = new FixMessage();
		message.setField(FixMessage.Key.SENDER_ID, id);
		message.setField(FixMessage.Key.RECIPIENT_ID, marketId);
		message.setField(FixMessage.Key.INSTRUMENT, instrument);
		message.setField(FixMessage.Key.REQUEST, FixMessage.Request.INFO.toCode());

		client.send(FixMessageEncoder.encode(message));
	}

	public void							buy(int marketId, String instrument, int quantity, int price)
	{
		FixMessage						message;

		message = new FixMessage();
		message.setField(FixMessage.Key.SENDER_ID, id);
		message.setField(FixMessage.Key.RECIPIENT_ID, marketId);
		message.setField(FixMessage.Key.INSTRUMENT, instrument);
		message.setField(FixMessage.Key.QUANTITY, quantity);
		message.setField(FixMessage.Key.PRICE, price);
		message.setField(FixMessage.Key.REQUEST, FixMessage.Request.BUY.toCode());

		client.send(FixMessageEncoder.encode(message));
	}

	public void							sell(int marketId, String instrument, int quantity, int price)
	{
		FixMessage						message;

		message = new FixMessage();
		message.setField(FixMessage.Key.SENDER_ID, id);
		message.setField(FixMessage.Key.RECIPIENT_ID, marketId);
		message.setField(FixMessage.Key.INSTRUMENT, instrument);
		message.setField(FixMessage.Key.QUANTITY, quantity);
		message.setField(FixMessage.Key.PRICE, price);
		message.setField(FixMessage.Key.REQUEST, FixMessage.Request.SELL.toCode());

		client.send(FixMessageEncoder.encode(message));
	}

	public void all()
	{
		for (Instrument instrument : stock.getAll())
			Console.write(instrument.getDescription());
	}
}
