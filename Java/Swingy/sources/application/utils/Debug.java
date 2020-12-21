package application.utils;

import application.ApplicationDefines;

public abstract class		Debug
{
	public static void		log(String message)
	{
		if (ApplicationDefines.get(ApplicationDefines.Define.DEBUG))
			System.out.println(message);
	}
}
