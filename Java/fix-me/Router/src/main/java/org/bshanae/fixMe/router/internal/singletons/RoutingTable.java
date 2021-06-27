package org.bshanae.fixMe.router.internal.singletons;

import java.net.SocketAddress;
import java.util.HashMap;
import java.util.Map;

public class									RoutingTable
{
	private static RoutingTable					instance;

	public static RoutingTable					getInstance()
	{
		if (instance == null)
			instance = new RoutingTable();

		return instance;
	}

	private final Map<Integer, SocketAddress>	idsAndAddresses;
	private int									nextId;

	private										RoutingTable()
	{
		idsAndAddresses = new HashMap<>();
		nextId = 0;
	}

	public SocketAddress						find(int id)
	{
		return idsAndAddresses.get(id);
	}

	public int									register(SocketAddress address)
	{
		Integer									id;

		id = tryFindExistingId(address);
		if (id != null)
			return id;

		id = registerNewId(address);
		return id;
	}

	private Integer								tryFindExistingId(SocketAddress address)
	{
		for (Map.Entry<Integer, SocketAddress> entry : idsAndAddresses.entrySet())
		{
			if (entry.getValue().equals(address))
				return entry.getKey();
		}

		return null;
	}

	private int									registerNewId(SocketAddress address)
	{
		int										newId;

		newId = nextId++;
		idsAndAddresses.put(newId, address);
		return newId;
	}
}