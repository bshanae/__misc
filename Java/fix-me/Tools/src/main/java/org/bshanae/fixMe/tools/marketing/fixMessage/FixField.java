package org.bshanae.fixMe.tools.marketing.fixMessage;

import lombok.Getter;
import lombok.Setter;

public class						FixField
{
	@Getter
	private final FixMessage.Key	key;

	@Getter @Setter
	private String					value;

									FixField(FixMessage.Key key)
	{
		this.key = key;
	}

									FixField(FixMessage.Key key, String value)
	{
		this.key = key;
		this.value = value;
	}

	static String					encode(FixField field)
	{
		return field.getKey().getId() + "=" + field.getValue();
	}

	static FixField					decode(String encoded)
	{
		String[]					pieces;

		pieces = encoded.split("=");
		if (pieces.length != 2)
			throw new RuntimeException("Invalid encoded field '" + encoded + "'");

		return new FixField(FixMessage.Key.findById(Integer.parseInt(pieces[0])), pieces[1]);
	}
}
