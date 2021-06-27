package org.bshanae.fixMe.tools.marketing.fixMessage;

import org.bshanae.fixMe.tools.system.network.Pocket;

public class				FixMessageEncoder
{
	public static Pocket	encode(FixMessage message)
	{
		String				content;
		String				contentWithoutChecksum;

		// Delete checksum if we have it
		message.setField(FixMessage.Key.CHECKSUM, null);
		contentWithoutChecksum = message.concatAllFields();

		message.setField(FixMessage.Key.CHECKSUM, Integer.toString(FixMessage.computeChecksum(contentWithoutChecksum)));
		content = message.concatAllFields();

		return new Pocket(content);
	}
}
