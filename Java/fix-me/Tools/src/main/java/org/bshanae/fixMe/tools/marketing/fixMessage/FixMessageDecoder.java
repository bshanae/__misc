package org.bshanae.fixMe.tools.marketing.fixMessage;

import org.bshanae.fixMe.tools.system.network.Pocket;

public class					FixMessageDecoder
{
	public static FixMessage	decode(Pocket pocket)
	{
		String[]				fields;
		FixField				field;
		FixMessage				message;

		fields = pocket.getString().split(FixMessage.DELIMITER);
		message = new FixMessage();

		for (String encodedField : fields)
		{
			field = FixField.decode(encodedField);
			message.setField(field.getKey(), field.getValue());
		}

		return message;
	}
}
