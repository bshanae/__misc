using System.Collections.Generic;

namespace						Computor
{
	public static class			Extensions
	{
		public static T			ExtractAt<T>(this List<T> list, int index)
		{
			T					item = list[index];
			
			list.RemoveAt(index);
			return item;
		}

		public static string	ToStandardString(this float value)
		{
			return System.Math.Round(value, 10).ToString();
		}
	}
}