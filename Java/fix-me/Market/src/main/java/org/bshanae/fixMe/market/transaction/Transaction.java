package org.bshanae.fixMe.market.transaction;

import lombok.Getter;
import lombok.Setter;

public class					Transaction
{
	@Getter @Setter
	private int					id;

	@Getter @Setter
	private String				action;

	@Getter @Setter
	private String				instrument;

	@Getter @Setter
	private int					price;

	@Getter @Setter
	private int					quantity;

	public 						Transaction()
	{}

	@Override
	public String				toString()
	{
		return String.format
		(
			"[transaction : id=%d, action=%s, instrument=%s, price=%d, quantity=%d",
			id,
			action,
			instrument,
			price,
			quantity
		);
	}
}
