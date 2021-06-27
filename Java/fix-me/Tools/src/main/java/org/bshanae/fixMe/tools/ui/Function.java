package org.bshanae.fixMe.tools.ui;

import lombok.Getter;

public class						Function
{
	public interface				Implementation
	{
		void						execute(Argument[] arguments);
	}

	public static class				Argument
	{
		private final String		string;

		public 						Argument(String string)
		{
			this.string = string;
		}

		public String				asString()
		{
			return string;
		}

		public int					asInt()
		{
			return Integer.parseInt(string);
		}
	}

	private final Implementation	implementation;

	@Getter
	private final String[]			prefix;

	public 							Function(Implementation implementation, String ...prefix)
	{
		this.implementation = implementation;
		this.prefix = prefix;
	}

	public void						invoke(Argument[] arguments)
	{
		implementation.execute(arguments);
	}
}
