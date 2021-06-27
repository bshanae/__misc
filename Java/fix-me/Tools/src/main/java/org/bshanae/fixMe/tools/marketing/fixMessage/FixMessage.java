package org.bshanae.fixMe.tools.marketing.fixMessage;

import java.util.HashMap;
import java.util.Map;

public class							FixMessage
{
	public enum							Key
	{
		SENDER_ID(0),
		RECIPIENT_ID(1),
		TRANSACTION_ID(0),
		INSTRUMENT(2),
		QUANTITY(3),
		PRICE(4),
		REQUEST(5),
		RESPONSE(6),
		CHECKSUM(7);

		static Key						findById(int id)
		{
			for (Key key : Key.values())
			{
				if (key.getId() == id)
					return key;
			}

			throw new RuntimeException("Unknown key with id " + id);
		}

		private final int				id;

		Key(int id)
		{
			this.id = id;
		}

		int								getId()
		{
			return id;
		}
	}

	public enum							Request
	{
		INIT("init"),
		INFO("info"),
		BUY("buy"),
		SELL("sell");

		private final String			code;

										Request(String code)
		{
			this.code = code;
		}

		public String					toCode()
		{
			return code;
		}

		public static Request			fromCode(String code)
		{
			for (Request request : Request.values())
			{
				if (request.code.equals(code))
					return request;
			}

			throw new RuntimeException("Unknown code");
		}
	}

	static final String					DELIMITER = ",";

	private final Map<Key, FixField>	fields;

	@Override
	public String						toString()
	{
		return "[Message:'" + FixMessageEncoder.encode(this) + "']";
	}

	public 								FixMessage()
	{
		fields = new HashMap<>();
	}

	public 								FixMessage(FixMessage other)
	{
		this();

		for (Key key : other.fields.keySet())
			this.copyField(key, other);
	}

	public void							setField(Key key, String value)
	{
		getField(key).setValue(value);
	}

	public void							setField(Key key, int value)
	{
		getField(key).setValue(Integer.toString(value));
	}

	public String						getFieldAsString(Key key)
	{
		return getField(key).getValue();
	}

	public Integer						getFieldAsInt(Key key)
	{
		final String					fieldAsString = getField(key).getValue();

		return fieldAsString != null ? Integer.parseInt(fieldAsString) : null;
	}

	public void							copyField(Key key, FixMessage source)
	{
		setField(key, source.getFieldAsString(key));
	}

	private FixField					getField(Key key)
	{
		if (!fields.containsKey(key))
			fields.put(key, new FixField(key));

		return fields.get(key);
	}

	public boolean						isValid()
	{
		int								checksum;
		FixMessage						copyWithoutChecksum;

		checksum = getFieldAsInt(Key.CHECKSUM);

		copyWithoutChecksum = new FixMessage(this);
		copyWithoutChecksum.setField(Key.CHECKSUM, null);

		return computeChecksum(copyWithoutChecksum.concatAllFields()) == checksum;
	}

	static int							computeChecksum(String string)
	{
		int								sum = 0;

		for (char symbol : string.toCharArray())
			sum += symbol;

		return Math.abs(sum) / 256;
	}

	String								concatAllFields()
	{
		StringBuilder					stringBuilder;
		boolean							isFirst;

		stringBuilder = new StringBuilder();
		isFirst = true;

		for (FixField field : fields.values())
		{
			if (!isFirst)
				stringBuilder.append(DELIMITER);
			else
				isFirst = false;

			if (field.getValue() != null)
				stringBuilder.append(FixField.encode(field));
		}

		return stringBuilder.toString();
	}
}
