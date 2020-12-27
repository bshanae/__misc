package model.closed.managers.generators;

public class					RandomGenerator
{
	public enum					Function
	{
		LINEAR,
		SINE;
	}

	public static float			random()
	{
		return random(Function.LINEAR);
	}

	public static float			random(Function function)
	{
		float					linearRandom;

		linearRandom = (float)Math.random();
		switch (function)
		{
			case SINE:
				return randomBetween(Function.LINEAR, 0.f, (float)Math.PI / 2.f);

			default:
				return linearRandom;
		}
	}

	public static float			randomBetween(float min, float max)
	{
		return (random() * max - min) + min;
	}

	public static int			randomBetween(int min, int max)
	{
		return (int)(random() * max - min) + min;
	}

	public static float			randomBetween(Function function, float min, float max)
	{
		return (random(function) * max - min) + min;
	}

	public static int			randomBetween(Function function, int min, int max)
	{
		return (int)(random(function) * max - min) + min;
	}
}
