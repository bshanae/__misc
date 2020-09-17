using System;
using System.Collections.Generic;
using System.Linq;

public static class				ListExstension
{
    public static IList<T>		Clone<T>(this IList<T> listToClone) where T: ICloneable
    {
        return listToClone.Select(item => (T)item.Clone()).ToList();
    }
}
