package org.bshanae.fixMe.tools.marketing.stock;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class                                Stock
{
	private final Map<String, Instrument>   instruments;

	public                                  Stock()
	{
		instruments = new HashMap<>();
	}

	public Instrument                       get(String name)
	{
		return instruments.get(name);
	}

	public Collection<Instrument>			getAll()
	{
		return instruments.values();
	}

	public Instrument						getOrPut(String name)
	{
		if (!instruments.containsKey(name))
			instruments.put(name, new Instrument(name));

		return instruments.get(name);
	}

	public void								put(Instrument instrument)
	{
		instruments.put(instrument.getName(), instrument);
	}
}
