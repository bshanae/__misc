package org.bshanae.fixMe.tools.system.network;

import lombok.Getter;

import java.net.SocketAddress;

public class				Pocket
{
	@Getter
	private String			string;

	@Getter
	private SocketAddress	address;

	public					Pocket(String string)
	{
		this.string = string;
		this.address = null;
	}

	public					Pocket(String string, SocketAddress address)
	{
		this.string = string;
		this.address = address;
	}

	@Override
	public String			toString()
	{
		return string != null ? string : "null";
	}
}