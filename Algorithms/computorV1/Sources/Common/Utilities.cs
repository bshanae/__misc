using System;
using System.Collections;
using System.Reflection;
using Computor;

public static class		Utilities
{
	public static T		GetStaticProperty<T>(Type classType, string propertyName)
	{
		PropertyInfo	propertyInfo;
		object			propertyObject;

		propertyInfo = classType.GetProperty(propertyName);
		Error.Assert(propertyInfo != null);

		propertyObject = propertyInfo.GetValue(null, null);
		Error.Assert(propertyObject != null);

		Error.Assert(propertyObject is T);

		return (T)propertyObject;
	}

	public static void	ValidateIndex(this ICollection container, int index)
	{
		Error.Assert(index >= 0);
		Error.Assert(index < container.Count);
	}
}
