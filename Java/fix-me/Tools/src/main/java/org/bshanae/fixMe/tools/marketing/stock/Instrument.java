package org.bshanae.fixMe.tools.marketing.stock;

import lombok.Getter;
import lombok.Setter;

public class				Instrument
{
	@Getter
	private final String	name;

	@Getter @Setter
	private int				quantity;

	@Getter @Setter
	private int				price;

	public					Instrument(String name)
	{
		this.name = name;
	}

	public String			getDescription()
	{
		return name + " : quantity = " + quantity + ", price = " + price;
	}
}
