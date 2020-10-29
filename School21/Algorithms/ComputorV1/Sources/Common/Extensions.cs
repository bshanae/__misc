using System.Collections.Generic;

namespace						Computor
{
	public static class			Extensions
	{
		public static ValyeType	GetValue<KeyType, ValyeType>
		(
			this IDictionary<KeyType, ValyeType> dictionary,
			KeyType key, ValyeType defaultValue = default(ValyeType)
		)
		{
		    ValyeType			value;
			
		    return dictionary.TryGetValue(key, out value) ? value : defaultValue;
		}
	}
}