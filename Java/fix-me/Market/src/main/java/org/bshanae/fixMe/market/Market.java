package org.bshanae.fixMe.market;

import lombok.Getter;
import org.bshanae.fixMe.market.transaction.Transaction;
import org.bshanae.fixMe.market.transaction.TransactionHistory;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessage;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessageDecoder;
import org.bshanae.fixMe.tools.marketing.fixMessage.FixMessageEncoder;
import org.bshanae.fixMe.tools.marketing.stock.Stock;
import org.bshanae.fixMe.tools.system.AsyncExecutor;
import org.bshanae.fixMe.tools.marketing.stock.Instrument;
import org.bshanae.fixMe.tools.system.Console;
import org.bshanae.fixMe.tools.system.network.Client;
import org.bshanae.fixMe.tools.system.network.Pocket;

import java.net.InetSocketAddress;
import java.net.SocketAddress;

class										Market
{
	private static final SocketAddress		ADDRESS = new InetSocketAddress("localhost", 5001);

	private final AsyncExecutor				asyncExecutor;
	private final Client					client;
	private final Stock						stock;
	private final TransactionHistory		transactionHistory;

	private Integer							id;

	@Getter
	private boolean							isRunning;

											Market()
	{
		asyncExecutor = new AsyncExecutor();
		client = new Client(ADDRESS);
		stock = new Stock();
		transactionHistory = new TransactionHistory();
	}

	void									launchInBackground()
	{
		asyncExecutor.execute(this::launchSelf);
		asyncExecutor.execute(this::launchClient);

		sendInitMessage();

	}

	private void							launchSelf()
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

	private void							launchClient()
	{
		client.launch();
	}

	private void							sendInitMessage()
	{
		FixMessage							fixMessage;

		fixMessage = new FixMessage();
		fixMessage.setField(FixMessage.Key.REQUEST, FixMessage.Request.INIT.toCode());
		client.send(FixMessageEncoder.encode(fixMessage));
	}

	void									terminate()
	{
		client.terminate();
		isRunning = false;

		asyncExecutor.terminate();
	}

	private void							reinitIfNeeded()
	{
		if (client.didReconnect())
		{
			client.markReconnectAsRead();

			id = null;
			sendInitMessage();

			Console.write("Lost connection to server, resetting id");
		}
	}

	private void							tryProcessNewMessage()
	{
		Pocket								pocket;
		FixMessage							inMessage;
		FixMessage							outMessage;
		FixMessage.Request					request;

		if ((pocket = client.receive()) != null)
		{
			inMessage = FixMessageDecoder.decode(pocket);
			outMessage = new FixMessage();
			request = FixMessage.Request.fromCode(inMessage.getFieldAsString(FixMessage.Key.REQUEST));

			if (request == FixMessage.Request.INIT)
			{
				processInit(inMessage);
				return;
			}

			if (id == null)
				throw new RuntimeException("Market is not initialized");

			outMessage.setField(FixMessage.Key.SENDER_ID, id);
			outMessage.setField(FixMessage.Key.RECIPIENT_ID, inMessage.getFieldAsInt(FixMessage.Key.SENDER_ID));

			if (request == FixMessage.Request.INFO)
				processInfo(inMessage, outMessage);
			else if (request == FixMessage.Request.BUY)
				processBuy(inMessage, outMessage);
			else if (request == FixMessage.Request.SELL)
				processSell(inMessage, outMessage);
			else
				outMessage.setField(FixMessage.Key.RESPONSE, "ERROR:UNKNOWN-COMMAND");

			client.send(FixMessageEncoder.encode(outMessage));
		}
	}

	private void 							processInit(FixMessage message)
	{
		id = message.getFieldAsInt(FixMessage.Key.RECIPIENT_ID);
		Console.write("Initialized with id %d", id);
	}

	private void 							processInfo(FixMessage inMessage, FixMessage outMessage)
	{
		final String						instrumentName = inMessage.getFieldAsString(FixMessage.Key.INSTRUMENT);
		final Instrument					instrument = stock.get(instrumentName);

		outMessage.copyField(FixMessage.Key.REQUEST, inMessage);
		outMessage.copyField(FixMessage.Key.INSTRUMENT, inMessage);

		if (instrument == null)
		{
			outMessage.setField(FixMessage.Key.RESPONSE, "ERROR:INSTRUMENT-NOT-FOUND");
			return;
		}

		outMessage.setField(FixMessage.Key.RESPONSE, "OK");
		outMessage.setField(FixMessage.Key.QUANTITY, instrument.getQuantity());
		outMessage.setField(FixMessage.Key.PRICE, instrument.getPrice());
	}

	private void 							processBuy(FixMessage inMessage, FixMessage outMessage)
	{
		final String						instrumentName = inMessage.getFieldAsString(FixMessage.Key.INSTRUMENT);

		final Instrument					instrument = stock.get(instrumentName);
		final int							requestedQuantity = inMessage.getFieldAsInt(FixMessage.Key.QUANTITY);
		final int							requestedPrice = inMessage.getFieldAsInt(FixMessage.Key.PRICE);

		outMessage.copyField(FixMessage.Key.REQUEST, inMessage);
		outMessage.copyField(FixMessage.Key.INSTRUMENT, inMessage);
		outMessage.copyField(FixMessage.Key.QUANTITY, inMessage);

		if (instrument == null)
		{
			outMessage.setField(FixMessage.Key.RESPONSE, "ERROR:INSTRUMENT-NOT-FOUND");
			return;
		}

		final int							currentQuantity = instrument.getQuantity();
		final int							currentPrice = instrument.getPrice();

		if (requestedQuantity > currentQuantity)
		{
			outMessage.setField(FixMessage.Key.RESPONSE, "ERROR:NOT-ENOUGH-IN-STOCK");
			return;
		}

		if (requestedPrice < currentPrice)
		{
			outMessage.setField(FixMessage.Key.RESPONSE, "ERROR:DESIRED-PRICE-IS-TOO-LOW");
			return;
		}

		outMessage.setField(FixMessage.Key.RESPONSE, "OK");
		instrument.setQuantity(currentQuantity - requestedQuantity);

		saveTransaction(inMessage);
	}

	private void 							processSell(FixMessage inMessage, FixMessage outMessage)
	{
		final String						instrumentName = inMessage.getFieldAsString(FixMessage.Key.INSTRUMENT);

		final Instrument					instrument = stock.get(instrumentName);
		final int							offeredQuantity = inMessage.getFieldAsInt(FixMessage.Key.QUANTITY);

		outMessage.copyField(FixMessage.Key.REQUEST, inMessage);
		outMessage.copyField(FixMessage.Key.INSTRUMENT, inMessage);
		outMessage.copyField(FixMessage.Key.QUANTITY, inMessage);

		if (instrument == null)
		{
			outMessage.setField(FixMessage.Key.RESPONSE, "ERROR:INSTRUMENT-NOT-FOUND");
			return;
		}

		outMessage.setField(FixMessage.Key.RESPONSE, "OK");
		instrument.setQuantity(instrument.getQuantity() + offeredQuantity);

		saveTransaction(inMessage);
	}

	void 									setInstrument(String name, int quantity, int price)
	{
		Instrument							instrument;

		instrument = stock.getOrPut(name);
		instrument.setQuantity(quantity);
		instrument.setPrice(price);
	}

	String									getInstrument(String name)
	{
		Instrument							instrument;

		instrument = stock.get(name);
		return instrument != null ? instrument.getDescription() : "none";
	}

	void 									all()
	{
		for (Instrument instrument : stock.getAll())
			Console.write(instrument.getDescription());
	}

	void									transactionsClear()
	{
		transactionHistory.clear();
	}

	void									transactionsAll()
	{
		for (Transaction transaction : transactionHistory.getAll())
			Console.write(transaction);
	}

	private void							saveTransaction(FixMessage message)
	{
		Transaction							transaction;

		transaction = new Transaction();
		transaction.setAction(message.getFieldAsString(FixMessage.Key.REQUEST));
		transaction.setInstrument(message.getFieldAsString(FixMessage.Key.INSTRUMENT));
		transaction.setPrice(message.getFieldAsInt(FixMessage.Key.PRICE));
		transaction.setQuantity(message.getFieldAsInt(FixMessage.Key.QUANTITY));

		transactionHistory.put(transaction);
	}
}
