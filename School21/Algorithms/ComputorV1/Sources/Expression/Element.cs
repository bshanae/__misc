
using System;

public static partial class		Expression
{
	public abstract class		Element : ICloneable
	{
		public abstract object	Clone();
	}
}