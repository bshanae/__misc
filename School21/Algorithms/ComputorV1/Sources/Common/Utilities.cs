using System;
using System.Reflection;

public static class		Utilities
{
	public static T		GetStaticProperty<T>(Type classType, string propertyName)
	{
		PropertyInfo	propertyInfo;
		object			propertyObject;

		if ((propertyInfo = classType.GetProperty(propertyName)) == null)
			throw new Exception($"[Utilities] Can't get property of class {classType}");
			
		if ((propertyObject = propertyInfo.GetValue(null, null)) == null)
			throw new Exception($"[Utilities] Can't get value of property for class {classType}");
			
		if (!(propertyObject is T))
			throw new Exception($"[Utilities] Can't cast property to target type");

		return (T)propertyObject;
	}
}
