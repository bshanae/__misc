using System;
using UnityEngine;

public static class Vector2Tools
{
	public static float GetLenght(Vector2 v)
	{
		return Mathf.Sqrt(v.x * v.x + v.y * v.y);
	}

	public static Vector2 Normalize(Vector2 v)
	{
		var length = GetLenght(v);
		if (length == 0)
			throw new ArithmeticException();

		return v / length;
	}

	public static float Dot(Vector2 v1, Vector2 v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	public static Vector2 Reflect(Vector2 v, Vector2 n)
	{
		return v - 2 * Dot(v, n) * n;
	}
}